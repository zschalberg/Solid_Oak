#ifndef GUARD_RESEARCH_TURNIN_H
#define GUARD_RESEARCH_TURNIN_H

bool8 IsSelectedMonResearchBall(void);
bool8 IsSelectedMonNewFamily(void);
bool32 IsSpeciesFamilyReserved(enum Species species);
void EvaluateSelectedResearchMon(void);
void TurnInSelectedResearchMon(void);
void TransferSelectedMonToPokeBall(void);

#endif // GUARD_RESEARCH_TURNIN_H
