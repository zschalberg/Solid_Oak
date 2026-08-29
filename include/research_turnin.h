#ifndef GUARD_RESEARCH_TURNIN_H
#define GUARD_RESEARCH_TURNIN_H

bool8 IsSelectedMonResearchBall(void);
bool8 IsSelectedMonNewFamily(void);
bool32 IsSpeciesFamilyReserved(enum Species species);
void EvaluateSelectedResearchMon(void);
void TurnInSelectedResearchMon(void);
void TransferSelectedMonToPokeBall(void);
bool8 CheckReserveStageJustAdvanced(void);
u16 GetBaseRarityPoints(u8 catchRate);
u16 GetSizeBonusForTier(u8 tier);
u16 ApplyShinyBonus(u16 points, bool8 isShiny);
u16 CalculateResearchMonCoins(struct Pokemon *mon);

#endif // GUARD_RESEARCH_TURNIN_H
