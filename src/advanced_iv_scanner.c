#include "global.h"
#include "advanced_iv_scanner.h"
#include "event_data.h"
#include "field_player_avatar.h"
#include "field_specials.h"
#include "fieldmap.h"
#include "itemfinder.h"
#include "menu.h"
#include "script.h"
#include "sound.h"
#include "strings.h"
#include "task.h"
#include "metatile_behavior.h"
#include "event_object_lock.h"
#include "field_effect.h"
#include "constants/event_bg.h"
#include "constants/field_effects.h"
#include "constants/songs.h"
#include "constants/region_map_sections.h"
#include "random.h"
#include "item_use.h"

// EWRAM Globals
bool8 gIsAdvIvScannerEncounter = FALSE;

// Static Hotspot State
static s16 sHotspotX;
static s16 sHotspotY;
static u8 sHotspotMapGroup;
static u8 sHotspotMapNum;
static bool8 sHotspotActive;
static u8 sHotspotFldEffSpriteId;

// Task register maps
#define tDingTimer          data[0]
#define tNumDingsRemaining  data[1]
#define tDingNum            data[2]

// Text
static const u8 sText_NothingToScanHereGrass[] = _("There are no signs of POKéMON\nin the tall grass nearby.");
static const u8 sText_NothingToScanHereWater[] = _("There are no signs of POKéMON\nin the water nearby.");

// Declarations
void ItemUseOnFieldCB_AdvancedIVScanner(u8 taskId);
static void Task_AdvancedIVScannerResponseSoundsAndAnims(u8 taskId);
static void Task_AdvancedIVScannerCleanUp(u8 taskId);
static void Task_AdvancedIVScannerNoResponseCleanUp(u8 taskId);

struct MapTile {
    s16 x;
    s16 y;
};

// Callback when item use on field is set up
void ItemUseOnFieldCB_AdvancedIVScanner(u8 taskId)
{
    s16 playerX, playerY;
    s16 dx, dy;
    u32 candidateCount = 0;
    static struct MapTile sCandidates[165]; // ±7/±5 grid is 15x11 = 165 max tiles
    bool8 isSurfing = TestPlayerAvatarState(PLAYER_AVATAR_STATE_SURFING);

    PlayerGetDestCoords(&playerX, &playerY);

    for (dy = -5; dy <= 5; dy++)
    {
        for (dx = -7; dx <= 7; dx++)
        {
            if (dx == 0 && dy == 0)
                continue;

            s16 tileX = playerX + dx;
            s16 tileY = playerY + dy;

            u8 behavior = MapGridGetMetatileBehaviorAt(tileX, tileY);
            bool8 isValidTile = FALSE;

            if (isSurfing)
                isValidTile = MetatileBehavior_IsSurfable(behavior);
            else
                isValidTile = MetatileBehavior_IsTallGrass(behavior) || MetatileBehavior_IsLongGrass(behavior);

            if (isValidTile)
            {
                if (!MapGridGetCollisionAt(tileX, tileY))
                {
                    sCandidates[candidateCount].x = tileX;
                    sCandidates[candidateCount].y = tileY;
                    candidateCount++;
                }
            }
        }
    }

    if (candidateCount == 0)
    {
        // Fail with message
        const u8 *message = isSurfing ? sText_NothingToScanHereWater : sText_NothingToScanHereGrass;
        DisplayItemMessageOnField(taskId, FONT_NORMAL, message, Task_AdvancedIVScannerNoResponseCleanUp);
    }
    else
    {
        // Pick one candidate randomly
        u32 index = Random() % candidateCount;
        sHotspotX = sCandidates[index].x;
        sHotspotY = sCandidates[index].y;
        sHotspotMapGroup = gSaveBlock1Ptr->location.mapGroup;
        sHotspotMapNum = gSaveBlock1Ptr->location.mapNum;
        sHotspotActive = TRUE;
        sHotspotFldEffSpriteId = MAX_SPRITES;

        // Remember the active route
        gSaveBlock3Ptr->advIvScannerRoute = gMapHeader.regionMapSectionId;

        // Calculate initial distance to configure beep count
        s16 dist = abs(sHotspotX - playerX) + abs(sHotspotY - playerY);

        gTasks[taskId].tDingTimer = 0;
        gTasks[taskId].tDingNum = 0;
        gTasks[taskId].tNumDingsRemaining = (dist > 3) ? 2 : 4;

        LoadArrowAndStarTiles();
        gTasks[taskId].func = Task_AdvancedIVScannerResponseSoundsAndAnims;
    }
}

// Visual beeps and arrow task
static void Task_AdvancedIVScannerResponseSoundsAndAnims(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    
    if (tDingTimer % 25 == 0)
    {
        s16 playerX, playerY;
        PlayerGetDestCoords(&playerX, &playerY);
        
        s16 dx = sHotspotX - playerX;
        s16 dy = sHotspotY - playerY;
        enum Direction direction = GetPlayerDirectionTowardsHiddenItem(dx, dy);

        if (tNumDingsRemaining == 0)
        {
            gTasks[taskId].func = Task_AdvancedIVScannerCleanUp;
            return;
        }
        else
        {
            PlaySE(SE_DEX_SEARCH);
            CreateArrowSprite(tDingNum, direction);
            tDingNum++;
            tNumDingsRemaining--;
        }
    }
    tDingTimer++;
}

// Clean up after successful scan
static void Task_AdvancedIVScannerCleanUp(u8 taskId)
{
    DestroyArrowAndStarTiles();
    UnlockPlayerFieldControls();
    ScriptUnfreezeObjectEvents();
    DestroyTask(taskId);
}

// Clean up after failed scan (no grass)
static void Task_AdvancedIVScannerNoResponseCleanUp(u8 taskId)
{
    ClearDialogWindowAndFrame(0, TRUE);
    UnlockPlayerFieldControls();
    ScriptUnfreezeObjectEvents();
    DestroyTask(taskId);
}

// Get the field effect ID matching the hotspot tile's behavior
static u8 GetHotspotFieldEffectId(s16 x, s16 y)
{
    u8 behavior = MapGridGetMetatileBehaviorAt(x, y);
    if (MetatileBehavior_IsLongGrass(behavior))
        return FLDEFF_SHAKING_LONG_GRASS;
    if (MetatileBehavior_IsSurfable(behavior))
        return FLDEFF_UNUSED_WATER_SURFACING;
    return FLDEFF_SHAKING_GRASS;
}

// Overworld step check for grass shakes (returns FALSE so standard wild checks run)
bool32 OnStep_AdvancedIVScanner(void)
{
    if (!sHotspotActive)
        return FALSE;

    // Safety check: clear if map changed
    if (sHotspotMapGroup != gSaveBlock1Ptr->location.mapGroup || sHotspotMapNum != gSaveBlock1Ptr->location.mapNum)
    {
        ClearAdvancedIVScannerHotspot();
        return FALSE;
    }

    s16 playerX, playerY;
    PlayerGetDestCoords(&playerX, &playerY);

    s16 dx = sHotspotX - playerX;
    s16 dy = sHotspotY - playerY;
    u16 dist = abs(dx) + abs(dy);

    if (dist <= 3)
    {
        if (sHotspotFldEffSpriteId == MAX_SPRITES)
        {
            gFieldEffectArguments[0] = sHotspotX;
            gFieldEffectArguments[1] = sHotspotY;
            gFieldEffectArguments[2] = 0xFF; // subpriority
            gFieldEffectArguments[3] = 2;    // priority
            sHotspotFldEffSpriteId = FieldEffectStart(GetHotspotFieldEffectId(sHotspotX, sHotspotY));
        }
    }
    else
    {
        if (sHotspotFldEffSpriteId != MAX_SPRITES)
        {
            FieldEffectStop(&gSprites[sHotspotFldEffSpriteId], GetHotspotFieldEffectId(sHotspotX, sHotspotY));
            sHotspotFldEffSpriteId = MAX_SPRITES;
        }
    }

    return FALSE;
}

// Check if player is standing on the active hotspot
bool8 IsPlayerOnActiveHotspot(void)
{
    if (!sHotspotActive)
        return FALSE;

    if (sHotspotMapGroup != gSaveBlock1Ptr->location.mapGroup || sHotspotMapNum != gSaveBlock1Ptr->location.mapNum)
        return FALSE;

    s16 playerX, playerY;
    PlayerGetDestCoords(&playerX, &playerY);

    return (playerX == sHotspotX && playerY == sHotspotY);
}

// Set N guaranteed perfect stats to 31
void ApplyAdvancedIVScannerIVs(struct Pokemon *mon)
{
    u8 iv[3] = {NUM_STATS, NUM_STATS, NUM_STATS};
    u8 perfectIv = 31;
    u8 count = 1;

    if (gSaveBlock3Ptr->advIvScannerChain >= 6)
        count = 3;
    else if (gSaveBlock3Ptr->advIvScannerChain >= 3)
        count = 2;

    iv[0] = Random() % NUM_STATS; // 1st perfect stat
    do {
        iv[1] = Random() % NUM_STATS;
        iv[2] = Random() % NUM_STATS;
    } while ((iv[1] == iv[0])
      || (iv[2] == iv[0] || iv[2] == iv[1])); // unique stats

    if (count > 2 && iv[2] != NUM_STATS)
        SetMonData(mon, MON_DATA_HP_IV + iv[2], &perfectIv);
    if (count > 1 && iv[1] != NUM_STATS)
        SetMonData(mon, MON_DATA_HP_IV + iv[1], &perfectIv);
    if (count > 0 && iv[0] != NUM_STATS)
        SetMonData(mon, MON_DATA_HP_IV + iv[0], &perfectIv);

    CalculateMonStats(mon);
}

// Clear visual effects and set active = FALSE
void ResolveAdvancedIVScannerHotspot(bool8 success)
{
    // sHotspotFldEffSpriteId defaults to 0 (a real sprite slot, the player's)
    // until a scan actually runs and sets it to the MAX_SPRITES sentinel, so
    // this must also check sHotspotActive or it can stop an arbitrary sprite
    // (including the player's) on the first map load/transition of a session.
    if (sHotspotActive && sHotspotFldEffSpriteId != MAX_SPRITES)
    {
        FieldEffectStop(&gSprites[sHotspotFldEffSpriteId], GetHotspotFieldEffectId(sHotspotX, sHotspotY));
        sHotspotFldEffSpriteId = MAX_SPRITES;
    }
    sHotspotActive = FALSE;
}

void ClearAdvancedIVScannerHotspot(void)
{
    ResolveAdvancedIVScannerHotspot(FALSE);
}

// Map change: clear hotspot. Break chain if map section changed.
void ResetAdvancedIVScannerSearch(void)
{
    ClearAdvancedIVScannerHotspot();

    if (gSaveBlock3Ptr->advIvScannerRoute != MAPSEC_NONE &&
        gSaveBlock3Ptr->advIvScannerRoute != gMapHeader.regionMapSectionId)
    {
        gSaveBlock3Ptr->advIvScannerChain = 0;
        gSaveBlock3Ptr->advIvScannerRoute = MAPSEC_NONE;
    }
}

// Calculate shiny rolls: 2 * min(chain, 10) rolls
u32 CalculateAdvIvScannerShinyRolls(void)
{
    if (!gIsAdvIvScannerEncounter)
        return 0;

    return 2 * min(gSaveBlock3Ptr->advIvScannerChain, 10);
}
