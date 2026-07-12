#ifndef GUARD_FUJI_LAB_H
#define GUARD_FUJI_LAB_H

extern u8 gFujiRoomMonNames[6][20];
extern bool8 gCourierStorageChanged;

void FujiLab_InitRoomObjects(void);
void FujiLab_GetPokemonInfo(void);
void FujiLab_Withdraw(void);
void FujiLab_Deposit(void);
void FujiLab_Swap(void);
void SpawnCourierBird(void);
void RemoveCourierBird(void);
void FujiLab_BufferRoomMons(void);
void FujiLab_IsSlotEmpty(void);

void FujiLab_ResetStorageChangeFlag(void);
bool8 FujiLab_DidStorageChange(void);

#endif // GUARD_FUJI_LAB_H
