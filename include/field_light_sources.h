#ifndef GUARD_FIELD_LIGHT_SOURCES_H
#define GUARD_FIELD_LIGHT_SOURCES_H

#include "global.h"

enum MapLightSourceType
{
    LIGHT_TYPE_STATIC,
    LIGHT_TYPE_FLAME,
    LIGHT_TYPE_FLASHLIGHT,
    LIGHT_TYPE_FIREFLIES,
    LIGHT_TYPE_BUGS,
    LIGHT_TYPE_AUTUMN_LEAVES,
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
    LIGHT_ANIM_ROTATION,
};

struct MapLightSource
{
    u8 mapGroup;
    u8 mapNum;
    s16 x;
    s16 y;
    u8 type;
    u8 shape;
    u8 colorTint;
    u8 trackingLocalId; // 0 for fixed map coords, or NPC localId to track
    u16 flagId; // If non-zero, light is only active when FlagGet(flagId) is TRUE
};

void InitMapLightSources(void);
void DestroyMapLightSources(void);
void UpdateMapLightSourcesVisibility(bool8 visible);
void Special_UpdateMapLightSources(void);
void ActivateTrainerLight(struct ObjectEvent *trainerObj);

#endif // GUARD_FIELD_LIGHT_SOURCES_H
