#ifndef GUARD_POKEMON_SIZE_RECORD_H
#define GUARD_POKEMON_SIZE_RECORD_H

#include "global.h"

void InitSeedotSizeRecord(void);
void GetSeedotSizeRecordInfo(void);
void CompareSeedotSize(void);

void InitLotadSizeRecord(void);
void GetLotadSizeRecordInfo(void);
void CompareLotadSize(void);

void InitHeracrossSizeRecord(void);
void InitMagikarpSizeRecord(void);
void GiveGiftRibbonToParty(u8 index, u8 ribbonId);

enum SizeRecordResult
{
    SIZE_RECORD_NONE     = 0,
    SIZE_RECORD_TALLEST  = (1 << 0),
    SIZE_RECORD_SHORTEST = (1 << 1),
    SIZE_RECORD_HEAVIEST = (1 << 2),
    SIZE_RECORD_LIGHTEST = (1 << 3),
};

u8 UpdatePokedexSizeRecord(struct Pokemon *mon);
u8 UpdatePokedexSizeRecordBySpeciesPersonality(u16 species, u32 personality);
u8 GetPokedexHeightRecord(u16 species, bool8 isTallest);
u8 GetPokedexWeightRecord(u16 species, bool8 isHeaviest);
u32 GetPokedexSizeMultiplier(u8 category);
u8 TranslateBigMonSizeTableIndex(u16 a);
u8 GetPersonalitySizeTier(u32 personality);
void SetMonSizeTierOrPercentile(struct Pokemon *mon, u16 heightVal, u16 weightVal);

#endif // GUARD_POKEMON_SIZE_RECORD_H

