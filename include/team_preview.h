#ifndef GUARD_TEAM_PREVIEW_H
#define GUARD_TEAM_PREVIEW_H

#include "global.h"

void ShowOpponentTeamPreview(u16 trainerId, MainCallback callback);

struct Pokemon;
struct Pokemon *GetPreviewPlayerParty(void);
u8 GetPreviewPlayerPartyCount(void);

extern u8 gSelectCount;
extern u8 gOpponentSelectCount;
extern bool8 gIsPreviewChooseMons;

#endif // GUARD_TEAM_PREVIEW_H
