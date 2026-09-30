#ifndef GUARD_CONSTANTS_SPEAKER_NAMES_H
#define GUARD_CONSTANTS_SPEAKER_NAMES_H

// Preset names for the `setspeaker` script macro. Any value below
// SP_NAME_COUNT is looked up in gSpeakerNamesTable; anything else is
// treated as a pointer to a string.
#define SP_NAME_NONE        0
#define SP_NAME_PLAYER      1   // Uses the player's chosen name
#define SP_NAME_AGATHA      2
#define SP_NAME_MR_FUJI     3
#define SP_NAME_PROF_ARBOR  4
#define SP_NAME_SAMUEL      5

#define SP_NAME_COUNT       6

#endif // GUARD_CONSTANTS_SPEAKER_NAMES_H
