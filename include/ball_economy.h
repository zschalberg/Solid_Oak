#ifndef GUARD_BALL_ECONOMY_H
#define GUARD_BALL_ECONOMY_H

#include "pokemon.h"

// Sentinel returned by GetBallLevelCap for ball types with no level cap
// (Research Ball, standard Poke Ball, and anything else post-jump).
#define BALL_CAP_NONE 0xFF

// PLACEHOLDERS pending design/balancing pass - not finalized:
#define RELEASE_COIN_REWARD 50           // Research Coins awarded for "tag and release".
#define FRIENDSHIP_DANGER_THRESHOLD 30    // Out of 255. An over-cap mon only risks disobedience below this ("hates you") - no risk at all above it.
#define MAX_DISOBEDIENCE_CHANCE_PERCENT 25 // Disobedience chance at friendship 0; ramps linearly to 0% at FRIENDSHIP_DANGER_THRESHOLD.
#define BREAKOUT_CHANCE_PERCENT 10        // Chance (per failed-obedience roll at friendship == 0) that the mon breaks out for good.

// Breakout (permanent flee) is disabled for now: reviving/interacting with a
// "pending departure" mon mid-battle raised design questions that haven't
// been resolved yet (see conversation), and the friendship system is meant
// to matter, not be bypassable. Flip this back on once that's designed -
// everything downstream (CancelerObedience, BattleScript_MonBreaksFree,
// FreeMonBall on breakout) is still intact and ready to go.
#define BREAKOUT_ENABLED FALSE

// Result codes for the Workbench "Upgrade Ball" specials.
#define UPGRADE_RESULT_SUCCESS 0
#define UPGRADE_RESULT_NOT_UPGRADEABLE 1 // Not a Protoball, ball not owned, or already max tier (Black).
#define UPGRADE_RESULT_NEED_APRICORN 2

u8 GetBallLevelCap(u16 ballItem);
u8 GetOriginalBallLevelCap(struct Pokemon *mon);
bool8 IsReusableBallItem(u16 ballItem);
u16 GetMonBallItem(struct Pokemon *mon);
u16 GetBoxMonBallItem(struct BoxPokemon *boxMon);
bool8 CanFreeMonBall(struct Pokemon *mon);
bool8 CanFreeBoxMonBall(struct BoxPokemon *boxMon);
bool8 FreeMonBall(struct Pokemon *mon);
bool8 FreeBoxMonBall(struct BoxPokemon *boxMon);
u16 GetClaimableBallItem(u16 requiredBall);
bool8 TryClaimMonBall(struct Pokemon *mon);
bool8 TryClaimBoxMonBall(struct BoxPokemon *boxMon);
void MarkMonBallOccupied(struct Pokemon *mon);
void GrantBallsOfType(u16 ballItem, u8 quantity);
void GrantQuestBalls(void);
u16 GetNextProtoBallTier(u16 ballItem);
u16 GetApricornForBallTier(u16 ballItem);

// Workbench "Upgrade Ball" script specials.
u8 GetSelectedMonUpgradeInfo(void);
u8 UpgradeSelectedMonBall(void);
u8 TryUpgradeBagBallTier(void);

#endif // GUARD_BALL_ECONOMY_H
