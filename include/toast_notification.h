#ifndef GUARD_TOAST_NOTIFICATION_H
#define GUARD_TOAST_NOTIFICATION_H

#include "global.h"

enum ToastType
{
    TOAST_QUEST_START = 0,
    TOAST_QUEST_UPDATE,
    TOAST_QUEST_COMPLETE,
    TOAST_CUSTOM
};

void ShowQuestToast(u8 toastType, const u8 *questName);
void ShowCustomToast(const u8 *headerText, const u8 *messageText, u16 sfx, u8 headerColorIndex);
void HideToastNotification(void);
bool32 IsToastNotificationActive(void);
void FlushToastQueue(void);

#endif // GUARD_TOAST_NOTIFICATION_H
