#include "global.h"
#include "achievement_notifications.h"
#include "event_data.h"
#include "pokedex.h"
#include "sound.h"
#include "string_util.h"
#include "toast_notification.h"
#include "constants/flags.h"
#include "constants/songs.h"

static const u8 sHeader_Achievement[]   = _("ACHIEVEMENT UNLOCKED!");
static const u8 sMsg_Caught10Species[]  = _("Caught 10 Species");

void CheckAndUnlockCatchAchievements(void)
{
    u16 caughtCount = GetNationalPokedexCount(FLAG_GET_CAUGHT);

    if (caughtCount >= 10 && !FlagGet(FLAG_ACHIEVEMENT_CAUGHT_10_SPECIES))
    {
        FlagSet(FLAG_ACHIEVEMENT_CAUGHT_10_SPECIES);
        ShowCustomToast(sHeader_Achievement, sMsg_Caught10Species, SE_SUCCESS, 0);
    }
}
