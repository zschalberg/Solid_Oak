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
    u8 slotId = gSpecialVar_0x8006; // slot was copied from VAR_0x800D into VAR_0x8006 by the script
    struct BoxPokemon *boxMon = GetBoxedMonPtr(boxId, slotId);
    if (GetBoxMonData(boxMon, MON_DATA_SPECIES) == SPECIES_NONE)
        gSpecialVar_Result = TRUE;
    else
        gSpecialVar_Result = FALSE;
}

struct CourierCart
{
    u8 partySlotsToDeposit[PARTY_SIZE];
    u8 depositCount;
    u8 roomBoxIdsToWithdraw[PARTY_SIZE];
    u8 roomSlotIdsToWithdraw[PARTY_SIZE];
    u8 withdrawCount;
};

static struct CourierCart sCourierCart;

void Courier_ClearCart(void)
{
    memset(&sCourierCart, 0, sizeof(sCourierCart));
}

void Courier_StageDeposit(void)
{
    u8 slot = gSpecialVar_0x8004;
    u8 i;
    s32 finalCount;

    if (slot >= CalculatePlayerPartyCount())
    {
        gSpecialVar_Result = 2; // Invalid slot
        return;
    }

    // Check if already staged
    for (i = 0; i < sCourierCart.depositCount; i++)
    {
        if (sCourierCart.partySlotsToDeposit[i] == slot)
        {
            gSpecialVar_Result = 1; // Already staged
            return;
        }
    }

    // Check if would leave party empty
    finalCount = (s32)CalculatePlayerPartyCount() - (sCourierCart.depositCount + 1) + sCourierCart.withdrawCount;
    if (finalCount < 1)
    {
        gSpecialVar_Result = 3; // Cannot have empty party
        return;
    }

    if (sCourierCart.depositCount >= PARTY_SIZE)
    {
        gSpecialVar_Result = 4; // Cart full
        return;
    }

    sCourierCart.partySlotsToDeposit[sCourierCart.depositCount++] = slot;
    gSpecialVar_Result = 0; // Success
}

void Courier_StageWithdraw(void)
{
    u8 boxId = gSpecialVar_0x8004;
    u8 slotId = gSpecialVar_0x8006;
    u8 i;
    s32 finalCount;

    // Check if already staged
    for (i = 0; i < sCourierCart.withdrawCount; i++)
    {
        if (sCourierCart.roomBoxIdsToWithdraw[i] == boxId && sCourierCart.roomSlotIdsToWithdraw[i] == slotId)
        {
            gSpecialVar_Result = 1; // Already staged
            return;
        }
    }

    // Check if would exceed party size
    finalCount = (s32)CalculatePlayerPartyCount() - sCourierCart.depositCount + (sCourierCart.withdrawCount + 1);
    if (finalCount > PARTY_SIZE)
    {
        gSpecialVar_Result = 2; // Would exceed party size
        return;
    }

    if (sCourierCart.withdrawCount >= PARTY_SIZE)
    {
        gSpecialVar_Result = 4; // Cart full
        return;
    }

    sCourierCart.roomBoxIdsToWithdraw[sCourierCart.withdrawCount] = boxId;
    sCourierCart.roomSlotIdsToWithdraw[sCourierCart.withdrawCount] = slotId;
    sCourierCart.withdrawCount++;
    gSpecialVar_Result = 0; // Success
}

u16 Courier_GetCartSummary(void)
{
    u8 roomsCount = GetFujiLabRoomsCount();
    u8 roomCapacity = GetBoxCapacityLimit();
    s32 boxNo, boxPos;
    s32 totalEmptySlots = 0;
    s32 finalCount;

    if (sCourierCart.depositCount == 0 && sCourierCart.withdrawCount == 0)
    {
        return 4; // Cart empty
    }

    finalCount = (s32)CalculatePlayerPartyCount() - sCourierCart.depositCount + sCourierCart.withdrawCount;
    if (finalCount < 1)
    {
        return 1; // Party empty
    }
    if (finalCount > PARTY_SIZE)
    {
        return 2; // Party too large
    }

    // Count empty box slots
    for (boxNo = 0; boxNo < roomsCount; boxNo++)
    {
        for (boxPos = 0; boxPos < roomCapacity; boxPos++)
        {
            struct BoxPokemon *destMon = GetBoxedMonPtr(boxNo, boxPos);
            if (GetBoxMonData(destMon, MON_DATA_SPECIES) == SPECIES_NONE)
            {
                totalEmptySlots++;
            }
        }
    }

    // Add empty slots that will be created by withdrawals
    if (sCourierCart.depositCount > totalEmptySlots + sCourierCart.withdrawCount)
    {
        return 3; // Sanctuary full
    }

    return 0; // Valid
}

void Courier_BufferCartString(void)
{
    u8 i;
    u8 temp[50];
    
    gStringVar1[0] = EOS;
    gStringVar2[0] = EOS;

    // Buffer deposits count and names
    ConvertIntToDecimalStringN(temp, sCourierCart.depositCount, STR_CONV_MODE_LEFT_ALIGN, 1);
    StringCopy(gStringVar1, temp);
    StringAppend(gStringVar1, COMPOUND_STRING(" Mon(s): "));
    
    for (i = 0; i < sCourierCart.depositCount; i++)
    {
        u8 slot = sCourierCart.partySlotsToDeposit[i];
        GetMonData(&gPlayerParty[slot], MON_DATA_NICKNAME, gStringVar3);
        if (i > 0)
            StringAppend(gStringVar1, COMPOUND_STRING(", "));
        StringAppend(gStringVar1, gStringVar3);
    }
    if (sCourierCart.depositCount == 0)
        StringAppend(gStringVar1, COMPOUND_STRING("None"));

    // Buffer retrieves count and names
    ConvertIntToDecimalStringN(temp, sCourierCart.withdrawCount, STR_CONV_MODE_LEFT_ALIGN, 1);
    StringCopy(gStringVar2, temp);
    StringAppend(gStringVar2, COMPOUND_STRING(" Mon(s): "));
    
    for (i = 0; i < sCourierCart.withdrawCount; i++)
    {
        u8 boxId = sCourierCart.roomBoxIdsToWithdraw[i];
        u8 slotId = sCourierCart.roomSlotIdsToWithdraw[i];
        struct BoxPokemon *boxMon = GetBoxedMonPtr(boxId, slotId);
        GetBoxMonData(boxMon, MON_DATA_NICKNAME, gStringVar3);
        if (i > 0)
            StringAppend(gStringVar2, COMPOUND_STRING(", "));
        StringAppend(gStringVar2, gStringVar3);
    }
    if (sCourierCart.withdrawCount == 0)
        StringAppend(gStringVar2, COMPOUND_STRING("None"));
}

void Courier_ExecuteCart(void)
{
    struct Pokemon tempWithdrawMons[PARTY_SIZE];
    u8 i, j;
    s32 boxNo, boxPos;
    u8 roomsCount = GetFujiLabRoomsCount();
    u8 roomCapacity = GetBoxCapacityLimit();

    // 1. Copy boxed mons to temp array and clear box slots
    for (i = 0; i < sCourierCart.withdrawCount; i++)
    {
        u8 boxId = sCourierCart.roomBoxIdsToWithdraw[i];
        u8 slotId = sCourierCart.roomSlotIdsToWithdraw[i];
        struct BoxPokemon *boxMon = GetBoxedMonPtr(boxId, slotId);
        BoxMonToMon(boxMon, &tempWithdrawMons[i]);
        ZeroBoxMonData(boxMon);
    }

    // 2. Copy staged deposits to empty box slots and clear party slots
    for (i = 0; i < sCourierCart.depositCount; i++)
    {
        u8 partySlot = sCourierCart.partySlotsToDeposit[i];
        struct Pokemon *partyMon = &gPlayerParty[partySlot];
        bool8 deposited = FALSE;

        for (boxNo = 0; boxNo < roomsCount && !deposited; boxNo++)
        {
            for (boxPos = 0; boxPos < roomCapacity; boxPos++)
            {
                struct BoxPokemon *destMon = GetBoxedMonPtr(boxNo, boxPos);
                if (GetBoxMonData(destMon, MON_DATA_SPECIES) == SPECIES_NONE)
                {
                    *destMon = partyMon->box;
                    ZeroMonData(partyMon);
                    deposited = TRUE;
                    break;
                }
            }
        }
    }

    // 3. Copy withdrawn mons to empty party slots
    for (i = 0; i < sCourierCart.withdrawCount; i++)
    {
        for (j = 0; j < PARTY_SIZE; j++)
        {
            if (GetMonData(&gPlayerParty[j], MON_DATA_SPECIES) == SPECIES_NONE)
            {
                gPlayerParty[j] = tempWithdrawMons[i];
                break;
            }
        }
    }

    // 4. Compact party and update follower
    CompactPartySlots();
    CalculatePlayerPartyCount();
    UpdateFollowingPokemon();

    // 5. Clear cart
    Courier_ClearCart();
}

void Courier_BufferSingleWithdrawName(void)
{
    u8 boxId = gSpecialVar_0x8004;
    u8 slotId = gSpecialVar_0x8006;
    struct BoxPokemon *boxMon = GetBoxedMonPtr(boxId, slotId);
    GetBoxMonData(boxMon, MON_DATA_NICKNAME, gStringVar1);
}
