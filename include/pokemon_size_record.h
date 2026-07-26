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

void UpdatePokedexSizeRecord(struct Pokemon *mon);
void UpdatePokedexSizeRecordBySpeciesPersonality(u16 species, u32 personality);
u8 GetPokedexHeightRecord(u16 species, bool8 isTallest);
u8 GetPokedexWeightRecord(u16 species, bool8 isHeaviest);
u32 GetPokedexSizeMultiplier(u8 category);
u8 TranslateBigMonSizeTableIndex(u16 a);
u8 GetPersonalitySizeTier(u32 personality);

#endif // GUARD_POKEMON_SIZE_RECORD_H
