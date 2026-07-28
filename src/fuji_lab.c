#include "global.h"
#include "event_data.h"
#include "pokemon.h"
#include "pokemon_storage_system.h"
#include "event_object_movement.h"
#include "field_specials.h"
#include "script.h"
#include "string_util.h"
#include "fieldmap.h"
#include "constants/event_objects.h"
#include "constants/flags.h"
#include "constants/vars.h"
#include "constants/characters.h"
#include "fuji_lab.h"
#include "ball_economy.h"

u8 gFujiRoomMonNames[6][20];

u8 GetCurrentFujiRoomBoxId(void)
{
    if (gSaveBlock1Ptr->location.mapGroup == 8)
    {
        u8 mapNum = gSaveBlock1Ptr->location.mapNum;
        if (mapNum >= 7 && mapNum <= 16)
        {
            return mapNum - 7;
        }
    }
    return gSpecialVar_0x8004;
}

void FujiLab_InitRoomObjects(void)
{
    u8 boxId = GetCurrentFujiRoomBoxId();
    u8 roomCapacity = GetBoxCapacityLimit();
    u8 i;

    for (i = 0; i < roomCapacity; i++)
    {
        struct BoxPokemon *boxMon = GetBoxedMonPtr(boxId, i);
        u16 species = GetBoxMonData(boxMon, MON_DATA_SPECIES);

        if (species != SPECIES_NONE && species != SPECIES_EGG)
        {
            u16 gfxId = species + OBJ_EVENT_MON;
            if (GetBoxMonData(boxMon, MON_DATA_IS_SHINY))
                gfxId += OBJ_EVENT_MON_SHINY;
            if (GetBoxMonGender(boxMon) == MON_FEMALE)
                gfxId += OBJ_EVENT_MON_FEMALE;

            VarSet(VAR_OBJ_GFX_ID_0 + i, gfxId);
            FlagClear(FLAG_TEMP_1 + i);

            // For testing: make them not move (set movement type to MOVEMENT_TYPE_FACE_DOWN)
            gSaveBlock1Ptr->objectEventTemplates[i].movementType = MOVEMENT_TYPE_FACE_DOWN;

            // Also update active object if it exists
            u8 objectEventId;
            if (!TryGetObjectEventIdByLocalIdAndMap(i + 1, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup, &objectEventId))
            {
                gObjectEvents[objectEventId].movementType = MOVEMENT_TYPE_FACE_DOWN;
                ObjectEventSetGraphicsId(&gObjectEvents[objectEventId], gfxId);
            }
        }
        else
        {
            VarSet(VAR_OBJ_GFX_ID_0 + i, 0);
            FlagSet(FLAG_TEMP_1 + i);
        }
    }
}

void FujiLab_GetPokemonInfo(void)
{
    u8 boxId = GetCurrentFujiRoomBoxId();
    u8 slotId = gSpecialVar_LastTalked - 1;
    struct BoxPokemon *boxMon = GetBoxedMonPtr(boxId, slotId);
    u16 species = GetBoxMonData(boxMon, MON_DATA_SPECIES);

    GetBoxMonData(boxMon, MON_DATA_NICKNAME, gStringVar1);
    StringCopy(gStringVar2, GetSpeciesName(species));
}

void FujiLab_Withdraw(void)
{
    u8 boxId = GetCurrentFujiRoomBoxId();
    u8 slotId = gSpecialVar_0x8006;
    struct BoxPokemon *boxMon = GetBoxedMonPtr(boxId, slotId);
    u8 partyCount = CalculatePlayerPartyCount();

    if (partyCount < PARTY_SIZE)
    {
        BoxMonToMon(boxMon, &gPlayerParty[partyCount]);
        ZeroBoxMonData(boxMon);
        CompactPartySlots();
        CalculatePlayerPartyCount();
        UpdateFollowingPokemon();
        gSpecialVar_Result = TRUE;
    }
    else
    {
        gSpecialVar_Result = FALSE;
    }
}


void FujiLab_Deposit(void)
{
    u8 partySlot = gSpecialVar_0x8004;
    u8 targetBox = gSpecialVar_0x8005; // 0-9, or 0xFF for automatic
    u8 roomsCount = GetFujiLabRoomsCount();
    u8 roomCapacity = GetBoxCapacityLimit();
    s32 boxNo, boxPos;

    if (partySlot >= CalculatePlayerPartyCount())
    {
        gSpecialVar_Result = FALSE;
        return;
    }

    if (targetBox != 0xFF)
    {
        if (targetBox < roomsCount)
        {
            for (boxPos = 0; boxPos < roomCapacity; boxPos++)
            {
                struct BoxPokemon *destMon = GetBoxedMonPtr(targetBox, boxPos);
                if (GetBoxMonData(destMon, MON_DATA_SPECIES) == SPECIES_NONE)
                {
                    struct Pokemon *partyMon = &gPlayerParty[partySlot];
                    FreeMonBall(partyMon); // Ball economy: sending to storage frees the ball.
                    *destMon = partyMon->box;
                    ZeroMonData(partyMon);
                    CompactPartySlots();
                    CalculatePlayerPartyCount();
                    UpdateFollowingPokemon();
                    gSpecialVar_Result = TRUE;
                    return;
                }
            }
        }
        gSpecialVar_Result = FALSE;
    }
    else
    {
        for (boxNo = 0; boxNo < roomsCount; boxNo++)
        {
            for (boxPos = 0; boxPos < roomCapacity; boxPos++)
            {
                struct BoxPokemon *destMon = GetBoxedMonPtr(boxNo, boxPos);
                if (GetBoxMonData(destMon, MON_DATA_SPECIES) == SPECIES_NONE)
                {
                    struct Pokemon *partyMon = &gPlayerParty[partySlot];
                    FreeMonBall(partyMon); // Ball economy: sending to storage frees the ball.
                    *destMon = partyMon->box;
                    ZeroMonData(partyMon);
                    CompactPartySlots();
                    CalculatePlayerPartyCount();
                    UpdateFollowingPokemon();
                    gSpecialVar_Result = TRUE;
                    return;
                }
            }
        }
        gSpecialVar_Result = FALSE;
    }
}

void FujiLab_Swap(void)
{
    u8 partySlot = gSpecialVar_0x8004;
    u8 boxId = GetCurrentFujiRoomBoxId();
    u8 slotId = gSpecialVar_0x8006;
    struct BoxPokemon *boxMon = GetBoxedMonPtr(boxId, slotId);
    struct Pokemon *partyMon = &gPlayerParty[partySlot];
    struct Pokemon tempPartyMon = *partyMon;

    FreeMonBall(&tempPartyMon); // Ball economy: the swapped-out party mon frees its ball.
    BoxMonToMon(boxMon, partyMon);
    *boxMon = tempPartyMon.box;
    UpdateFollowingPokemon();
    gSpecialVar_Result = TRUE;
}

void SpawnCourierBird(void)
{
    s16 x = gSaveBlock1Ptr->pos.x + MAP_OFFSET;
    s16 y = gSaveBlock1Ptr->pos.y + MAP_OFFSET;
    
    SpawnSpecialObjectEventParameterized(OBJ_EVENT_GFX_PIDGEOT, MOVEMENT_TYPE_FACE_DOWN, 0x1F, x, y - 5, 3);
}

void RemoveCourierBird(void)
{
    RemoveObjectEventByLocalIdAndMap(0x1F, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup);
}

void FujiLab_BufferRoomMons(void)
{
    u8 boxId = gSpecialVar_0x8004;
    u8 roomCapacity = GetBoxCapacityLimit();
    u8 i;

    for (i = 0; i < 6; i++)
    {
        if (i < roomCapacity)
        {
            struct BoxPokemon *boxMon = GetBoxedMonPtr(boxId, i);
            u16 species = GetBoxMonData(boxMon, MON_DATA_SPECIES);
            if (species != SPECIES_NONE && species != SPECIES_EGG)
            {
                GetBoxMonData(boxMon, MON_DATA_NICKNAME, gFujiRoomMonNames[i]);
            }
            else
            {
                StringCopy(gFujiRoomMonNames[i], COMPOUND_STRING("---"));
            }
        }
        else
        {
            StringCopy(gFujiRoomMonNames[i], COMPOUND_STRING("---"));
        }
    }
}

void FujiLab_IsSlotEmpty(void)
{
    u8 boxId = gSpecialVar_0x8004;
    u8 slotId = gSpecialVar_0x8006; // slot was copied from VAR_RESULT into VAR_0x8006 by the script
    struct BoxPokemon *boxMon = GetBoxedMonPtr(boxId, slotId);
    if (GetBoxMonData(boxMon, MON_DATA_SPECIES) == SPECIES_NONE)
        gSpecialVar_Result = TRUE;
    else
        gSpecialVar_Result = FALSE;
}



void FujiLab_ResetStorageChangeFlag(void)
{
    gCourierStorageChanged = FALSE;
}

bool8 FujiLab_DidStorageChange(void)
{
    return gCourierStorageChanged;
}
