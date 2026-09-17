#ifndef GUARD_FIELD_LIGHT_SOURCES_H
#define GUARD_FIELD_LIGHT_SOURCES_H

#include "global.h"

enum MapLightSourceType
{
    LIGHT_TYPE_STATIC, // Unused. Reserved for a non-animated circle light.
                       // Keep at index 0 -- the table's default/zero value.
    LIGHT_TYPE_FLAME,
    LIGHT_TYPE_FLASHLIGHT,
    LIGHT_TYPE_FIREFLIES,
    LIGHT_TYPE_BUGS,
    LIGHT_TYPE_AUTUMN_LEAVES,
    LIGHT_TYPE_FLYING_PIDGEY,
    LIGHT_TYPE_TREE_PIDGEY,
    LIGHT_TYPE_MAGIKARP_SPLASH,
    LIGHT_TYPE_WINGULL_SKIM,
    LIGHT_TYPE_GASTLY_SPOOK,
};

enum MapLightShape
{
    LIGHT_SHAPE_CIRCLE,
    LIGHT_SHAPE_CONE,
    LIGHT_SHAPE_FIREFLIES,
};

enum MapLightColorTint
{
    LIGHT_COLOR_NONE,
    LIGHT_COLOR_AMBER,
    LIGHT_COLOR_BUGS_GRAY,
};

enum MapLightSourceAnim
{
    LIGHT_ANIM_STATIC,
    LIGHT_ANIM_FLAME_100,
    LIGHT_ANIM_FLAME_50,
    LIGHT_ANIM_FLAME_150,
    LIGHT_ANIM_ROTATION, // Unused. Reserved for a rotating affine anim; there
                         // is no matching entry in sAffineAnims_LightCircle,
                         // so adding one requires a new AffineAnimCmd there.
};

struct MapLightSource
{
    u8 mapGroup;
    u8 mapNum;
    s16 x;
    s16 y;
    u8 type;
    u8 shape;     // Currently unread -- every code path dispatches on `type`.
                  // Kept so entries stay self-documenting; wire it up if a
                  // single type ever needs more than one silhouette.
    u8 colorTint; // Currently unread -- the palette is picked by `type` via
                  // the sprite template. Same rationale as `shape`.
    u8 trackingLocalId; // 0 for fixed map coords, or NPC localId to track
    u16 flagId; // If non-zero, light is only active when FlagGet(flagId) is TRUE
};

void InitMapLightSources(void);
void DestroyMapLightSources(void);
void ActivateTrainerLight(struct ObjectEvent *trainerObj);
void OnMapConnectionTransition(u8 mapGroup, u8 mapNum);

// Currently unused -- definitions are commented out in src/field_light_sources.c
// with notes on what they do and what still needs wiring before re-enabling.
// void UpdateMapLightSourcesVisibility(bool8 visible);
// void Special_UpdateMapLightSources(void);

#endif // GUARD_FIELD_LIGHT_SOURCES_H
