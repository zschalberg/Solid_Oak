#include "global.h"
#include "event_data.h"
#include "pokedex.h"
#include "field_message_box.h"
#include "pokemon.h"
#include "pokemon_storage_system.h"
#include "string_util.h"
#include "constants/characters.h"

extern const u8 PokedexRating_Text_LessThan10[];
extern const u8 PokedexRating_Text_LessThan20[];
extern const u8 PokedexRating_Text_LessThan30[];
extern const u8 PokedexRating_Text_LessThan40[];
extern const u8 PokedexRating_Text_LessThan50[];
extern const u8 PokedexRating_Text_LessThan60[];
extern const u8 PokedexRating_Text_LessThan70[];
extern const u8 PokedexRating_Text_LessThan80[];
extern const u8 PokedexRating_Text_LessThan90[];
extern const u8 PokedexRating_Text_LessThan100[];
extern const u8 PokedexRating_Text_LessThan110[];
extern const u8 PokedexRating_Text_LessThan120[];
extern const u8 PokedexRating_Text_LessThan130[];
extern const u8 PokedexRating_Text_LessThan140[];
extern const u8 PokedexRating_Text_LessThan150[];
extern const u8 PokedexRating_Text_Complete[];

u16 GetPokedexCount(void)
{
    if (gSpecialVar_0x8004 == 0)
    {
        gSpecialVar_0x8005 = GetKantoPokedexCount(0);
        gSpecialVar_0x8006 = GetKantoPokedexCount(1);
    }
    else
    {
        gSpecialVar_0x8005 = GetNationalPokedexCount(0);
        gSpecialVar_0x8006 = GetNationalPokedexCount(1);
    }
    return IsNationalPokedexEnabled();
}

static const u8 *GetProfOaksRatingMessageByCount(u16 count)
{
    gSpecialVar_Result = FALSE;
    
    if (count > 0 && GetSetPokedexFlag(NATIONAL_DEX_MEW, FLAG_GET_CAUGHT))
        count--;

    if (count < 10)
        return PokedexRating_Text_LessThan10;

    if (count < 20)
        return PokedexRating_Text_LessThan20;

    if (count < 30)
        return PokedexRating_Text_LessThan30;

    if (count < 40)
        return PokedexRating_Text_LessThan40;

    if (count < 50)
        return PokedexRating_Text_LessThan50;

    if (count < 60)
        return PokedexRating_Text_LessThan60;

    if (count < 70)
        return PokedexRating_Text_LessThan70;

    if (count < 80)
        return PokedexRating_Text_LessThan80;

    if (count < 90)
        return PokedexRating_Text_LessThan90;

    if (count < 100)
        return PokedexRating_Text_LessThan100;

    if (count < 110)
        return PokedexRating_Text_LessThan110;

    if (count < 120)
        return PokedexRating_Text_LessThan120;

    if (count < 130)
        return PokedexRating_Text_LessThan130;

    if (count < 140)
        return PokedexRating_Text_LessThan140;

    if (count < KANTO_DEX_COUNT - 1)
        return PokedexRating_Text_LessThan150;

    gSpecialVar_Result = TRUE;
    return PokedexRating_Text_Complete;
}

void GetProfOaksRatingMessage(void)
{
    ShowFieldMessage(GetProfOaksRatingMessageByCount(gSpecialVar_0x8004));
}

u16 GetSpeciesSeenCount(void)
{
    u16 species = gSpecialVar_0x8004;
    u32 seen = GET_DEX_SEEN_COUNT(species);
    
    if (seen == 0 && GetSetPokedexFlag(SpeciesToNationalPokedexNum(species), FLAG_GET_SEEN))
        seen = 1;
        
    gSpecialVar_Result = seen;
    return seen;
}

u16 GetSpeciesCaughtCount(void)
{
    u16 species = gSpecialVar_0x8004;
    u32 caught = GET_DEX_CAUGHT_COUNT(species);
    
    if (caught == 0 && GetSetPokedexFlag(SpeciesToNationalPokedexNum(species), FLAG_GET_CAUGHT))
        caught = 1;
        
    gSpecialVar_Result = caught;
    return caught;
}

u16 GetMonHeight(void)
{
    u8 partySlot = gSpecialVar_0x8004;
    if (partySlot < PARTY_SIZE)
    {
        struct Pokemon *mon = &gPlayerParty[partySlot];
        u16 species = GetMonData(mon, MON_DATA_SPECIES, NULL);
        if (species != SPECIES_NONE && !GetMonData(mon, MON_DATA_IS_EGG, NULL))
        {
            u32 personality = GetMonData(mon, MON_DATA_PERSONALITY, NULL);
            u32 height = GetIndividualHeight(species, personality);
            gSpecialVar_Result = height;
            return height;
        }
    }
    gSpecialVar_Result = 0;
    return 0;
}

u16 GetMonWeight(void)
{
    u8 partySlot = gSpecialVar_0x8004;
    if (partySlot < PARTY_SIZE)
    {
        struct Pokemon *mon = &gPlayerParty[partySlot];
        u16 species = GetMonData(mon, MON_DATA_SPECIES, NULL);
        if (species != SPECIES_NONE && !GetMonData(mon, MON_DATA_IS_EGG, NULL))
        {
            u32 personality = GetMonData(mon, MON_DATA_PERSONALITY, NULL);
            u32 weight = GetIndividualWeight(species, personality);
            gSpecialVar_Result = weight;
            return weight;
        }
    }
    gSpecialVar_Result = 0;
    return 0;
}

u16 GetMonHeightPercentile(void)
{
    u8 partySlot = gSpecialVar_0x8004;
    if (partySlot < PARTY_SIZE)
    {
        struct Pokemon *mon = &gPlayerParty[partySlot];
        u16 species = GetMonData(mon, MON_DATA_SPECIES, NULL);
        if (species != SPECIES_NONE && !GetMonData(mon, MON_DATA_IS_EGG, NULL))
        {
            u32 personality = GetMonData(mon, MON_DATA_PERSONALITY, NULL);
            u16 percentile = ((personality & 0xFFFF) * 1000) / 65535;
            gSpecialVar_Result = percentile;
            return percentile;
        }
    }
    gSpecialVar_Result = 0;
    return 0;
}

u16 GetMonWeightPercentile(void)
{
    u8 partySlot = gSpecialVar_0x8004;
    if (partySlot < PARTY_SIZE)
    {
        struct Pokemon *mon = &gPlayerParty[partySlot];
        u16 species = GetMonData(mon, MON_DATA_SPECIES, NULL);
        if (species != SPECIES_NONE && !GetMonData(mon, MON_DATA_IS_EGG, NULL))
        {
            u32 personality = GetMonData(mon, MON_DATA_PERSONALITY, NULL);
            u16 percentile = (((personality >> 16) & 0xFFFF) * 1000) / 65535;
            gSpecialVar_Result = percentile;
            return percentile;
        }
    }
    gSpecialVar_Result = 0;
    return 0;
}

void RemoveSelectedPartyMon(void)
{
    u8 partySlot = gSpecialVar_0x8004;
    u8 partyCount = CalculatePlayerPartyCount();
    
    if (partySlot < PARTY_SIZE && partyCount > 1)
    {
        struct Pokemon *mon = &gPlayerParty[partySlot];
        u16 species = GetMonData(mon, MON_DATA_SPECIES, NULL);
        
        if (species != SPECIES_NONE)
        {
            // If it is a non-egg, verify we have another non-egg left in the party
            if (species != SPECIES_EGG)
            {
                u8 usableCount = 0;
                u8 i;
                for (i = 0; i < PARTY_SIZE; i++)
                {
                    u16 s = GetMonData(&gPlayerParty[i], MON_DATA_SPECIES, NULL);
                    if (s != SPECIES_NONE && s != SPECIES_EGG)
                        usableCount++;
                }
                
                if (usableCount <= 1)
                {
                    gSpecialVar_Result = FALSE; // Cannot remove last usable pokemon
                    return;
                }
            }
            
            ZeroMonData(mon);
            CompactPartySlots();
            CalculatePlayerPartyCount();
            gSpecialVar_Result = TRUE;
            return;
        }
    }
    gSpecialVar_Result = FALSE;
}

void BufferMonPercentiles(void)
{
    u8 partySlot = gSpecialVar_0x8004;
    if (partySlot < PARTY_SIZE)
    {
        struct Pokemon *mon = &gPlayerParty[partySlot];
        u16 species = GetMonData(mon, MON_DATA_SPECIES, NULL);
        if (species != SPECIES_NONE && !GetMonData(mon, MON_DATA_IS_EGG, NULL))
        {
            u32 personality = GetMonData(mon, MON_DATA_PERSONALITY, NULL);
            u32 heightPercentileVal = ((personality & 0xFFFF) * 1000) / 65535;
            u32 weightPercentileVal = (((personality >> 16) & 0xFFFF) * 1000) / 65535;
            u8 *ptr;
            
            ptr = ConvertIntToDecimalStringN(gStringVar2, heightPercentileVal / 10, STR_CONV_MODE_LEFT_ALIGN, 3);
            ptr[0] = CHAR_PERIOD;
            ptr++;
            ConvertIntToDecimalStringN(ptr, heightPercentileVal % 10, STR_CONV_MODE_LEFT_ALIGN, 1);
            
            ptr = ConvertIntToDecimalStringN(gStringVar3, weightPercentileVal / 10, STR_CONV_MODE_LEFT_ALIGN, 3);
            ptr[0] = CHAR_PERIOD;
            ptr++;
            ConvertIntToDecimalStringN(ptr, weightPercentileVal % 10, STR_CONV_MODE_LEFT_ALIGN, 1);
            return;
        }
    }
    gStringVar2[0] = EOS;
    gStringVar3[0] = EOS;
}

