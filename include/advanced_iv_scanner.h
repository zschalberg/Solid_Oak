#ifndef GUARD_ADVANCED_IV_SCANNER_H
#define GUARD_ADVANCED_IV_SCANNER_H

#include "global.h"

// Globals
extern bool8 gIsAdvIvScannerEncounter;

// Functions
void ItemUseOutOfBattle_AdvancedIVScanner(u8 taskId);
void ItemUseOnFieldCB_AdvancedIVScanner(u8 taskId);
bool8 IsPlayerOnActiveHotspot(void);
void ApplyAdvancedIVScannerIVs(struct Pokemon *mon);
void ResolveAdvancedIVScannerHotspot(bool8 success);
void ClearAdvancedIVScannerHotspot(void);
void ResetAdvancedIVScannerSearch(void);
u32 CalculateAdvIvScannerShinyRolls(void);
bool32 OnStep_AdvancedIVScanner(void);

#endif // GUARD_ADVANCED_IV_SCANNER_H
