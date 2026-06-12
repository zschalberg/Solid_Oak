#ifndef GUARD_FUJI_LAB_H
#define GUARD_FUJI_LAB_H

extern u8 gFujiRoomMonNames[6][20];

void FujiLab_InitRoomObjects(void);
void FujiLab_GetPokemonInfo(void);
void FujiLab_Withdraw(void);
void FujiLab_Deposit(void);
void FujiLab_Swap(void);
void SpawnCourierBird(void);
void RemoveCourierBird(void);
void FujiLab_BufferRoomMons(void);
void FujiLab_IsSlotEmpty(void);

void Courier_ClearCart(void);
void Courier_StageDeposit(void);
void Courier_StageWithdraw(void);
u16 Courier_GetCartSummary(void);
void Courier_BufferCartString(void);
void Courier_ExecuteCart(void);
void Courier_BufferSingleWithdrawName(void);

#endif // GUARD_FUJI_LAB_H
