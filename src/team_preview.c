#include "global.h"
#include "main.h"
#include "menu.h"
#include "gpu_regs.h"
#include "palette.h"
#include "pokemon.h"
#include "trainer_pokemon_sprites.h"
#include "sprite.h"
#include "sound.h"
#include "constants/songs.h"
#include "constants/rgb.h"
#include "malloc.h"
#include "decompress.h"
#include "data.h"
#include "party_menu.h"
#include "battle_setup.h"
#include "battle.h"
#include "event_data.h"
#include "constants/battle.h"
#include "team_preview.h"
#include "task.h"
#include "string_util.h"
#include "overworld.h"
#include "script.h"

struct TeamPreviewResources
{
    u16 trainerId;
    u16 spriteIds[6];
};

EWRAM_DATA u8 gSelectCount = 0;
EWRAM_DATA u8 gOpponentSelectCount = 0;
EWRAM_DATA bool8 gIsPreviewChooseMons = FALSE;

static EWRAM_DATA struct Pokemon sSavedPlayerParty[PARTY_SIZE] = {0};
static EWRAM_DATA u8 sSavedPlayerPartyCount = 0;
static EWRAM_DATA u8 sSelectedMonOriginalSlots[6] = {0};
static EWRAM_DATA MainCallback sOriginalBattleSavedCallback = NULL;
static EWRAM_DATA u8 sSelectedCount = 0;

static void Task_TeamPreviewWaitButton(u8 taskId);
static void CB2_StartBattleAfterChooseMons(void);
static void FieldCB_Start3v3Battle(void);
static void CB2_End3v3PreviewBattle(void);

void ShowOpponentTeamPreview(u16 trainerId, MainCallback callback)
{
    u8 taskId = CreateTask(Task_TeamPreviewWaitButton, 0);
    struct TeamPreviewResources *resources = (struct TeamPreviewResources *)&gTasks[taskId].data[0];
    const struct Trainer *trainer = GetTrainerStructFromId(trainerId);
    u32 i;
    
    gIsPreviewChooseMons = TRUE;
    
    resources->trainerId = trainerId;
    
    // Determine select count:
    // If gSpecialVar_0x8008 is set (1 to 6), use it.
    // Otherwise, default to 3 (or the trainer's pool size if it's smaller).
    u8 maxPoolSize = (trainer->poolSize != 0) ? trainer->poolSize : trainer->partySize;
    u8 selectCount = gSpecialVar_0x8008;
    if (selectCount == 0 || selectCount > 6)
    {
        selectCount = 3;
    }
    if (selectCount > maxPoolSize)
    {
        selectCount = maxPoolSize;
    }
    gSelectCount = selectCount;

    // Determine opponent select count:
    u8 opponentCount = gSpecialVar_0x800A;
    if (opponentCount == 0 || opponentCount > 6)
    {
        opponentCount = gSelectCount; // default: match player count (symmetric)
    }
    if (opponentCount > maxPoolSize)
    {
        opponentCount = maxPoolSize; // clamp to trainer's available pool
    }
    gOpponentSelectCount = opponentCount;
    
    for (i = 0; i < 6; i++)
    {
        resources->spriteIds[i] = 0xFFFF;
        if (i < maxPoolSize)
        {
            u16 species = trainer->party[i].species;
            bool32 isShiny = trainer->party[i].isShiny;
            u32 personality = 0;
            
            // Centers and distributes sprites cleanly with no overlap
            s16 x = 48 + (i % 3) * 72;
            s16 y = 35 + (i / 3) * 70; // Row 1: Y=35, Row 2: Y=105
            
            // OBJ palettes 10-15 to avoid conflict with standard overworld character palettes
            u16 spriteId = CreateMonFrontPicSprite(species, isShiny, personality, x, y, 10 + i, TAG_NONE);
            if (spriteId != 0xFFFF)
            {
                resources->spriteIds[i] = spriteId;
                gSprites[spriteId].oam.priority = 0;
            }
        }
    }
}

static void Task_TeamPreviewWaitButton(u8 taskId)
{
    struct TeamPreviewResources *resources = (struct TeamPreviewResources *)&gTasks[taskId].data[0];
    
    if (JOY_NEW(A_BUTTON))
    {
        u32 i;
        
        PlaySE(SE_SELECT);
        
        for (i = 0; i < 6; i++)
        {
            if (resources->spriteIds[i] != 0xFFFF)
            {
                FreeAndDestroyMonPicSprite(resources->spriteIds[i]);
            }
        }
        
        DestroyTask(taskId);
        
        gSpecialVar_0x8004 = FRONTIER_LVL_OPEN;
        gSpecialVar_0x8005 = gSelectCount; // Dynamically request gSelectCount selections
        
        gMain.savedCallback = CB2_StartBattleAfterChooseMons;
        InitChooseMonsForBattle(0);
    }
}

static void FieldCB_Start3v3Battle(void)
{
    BattleSetup_StartTrainerBattle();
    gBattleTypeFlags |= BATTLE_TYPE_PREVIEW;
    
    // Wrap the saved callback so we can restore the party at the end of the battle
    sOriginalBattleSavedCallback = gMain.savedCallback;
    gMain.savedCallback = CB2_End3v3PreviewBattle;
}

static void CB2_StartBattleAfterChooseMons(void)
{
    gIsPreviewChooseMons = FALSE;
    if (gSelectedOrderFromParty[0] == 0)
    {
        ScriptContext_Init();
        UnlockPlayerFieldControls();
        SetMainCallback2(CB2_ReturnToField);
        return;
    }
    
    // Calculate the actual number of Pokémon selected
    sSelectedCount = 0;
    while (sSelectedCount < gSelectCount && gSelectedOrderFromParty[sSelectedCount] != 0)
    {
        sSelectedCount++;
    }
    
    // 1. Save the original full party and count
    sSavedPlayerPartyCount = gPlayerPartyCount;
    u8 i;
    for (i = 0; i < PARTY_SIZE; i++)
    {
        CopyMon(&sSavedPlayerParty[i], &gPlayerParty[i], sizeof(struct Pokemon));
    }
    
    // 2. Save the original slots of selected Pokémon
    for (i = 0; i < sSelectedCount; i++)
    {
        sSelectedMonOriginalSlots[i] = gSelectedOrderFromParty[i] - 1;
    }
    
    // 3. Reorder party to place chosen Pokémon at indices 0 to sSelectedCount - 1
    struct Pokemon tempParty[6];
    for (i = 0; i < sSelectedCount; i++)
    {
        u8 slot = sSelectedMonOriginalSlots[i];
        CopyMon(&tempParty[i], &gPlayerParty[slot], sizeof(struct Pokemon));
    }
    
    for (i = 0; i < sSelectedCount; i++)
    {
        CopyMon(&gPlayerParty[i], &tempParty[i], sizeof(struct Pokemon));
    }
    
    // 4. Zero out remaining slots and set count to sSelectedCount
    for (i = sSelectedCount; i < PARTY_SIZE; i++)
    {
        ZeroMonData(&gPlayerParty[i]);
    }
    gPlayerPartyCount = sSelectedCount;
    
    // Set field callback to initiate battle once map re-renders
    gFieldCallback = FieldCB_Start3v3Battle;
    SetMainCallback2(CB2_ReturnToField);
}

static void CB2_End3v3PreviewBattle(void)
{
    // 1. Copy the updated Pokémon back to their original slots in sSavedPlayerParty
    u8 i;
    for (i = 0; i < sSelectedCount; i++)
    {
        u8 slot = sSelectedMonOriginalSlots[i];
        CopyMon(&sSavedPlayerParty[slot], &gPlayerParty[i], sizeof(struct Pokemon));
    }
    
    // 2. Restore gPlayerParty from sSavedPlayerParty
    for (i = 0; i < PARTY_SIZE; i++)
    {
        CopyMon(&gPlayerParty[i], &sSavedPlayerParty[i], sizeof(struct Pokemon));
    }
    
    // 3. Restore player party count
    gPlayerPartyCount = sSavedPlayerPartyCount;
    
    // 4. Clear preview battle flag
    gBattleTypeFlags &= ~BATTLE_TYPE_PREVIEW;
    
    gSelectCount = 0;
    gOpponentSelectCount = 0;
    sSelectedCount = 0;
    
    FlagClear(FLAG_MONOTYPE_BATTLE);
    VarSet(VAR_MONOTYPE_RESTRICTION, TYPE_NONE);
    
    // 5. Call the original battle end callback
    if (sOriginalBattleSavedCallback)
    {
        sOriginalBattleSavedCallback();
    }
}

struct Pokemon *GetPreviewPlayerParty(void)
{
    return sSavedPlayerParty;
}

u8 GetPreviewPlayerPartyCount(void)
{
    return sSavedPlayerPartyCount;
}
