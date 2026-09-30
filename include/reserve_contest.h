#ifndef GUARD_RESERVE_CONTEST_H
#define GUARD_RESERVE_CONTEST_H

// Research Balls loaned to the player for the duration of one contest
// session. Unused ones are reclaimed by EndReserveContestSession.
#define RESERVE_CONTEST_BALL_LOAN 30

void ResetReserveContestAttempts(void);
void EndReserveContestSession(void);
u8 GetReserveContestAttemptsRemaining(void);
bool8 CheckCanRegisterReserveContest(void);
void ValidateReserveContestChosenMon(void);
void SavePlayerPartyForReserveContest(void);
void RestorePlayerPartyFromReserveContest(void);
void StartReserveContestSession(void);
void GetReserveContestCatchNicknames(void);
void OpenReserveContestSpecimenSummary(void);
void ProcessReserveContestSpecimenChoice(void);
void EvaluateReserveContestCatch(void);
void FinalizeReserveContestCatch(void);

#endif // GUARD_RESERVE_CONTEST_H
