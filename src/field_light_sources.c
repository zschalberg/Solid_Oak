#include "global.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "field_light_sources.h"
#include "field_screen_effect.h"
#include "fieldmap.h"
#include "gpu_regs.h"
#include "overworld.h"
#include "random.h"
#include "sprite.h"
#include "trig.h"
#include "constants/field_effects.h"
#include "constants/flags.h"
#include "constants/maps.h"
#include "constants/global.h"
#include "constants/opponents.h"
#include "constants/vars.h"

#define MAX_MAP_LIGHTS 32
#define LIGHT_CONE_ANIM_GLOW 5

static const u16 sLightCircle_Pal[] = {
    RGB_BLACK, RGB_WHITE, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

static const u16 sFireflies_Pal[] = {
    RGB_BLACK,
    RGB(31, 22, 5),   // 1: warm amber
    RGB(31, 30, 20),  // 2: bright gold core
    RGB(26, 15, 2),   // 3: soft amber
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

static const u16 sBugs_Pal[] = {
    RGB_BLACK,
    RGB(3, 3, 3),     // 1: dark black body
    RGB(16, 16, 16),  // 2: medium-light gray wings
    RGB(8, 8, 8),     // 3: dark gray outline
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

static const u32 sLightCircle_Gfx[] = INCBIN_U32("graphics/field_effects/pics/light_circle.4bpp");
static const u32 sLightCone_Gfx[]   = INCBIN_U32("graphics/field_effects/pics/light_cone.4bpp");
static const u32 sFireflies_Gfx[]   = INCBIN_U32("graphics/field_effects/pics/fireflies.4bpp");

static const struct SpriteSheet sSpriteSheet_LightCircle = {
    .data = sLightCircle_Gfx,
    .size = 2048, // 64x64 4bpp
    .tag = FLDEFF_TILE_TAG_LIGHT_CIRCLE,
};

static const struct SpriteSheet sSpriteSheet_LightCone = {
    .data = sLightCone_Gfx,
    .size = 10240, // 64x320 4bpp (5 frames: Down, Up, Left, Right, Ambient Glow)
    .tag = FLDEFF_TILE_TAG_LIGHT_CONE,
};

static const struct SpriteSheet sSpriteSheet_Fireflies = {
    .data = sFireflies_Gfx,
    .size = 8192, // 16 frames of 32x32 4bpp (16 * 16 tiles * 32 bytes)
    .tag = FLDEFF_TILE_TAG_FIREFLIES,
};

static const struct SpritePalette sSpritePalette_LightCircle = {
    .data = sLightCircle_Pal,
    .tag = FLDEFF_PAL_TAG_LIGHT_CIRCLE,
};

static const struct SpritePalette sSpritePalette_Fireflies = {
    .data = sFireflies_Pal,
    .tag = FLDEFF_PAL_TAG_LIGHT_AMBER,
};

static const struct SpritePalette sSpritePalette_Bugs = {
    .data = sBugs_Pal,
    .tag = FLDEFF_PAL_TAG_LIGHT_BUGS,
};

static const u16 sAutumnLeaf_Pal[] = {
    RGB_BLACK,
    RGB(9, 4, 2),     // 1: dark russet outline
    RGB(21, 6, 3),    // 2: deep crimson
    RGB(28, 12, 2),   // 3: warm burnt orange
    RGB(30, 22, 5),   // 4: golden amber
    RGB(31, 28, 14),  // 5: bright yellow vein
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

static const u32 sAutumnLeaf_Gfx[] = INCBIN_U32("graphics/field_effects/pics/autumn_leaf.4bpp");

static const struct SpriteSheet sSpriteSheet_AutumnLeaf = {
    .data = sAutumnLeaf_Gfx,
    .size = 1024, // 16x128 4bpp (8 frames of 16x16)
    .tag = FLDEFF_TILE_TAG_AUTUMN_LEAF,
};

static const struct SpritePalette sSpritePalette_AutumnLeaf = {
    .data = sAutumnLeaf_Pal,
    .tag = FLDEFF_PAL_TAG_AUTUMN_LEAF,
};

// OAM Data for Monument Flame (uses double affine for 150% scaling)
static const struct OamData sOamData_LightCircle = {
    .y = 0,
    .affineMode = ST_OAM_AFFINE_DOUBLE,
    .objMode = ST_OAM_OBJ_WINDOW,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = ST_OAM_SQUARE,
    .x = 0,
    .matrixNum = 0,
    .size = ST_OAM_SIZE_3, // 64x64
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
};

// OAM Data for Flashlight Cone (pure non-affine window mask with directional frames)
static const struct OamData sOamData_LightCone = {
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_WINDOW,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = ST_OAM_SQUARE,
    .x = 0,
    .matrixNum = 0,
    .size = ST_OAM_SIZE_3, // 64x64
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
};

static const union AffineAnimCmd sAffineAnim_LightStatic[] = {
    AFFINEANIMCMD_FRAME(256, 256, 0, 0),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd sAffineAnim_LightPulse_100[] = {
    AFFINEANIMCMD_FRAME(256, 256, 0, 0),
    AFFINEANIMCMD_FRAME(1, 1, 0, 20),
    AFFINEANIMCMD_FRAME(-1, -1, 0, 20),
    AFFINEANIMCMD_FRAME(-1, -1, 0, 16),
    AFFINEANIMCMD_FRAME(1, 1, 0, 16),
    AFFINEANIMCMD_JUMP(1),
};

static const union AffineAnimCmd sAffineAnim_LightPulse_50[] = {
    AFFINEANIMCMD_FRAME(128, 128, 0, 0),
    AFFINEANIMCMD_FRAME(1, 1, 0, 10),
    AFFINEANIMCMD_FRAME(-1, -1, 0, 10),
    AFFINEANIMCMD_FRAME(-1, -1, 0, 8),
    AFFINEANIMCMD_FRAME(1, 1, 0, 8),
    AFFINEANIMCMD_JUMP(1),
};

static const union AffineAnimCmd sAffineAnim_LightPulse_150[] = {
    AFFINEANIMCMD_FRAME(384, 384, 0, 0),
    AFFINEANIMCMD_FRAME(2, 2, 0, 15),
    AFFINEANIMCMD_FRAME(-2, -2, 0, 15),
    AFFINEANIMCMD_FRAME(-2, -2, 0, 12),
    AFFINEANIMCMD_FRAME(2, 2, 0, 12),
    AFFINEANIMCMD_JUMP(1),
};

static const union AffineAnimCmd *const sAffineAnims_LightCircle[] = {
    [LIGHT_ANIM_STATIC]    = sAffineAnim_LightStatic,
    [LIGHT_ANIM_FLAME_100] = sAffineAnim_LightPulse_100,
    [LIGHT_ANIM_FLAME_50]  = sAffineAnim_LightPulse_50,
    [LIGHT_ANIM_FLAME_150] = sAffineAnim_LightPulse_150,
};

// Directional sprite animation commands for the flashlight cone
// Each 64x64 frame is 64 tiles in 4bpp
static const union AnimCmd sAnim_LightConeDown[] = {
    ANIMCMD_FRAME(0, 0),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_LightConeUp[] = {
    ANIMCMD_FRAME(64, 0),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_LightConeLeft[] = {
    ANIMCMD_FRAME(128, 0),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_LightConeRight[] = {
    ANIMCMD_FRAME(192, 0),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_LightConeGlow[] = {
    ANIMCMD_FRAME(256, 0),
    ANIMCMD_END,
};

static const union AnimCmd *const sAnims_LightCone[] = {
    [DIR_NONE]             = sAnim_LightConeDown,
    [DIR_SOUTH]            = sAnim_LightConeDown,
    [DIR_NORTH]            = sAnim_LightConeUp,
    [DIR_WEST]             = sAnim_LightConeLeft,
    [DIR_EAST]             = sAnim_LightConeRight,
    [LIGHT_CONE_ANIM_GLOW] = sAnim_LightConeGlow,
};

// OAM Data for Fireflies Window Mask (32x32)
static const struct OamData sOamData_Fireflies_Window = {
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_WINDOW,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = ST_OAM_SQUARE,
    .x = 0,
    .matrixNum = 0,
    .size = ST_OAM_SIZE_2, // 32x32
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
};

// OAM Data for Fireflies Color Sprite (32x32)
static const struct OamData sOamData_Fireflies_Color = {
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = ST_OAM_SQUARE,
    .x = 0,
    .matrixNum = 0,
    .size = ST_OAM_SIZE_2, // 32x32
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
};

// 16-frame looping animation for the 32x32 firefly swarm (16 tiles per frame)
static const union AnimCmd sAnim_Fireflies[] = {
    ANIMCMD_FRAME(0,   8),
    ANIMCMD_FRAME(16,  8),
    ANIMCMD_FRAME(32,  8),
    ANIMCMD_FRAME(48,  8),
    ANIMCMD_FRAME(64,  8),
    ANIMCMD_FRAME(80,  8),
    ANIMCMD_FRAME(96,  8),
    ANIMCMD_FRAME(112, 8),
    ANIMCMD_FRAME(128, 8),
    ANIMCMD_FRAME(144, 8),
    ANIMCMD_FRAME(160, 8),
    ANIMCMD_FRAME(176, 8),
    ANIMCMD_FRAME(192, 8),
    ANIMCMD_FRAME(208, 8),
    ANIMCMD_FRAME(224, 8),
    ANIMCMD_FRAME(240, 8),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd *const sAnims_Fireflies[] = {
    sAnim_Fireflies,
};

static void SpriteCallback_MapLightSource(struct Sprite *sprite);

static const struct SpriteTemplate sSpriteTemplate_LightCircle = {
    .tileTag = FLDEFF_TILE_TAG_LIGHT_CIRCLE,
    .paletteTag = FLDEFF_PAL_TAG_LIGHT_CIRCLE,
    .oam = &sOamData_LightCircle,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = sAffineAnims_LightCircle,
    .callback = SpriteCallback_MapLightSource,
};

static const struct SpriteTemplate sSpriteTemplate_LightCone = {
    .tileTag = FLDEFF_TILE_TAG_LIGHT_CONE,
    .paletteTag = FLDEFF_PAL_TAG_LIGHT_CIRCLE,
    .oam = &sOamData_LightCone,
    .anims = sAnims_LightCone,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallback_MapLightSource,
};

static const struct SpriteTemplate sSpriteTemplate_Fireflies_Window = {
    .tileTag = FLDEFF_TILE_TAG_FIREFLIES,
    .paletteTag = FLDEFF_PAL_TAG_LIGHT_CIRCLE,
    .oam = &sOamData_Fireflies_Window,
    .anims = sAnims_Fireflies,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallback_MapLightSource,
};

static const struct SpriteTemplate sSpriteTemplate_Fireflies_Color = {
    .tileTag = FLDEFF_TILE_TAG_FIREFLIES,
    .paletteTag = FLDEFF_PAL_TAG_LIGHT_AMBER,
    .oam = &sOamData_Fireflies_Color,
    .anims = sAnims_Fireflies,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallback_MapLightSource,
};

static const struct SpriteTemplate sSpriteTemplate_Bugs_Color = {
    .tileTag = FLDEFF_TILE_TAG_FIREFLIES,
    .paletteTag = FLDEFF_PAL_TAG_LIGHT_BUGS,
    .oam = &sOamData_Fireflies_Color,
    .anims = sAnims_Fireflies,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallback_MapLightSource,
};

static const struct OamData sOamData_AutumnLeaf = {
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = ST_OAM_SQUARE,
    .x = 0,
    .matrixNum = 0,
    .size = ST_OAM_SIZE_1, // 16x16
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
};

static const union AnimCmd sAnim_AutumnLeaf[] = {
    ANIMCMD_FRAME(0,  6),
    ANIMCMD_FRAME(4,  6),
    ANIMCMD_FRAME(8,  6),
    ANIMCMD_FRAME(12, 6),
    ANIMCMD_FRAME(16, 6),
    ANIMCMD_FRAME(20, 6),
    ANIMCMD_FRAME(24, 6),
    ANIMCMD_FRAME(28, 6),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd *const sAnims_AutumnLeaf[] = {
    sAnim_AutumnLeaf,
};

static void SpriteCallback_AutumnLeaf(struct Sprite *sprite)
{
    // Horizontal subpixel movement from Left to Right
    sprite->data[0] += sprite->data[2]; // speedX accumulator (fixed 1/16)
    sprite->x += sprite->data[0] >> 4;
    sprite->data[0] &= 0x0F;

    // Vertical downward drift (fixed 1/16)
    sprite->data[4] += sprite->data[3];
    sprite->y += sprite->data[4] >> 4;
    sprite->data[4] &= 0x0F;

    // Vertical sinusoidal wind flutter
    sprite->data[1] = (sprite->data[1] + 4) & 0xFF;
    sprite->y2 = gSineTable[sprite->data[1]] >> 6; // -4 to +4 pixels gentle bobbing

    // Wrap when drifting off the right edge (DISPLAY_WIDTH is 240)
    if (sprite->x >= DISPLAY_WIDTH + 16)
    {
        sprite->x = -16;
        sprite->y = (Random() % (DISPLAY_HEIGHT + 20)) - 10;
        sprite->data[1] = Random() & 0xFF;
    }
    // Wrap when drifting off bottom edge (DISPLAY_HEIGHT is 160)
    if (sprite->y >= DISPLAY_HEIGHT + 16)
    {
        sprite->y = -16;
        sprite->x = (Random() % (DISPLAY_WIDTH + 32)) - 16;
    }
}

static const struct SpriteTemplate sSpriteTemplate_AutumnLeaf = {
    .tileTag = FLDEFF_TILE_TAG_AUTUMN_LEAF,
    .paletteTag = FLDEFF_PAL_TAG_AUTUMN_LEAF,
    .oam = &sOamData_AutumnLeaf,
    .anims = sAnims_AutumnLeaf,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallback_AutumnLeaf,
};

static const struct MapLightSource sMapLightSources[] = {
    // Monument Flame at (37, 27)
    {
        .mapGroup        = MAP_GROUP(MAP_HAUNTED_WOODS),
        .mapNum          = MAP_NUM(MAP_HAUNTED_WOODS),
        .x               = 37,
        .y               = 27,
        .type            = LIGHT_TYPE_FLAME,
        .shape           = LIGHT_SHAPE_CIRCLE,
        .colorTint       = LIGHT_COLOR_NONE,
        .trackingLocalId = 0,
        .flagId          = 0,
    },
    // Flashlight Scientist at (24, 35)
    {
        .mapGroup        = MAP_GROUP(MAP_HAUNTED_WOODS),
        .mapNum          = MAP_NUM(MAP_HAUNTED_WOODS),
        .x               = 24,
        .y               = 35,
        .type            = LIGHT_TYPE_FLASHLIGHT,
        .shape           = LIGHT_SHAPE_CONE,
        .colorTint       = LIGHT_COLOR_NONE,
        .trackingLocalId = 2, // Scientist NPC
        .flagId          = 0,
    },
    // Firefly Swarm at (41, 3)
    {
        .mapGroup        = MAP_GROUP(MAP_HAUNTED_WOODS),
        .mapNum          = MAP_NUM(MAP_HAUNTED_WOODS),
        .x               = 41,
        .y               = 3,
        .type            = LIGHT_TYPE_FIREFLIES,
        .shape           = LIGHT_SHAPE_FIREFLIES,
        .colorTint       = LIGHT_COLOR_AMBER,
        .trackingLocalId = 0,
        .flagId          = 0,
    },
    // Firefly Swarm at (44, 39)
    {
        .mapGroup        = MAP_GROUP(MAP_HAUNTED_WOODS),
        .mapNum          = MAP_NUM(MAP_HAUNTED_WOODS),
        .x               = 44,
        .y               = 39,
        .type            = LIGHT_TYPE_FIREFLIES,
        .shape           = LIGHT_SHAPE_FIREFLIES,
        .colorTint       = LIGHT_COLOR_AMBER,
        .trackingLocalId = 0,
        .flagId          = 0,
    },
    // Firefly Swarm at (31, 3)
    {
        .mapGroup        = MAP_GROUP(MAP_HAUNTED_WOODS),
        .mapNum          = MAP_NUM(MAP_HAUNTED_WOODS),
        .x               = 31,
        .y               = 3,
        .type            = LIGHT_TYPE_FIREFLIES,
        .shape           = LIGHT_SHAPE_FIREFLIES,
        .colorTint       = LIGHT_COLOR_AMBER,
        .trackingLocalId = 0,
        .flagId          = 0,
    },
        // Firefly Swarm at (7, 14)
    {
        .mapGroup        = MAP_GROUP(MAP_HAUNTED_WOODS),
        .mapNum          = MAP_NUM(MAP_HAUNTED_WOODS),
        .x               = 7,
        .y               = 14,
        .type            = LIGHT_TYPE_FIREFLIES,
        .shape           = LIGHT_SHAPE_FIREFLIES,
        .colorTint       = LIGHT_COLOR_AMBER,
        .trackingLocalId = 0,
        .flagId          = 0,
    },
    // Flashlight Trainer (Camper Chris) at (48, 24)
    {
        .mapGroup        = MAP_GROUP(MAP_HAUNTED_WOODS),
        .mapNum          = MAP_NUM(MAP_HAUNTED_WOODS),
        .x               = 48,
        .y               = 24,
        .type            = LIGHT_TYPE_FLASHLIGHT,
        .shape           = LIGHT_SHAPE_CONE,
        .colorTint       = LIGHT_COLOR_NONE,
        .trackingLocalId = 3, // Camper Chris NPC
        .flagId          = TRAINER_FLAGS_START + TRAINER_CAMPER_2,
    },
    // Bug Swarm (Normal Black/Grey Bugs) in Lavender Town at (14, 13)
    {
        .mapGroup        = MAP_GROUP(MAP_LAVENDER_TOWN),
        .mapNum          = MAP_NUM(MAP_LAVENDER_TOWN),
        .x               = 14,
        .y               = 13,
        .type            = LIGHT_TYPE_BUGS,
        .shape           = LIGHT_SHAPE_FIREFLIES,
        .colorTint       = LIGHT_COLOR_BUGS_GRAY,
        .trackingLocalId = 0,
        .flagId          = 0,
    },
    // Bug Swarm (Normal Black/Grey Bugs) in Lavender Cemetery at (20, 16)
    {
        .mapGroup        = MAP_GROUP(MAP_LAVENDER_CEMETARY_MAP),
        .mapNum          = MAP_NUM(MAP_LAVENDER_CEMETARY_MAP),
        .x               = 20,
        .y               = 16,
        .type            = LIGHT_TYPE_BUGS,
        .shape           = LIGHT_SHAPE_FIREFLIES,
        .colorTint       = LIGHT_COLOR_BUGS_GRAY,
        .trackingLocalId = 0,
        .flagId          = 0,
    },
    // Blowing Autumn Leaves in Lavender Cemetery
    {
        .mapGroup        = MAP_GROUP(MAP_LAVENDER_CEMETARY_MAP),
        .mapNum          = MAP_NUM(MAP_LAVENDER_CEMETARY_MAP),
        .x               = 0,
        .y               = 0,
        .type            = LIGHT_TYPE_AUTUMN_LEAVES,
        .shape           = 0,
        .colorTint       = 0,
        .trackingLocalId = 0,
        .flagId          = 0,
    },
};

static EWRAM_DATA u8 sLightSpriteIds[MAX_MAP_LIGHTS] = {0};
static EWRAM_DATA bool8 sMapLightsActive = FALSE;

static void SpriteCallback_MapLightSource(struct Sprite *sprite)
{
    s16 screenX;
    s16 screenY;

    // Check if flame light is toggled off
    if (sprite->data[2] == LIGHT_TYPE_FLAME && FlagGet(FLAG_HAUNTED_WOODS_LIGHT_DISABLED))
    {
        sprite->invisible = TRUE;
        return;
    }

    // NPC Tracking
    if (sprite->data[1] != 0)
    {
        u8 objEventId;
        u8 localId = sprite->data[1];
        if (!TryGetObjectEventIdByLocalIdAndMap(localId, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup, &objEventId))
        {
            struct ObjectEvent *obj = &gObjectEvents[objEventId];
            struct Sprite *npcSprite = &gSprites[obj->spriteId];
            u8 direction = obj->facingDirection;

            if (npcSprite->invisible || !obj->active)
            {
                sprite->invisible = TRUE;
                return;
            }

            sprite->invisible = FALSE;

            if (sprite->data[2] == LIGHT_TYPE_FLASHLIGHT && sprite->data[3] == 0) // Flashlight Beam
            {
                s16 offsetX = 0;
                s16 offsetY = 0;

                switch (direction)
                {
                case DIR_NORTH:
                    offsetY = -32;
                    break;
                case DIR_WEST:
                    offsetX = -32;
                    break;
                case DIR_EAST:
                    offsetX = 32;
                    break;
                case DIR_SOUTH:
                default:
                    offsetY = 32;
                    break;
                }

                sprite->x = npcSprite->x + offsetX;
                sprite->y = npcSprite->y + offsetY;
                sprite->x2 = npcSprite->x2;
                sprite->y2 = npcSprite->y2;

                if (direction < LIGHT_CONE_ANIM_GLOW)
                    StartSpriteAnimIfDifferent(sprite, direction);
            }
            else if (sprite->data[2] == LIGHT_TYPE_FLASHLIGHT && sprite->data[3] == 1) // Flashlight Ambient Glow
            {
                sprite->x = npcSprite->x;
                sprite->y = npcSprite->y;
                sprite->x2 = npcSprite->x2;
                sprite->y2 = npcSprite->y2;

                StartSpriteAnimIfDifferent(sprite, LIGHT_CONE_ANIM_GLOW);
            }
            else
            {
                sprite->x = npcSprite->x;
                sprite->y = npcSprite->y;
                sprite->x2 = npcSprite->x2;
                sprite->y2 = npcSprite->y2;

                if (direction < ARRAY_COUNT(sAnims_LightCone))
                    StartSpriteAnimIfDifferent(sprite, direction);
            }
        }
        else
        {
            sprite->invisible = TRUE;
            return;
        }
    }
    else
    {
        // Reset base offsets for static lights
        sprite->x2 = 0;
        sprite->y2 = 0;

        // Check for size variable changes (0: 100%, 1: 50%, 2: 150%)
        if (sprite->data[2] == LIGHT_TYPE_FLAME)
        {
            u16 sizeVar = VarGet(VAR_HAUNTED_WOODS_LIGHT_SIZE);
            if (sizeVar != sprite->data[5])
            {
                sprite->data[5] = sizeVar;
                if (sizeVar == 1)
                    StartSpriteAffineAnim(sprite, LIGHT_ANIM_FLAME_50);
                else if (sizeVar == 2)
                    StartSpriteAffineAnim(sprite, LIGHT_ANIM_FLAME_150);
                else
                    StartSpriteAffineAnim(sprite, LIGHT_ANIM_FLAME_100);
            }

            // Organic flame flicker and jitter
            sprite->data[3]++;
            if ((sprite->data[3] & 3) == 0)
            {
                sprite->data[6] = (Random() % 3) - 1; // -1, 0, or 1
                sprite->data[7] = (Random() % 3) - 1;
            }
            sprite->x2 += sprite->data[6];
            sprite->y2 += sprite->data[7];

            // 2x2 movement patrol
            if (FlagGet(FLAG_HAUNTED_WOODS_LIGHT_MOVE))
            {
                u16 step = (sprite->data[4]++) & 0x7F; // 0..127
                s16 moveX = 0, moveY = 0;
                if (step < 32)
                {
                    moveX = step >> 1; // 0 -> 16
                    moveY = 0;
                }
                else if (step < 64)
                {
                    moveX = 16;
                    moveY = (step - 32) >> 1; // 0 -> 16
                }
                else if (step < 96)
                {
                    moveX = 16 - ((step - 64) >> 1); // 16 -> 0
                    moveY = 16;
                }
                else
                {
                    moveX = 0;
                    moveY = 16 - ((step - 96) >> 1); // 16 -> 0
                }
                sprite->x2 += moveX;
                sprite->y2 += moveY;
            }
        }
    }

    // Calculate live screen coordinates of the sprite's top-left corner
    screenX = sprite->x + sprite->x2 + sprite->centerToCornerVecX + gSpriteCoordOffsetX;
    screenY = sprite->y + sprite->y2 + sprite->centerToCornerVecY + gSpriteCoordOffsetY;

    // Off-screen culling: GBA OAM coordinates wrap every 512px horizontally and 256px vertically.
    if (screenX <= -112 || screenX >= DISPLAY_WIDTH || screenY <= -94 || screenY >= 128)
    {
        sprite->invisible = TRUE;
    }
    else
    {
        sprite->invisible = FALSE;
    }
}

void InitMapLightSources(void)
{
    u32 i;
    u8 count = 0;
    u8 mapGroup = gSaveBlock1Ptr->location.mapGroup;
    u8 mapNum = gSaveBlock1Ptr->location.mapNum;
    bool8 hasMatchingLights = FALSE;
    bool8 isDarkMap = (GetFlashLevel() > 0);

    DestroyMapLightSources();

    for (i = 0; i < ARRAY_COUNT(sMapLightSources); i++)
    {
        if (sMapLightSources[i].mapGroup == mapGroup && sMapLightSources[i].mapNum == mapNum)
        {
            if (sMapLightSources[i].flagId == 0 || FlagGet(sMapLightSources[i].flagId))
            {
                hasMatchingLights = TRUE;
                break;
            }
        }
    }

    if (!hasMatchingLights)
        return;

    for (i = 0; i < MAX_MAP_LIGHTS; i++)
        sLightSpriteIds[i] = MAX_SPRITES;

    LoadSpriteSheet(&sSpriteSheet_LightCircle);
    LoadSpriteSheet(&sSpriteSheet_LightCone);
    LoadSpriteSheet(&sSpriteSheet_Fireflies);
    LoadSpriteSheet(&sSpriteSheet_AutumnLeaf);
    LoadSpritePalette(&sSpritePalette_LightCircle);
    LoadSpritePalette(&sSpritePalette_Fireflies);
    LoadSpritePalette(&sSpritePalette_Bugs);
    LoadSpritePalette(&sSpritePalette_AutumnLeaf);

    if (isDarkMap)
    {
        SetGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_OBJWIN_ON);
        SetGpuRegBits(REG_OFFSET_WINOUT, WINOUT_WINOBJ_BG_ALL | WINOUT_WINOBJ_OBJ);
    }

    for (i = 0; i < ARRAY_COUNT(sMapLightSources) && count < MAX_MAP_LIGHTS; i++)
    {
        if (sMapLightSources[i].mapGroup == mapGroup && sMapLightSources[i].mapNum == mapNum)
        {
            if (sMapLightSources[i].flagId == 0 || FlagGet(sMapLightSources[i].flagId))
            {
                s16 x = sMapLightSources[i].x + MAP_OFFSET;
                s16 y = sMapLightSources[i].y + MAP_OFFSET;

                SetSpritePosToOffsetMapCoords(&x, &y, 8, 8);

                if (sMapLightSources[i].type == LIGHT_TYPE_FIREFLIES)
                {
                    if (isDarkMap)
                    {
                        u8 winSpriteId = CreateSprite(&sSpriteTemplate_Fireflies_Window, x, y, 0);
                        if (winSpriteId != MAX_SPRITES && count < MAX_MAP_LIGHTS)
                        {
                            gSprites[winSpriteId].coordOffsetEnabled = TRUE;
                            gSprites[winSpriteId].data[1] = 0;
                            gSprites[winSpriteId].data[2] = LIGHT_TYPE_FIREFLIES;
                            sLightSpriteIds[count++] = winSpriteId;
                        }
                    }
                    if (count < MAX_MAP_LIGHTS)
                    {
                        u8 colorSpriteId = CreateSprite(&sSpriteTemplate_Fireflies_Color, x, y, 1);
                        if (colorSpriteId != MAX_SPRITES)
                        {
                            gSprites[colorSpriteId].coordOffsetEnabled = TRUE;
                            gSprites[colorSpriteId].data[1] = 0;
                            gSprites[colorSpriteId].data[2] = LIGHT_TYPE_FIREFLIES;
                            sLightSpriteIds[count++] = colorSpriteId;
                        }
                    }
                }
                else if (sMapLightSources[i].type == LIGHT_TYPE_BUGS)
                {
                    if (count < MAX_MAP_LIGHTS)
                    {
                        u8 bugSpriteId = CreateSprite(&sSpriteTemplate_Bugs_Color, x, y, 1);
                        if (bugSpriteId != MAX_SPRITES)
                        {
                            gSprites[bugSpriteId].coordOffsetEnabled = TRUE;
                            gSprites[bugSpriteId].data[1] = 0;
                            gSprites[bugSpriteId].data[2] = LIGHT_TYPE_BUGS;
                            sLightSpriteIds[count++] = bugSpriteId;
                        }
                    }
                }
                else if (sMapLightSources[i].type == LIGHT_TYPE_AUTUMN_LEAVES)
                {
                    static const s16 sLeafStartX[] = { 15, 60, 110, 155, 195, 230 };
                    static const s16 sLeafStartY[] = { 20, 85, 130, 45,  105, 30 };
                    static const s16 sLeafSpeedX[] = { 36, 44, 32,  48,  38,  42 };
                    static const s16 sLeafDriftY[] = { 6,  8,  5,   10,  7,   9 };
                    u8 leafIdx;

                    for (leafIdx = 0; leafIdx < 6 && count < MAX_MAP_LIGHTS; leafIdx++)
                    {
                        u8 leafSpriteId = CreateSprite(&sSpriteTemplate_AutumnLeaf, sLeafStartX[leafIdx], sLeafStartY[leafIdx], 1);
                        if (leafSpriteId != MAX_SPRITES)
                        {
                            gSprites[leafSpriteId].coordOffsetEnabled = FALSE;
                            gSprites[leafSpriteId].data[0] = 0;
                            gSprites[leafSpriteId].data[1] = leafIdx * 42;
                            gSprites[leafSpriteId].data[2] = sLeafSpeedX[leafIdx];
                            gSprites[leafSpriteId].data[3] = sLeafDriftY[leafIdx];
                            gSprites[leafSpriteId].data[4] = 0;
                            sLightSpriteIds[count++] = leafSpriteId;
                        }
                    }
                }
                else if (sMapLightSources[i].type == LIGHT_TYPE_FLASHLIGHT)
                {
                    u8 objEventId;
                    s16 beamX = x;
                    s16 beamY = y;
                    u8 dir = DIR_SOUTH;
                    u8 beamSpriteId;
                    u8 glowSpriteId;

                    if (sMapLightSources[i].trackingLocalId != 0 
                     && !TryGetObjectEventIdByLocalIdAndMap(sMapLightSources[i].trackingLocalId, mapNum, mapGroup, &objEventId))
                    {
                        struct ObjectEvent *obj = &gObjectEvents[objEventId];
                        dir = obj->facingDirection;
                        switch (dir)
                        {
                        case DIR_NORTH:
                            beamY -= 32;
                            break;
                        case DIR_WEST:
                            beamX -= 32;
                            break;
                        case DIR_EAST:
                            beamX += 32;
                            break;
                        case DIR_SOUTH:
                        default:
                            beamY += 32;
                            break;
                        }
                    }

                    // Flashlight Beam (data[3] = 0)
                    beamSpriteId = CreateSprite(&sSpriteTemplate_LightCone, beamX, beamY, 0);
                    if (beamSpriteId != MAX_SPRITES && count < MAX_MAP_LIGHTS)
                    {
                        gSprites[beamSpriteId].coordOffsetEnabled = TRUE;
                        gSprites[beamSpriteId].data[1] = sMapLightSources[i].trackingLocalId;
                        gSprites[beamSpriteId].data[2] = LIGHT_TYPE_FLASHLIGHT;
                        gSprites[beamSpriteId].data[3] = 0; // Beam
                        StartSpriteAnim(&gSprites[beamSpriteId], dir);
                        sLightSpriteIds[count++] = beamSpriteId;
                    }

                    // Ambient Glow on NPC (data[3] = 1)
                    if (count < MAX_MAP_LIGHTS)
                    {
                        glowSpriteId = CreateSprite(&sSpriteTemplate_LightCone, x, y, 0);
                        if (glowSpriteId != MAX_SPRITES)
                        {
                            gSprites[glowSpriteId].coordOffsetEnabled = TRUE;
                            gSprites[glowSpriteId].data[1] = sMapLightSources[i].trackingLocalId;
                            gSprites[glowSpriteId].data[2] = LIGHT_TYPE_FLASHLIGHT;
                            gSprites[glowSpriteId].data[3] = 1; // Glow
                            StartSpriteAnim(&gSprites[glowSpriteId], LIGHT_CONE_ANIM_GLOW);
                            sLightSpriteIds[count++] = glowSpriteId;
                        }
                    }
                }
                else
                {
                    u8 spriteId = CreateSprite(&sSpriteTemplate_LightCircle, x, y, 0);
                    if (spriteId != MAX_SPRITES && count < MAX_MAP_LIGHTS)
                    {
                        u16 sizeVar;
                        u8 anim;

                        gSprites[spriteId].coordOffsetEnabled = TRUE;
                        gSprites[spriteId].data[1] = sMapLightSources[i].trackingLocalId;
                        gSprites[spriteId].data[2] = sMapLightSources[i].type;
                        gSprites[spriteId].data[3] = 0;

                        sizeVar = VarGet(VAR_HAUNTED_WOODS_LIGHT_SIZE);
                        anim = LIGHT_ANIM_FLAME_100;
                        if (sizeVar == 1)
                            anim = LIGHT_ANIM_FLAME_50;
                        else if (sizeVar == 2)
                            anim = LIGHT_ANIM_FLAME_150;

                        gSprites[spriteId].data[5] = sizeVar;
                        StartSpriteAffineAnim(&gSprites[spriteId], anim);

                        sLightSpriteIds[count++] = spriteId;
                    }
                }
            }
        }
    }

    if (count > 0)
        sMapLightsActive = TRUE;
}

void DestroyMapLightSources(void)
{
    u32 i;

    if (!sMapLightsActive)
        return;

    for (i = 0; i < MAX_MAP_LIGHTS; i++)
    {
        if (sLightSpriteIds[i] != MAX_SPRITES)
        {
            if (gSprites[sLightSpriteIds[i]].oam.affineMode & ST_OAM_AFFINE_ON_MASK)
                FreeSpriteOamMatrix(&gSprites[sLightSpriteIds[i]]);
            DestroySprite(&gSprites[sLightSpriteIds[i]]);
            sLightSpriteIds[i] = MAX_SPRITES;
        }
    }

    FreeSpriteTilesByTag(FLDEFF_TILE_TAG_LIGHT_CIRCLE);
    FreeSpriteTilesByTag(FLDEFF_TILE_TAG_LIGHT_CONE);
    FreeSpriteTilesByTag(FLDEFF_TILE_TAG_FIREFLIES);
    FreeSpriteTilesByTag(FLDEFF_TILE_TAG_AUTUMN_LEAF);
    FreeSpritePaletteByTag(FLDEFF_PAL_TAG_LIGHT_CIRCLE);
    FreeSpritePaletteByTag(FLDEFF_PAL_TAG_LIGHT_AMBER);
    FreeSpritePaletteByTag(FLDEFF_PAL_TAG_LIGHT_BUGS);
    FreeSpritePaletteByTag(FLDEFF_PAL_TAG_AUTUMN_LEAF);
    sMapLightsActive = FALSE;
}

void UpdateMapLightSourcesVisibility(bool8 visible)
{
    u32 i;

    if (!sMapLightsActive)
        return;

    for (i = 0; i < MAX_MAP_LIGHTS; i++)
    {
        if (sLightSpriteIds[i] != MAX_SPRITES)
        {
            gSprites[sLightSpriteIds[i]].invisible = !visible;
        }
    }
}

void Special_UpdateMapLightSources(void)
{
    InitMapLightSources();
}

void ActivateTrainerLight(struct ObjectEvent *trainerObj)
{
    u32 i;
    u8 beamSpriteId;
    u8 glowSpriteId;
    u8 mapGroup;
    u8 mapNum;
    bool8 isFlashlightTrainer = FALSE;
    bool8 alreadyActive = FALSE;
    s16 offsetX = 0;
    s16 offsetY = 0;

    if (trainerObj == NULL || GetFlashLevel() == 0)
        return;

    mapGroup = gSaveBlock1Ptr->location.mapGroup;
    mapNum = gSaveBlock1Ptr->location.mapNum;

    // Guard 1: Verify that this specific trainer is actually configured with a flashlight on this map
    for (i = 0; i < ARRAY_COUNT(sMapLightSources); i++)
    {
        if (sMapLightSources[i].mapGroup == mapGroup 
         && sMapLightSources[i].mapNum == mapNum 
         && sMapLightSources[i].trackingLocalId == trainerObj->localId
         && sMapLightSources[i].type == LIGHT_TYPE_FLASHLIGHT)
        {
            isFlashlightTrainer = TRUE;
            break;
        }
    }

    if (!isFlashlightTrainer)
        return;

    // Guard 2: Check if this trainer already has active light sprites
    for (i = 0; i < MAX_MAP_LIGHTS; i++)
    {
        if (sLightSpriteIds[i] != MAX_SPRITES 
         && gSprites[sLightSpriteIds[i]].data[1] == trainerObj->localId)
        {
            gSprites[sLightSpriteIds[i]].invisible = FALSE;
            alreadyActive = TRUE;
        }
    }

    if (alreadyActive)
        return;

    // Defensive loading of cone sprite sheet, palette, and window registers
    if (GetSpriteTileStartByTag(FLDEFF_TILE_TAG_LIGHT_CONE) == TAG_NONE)
        LoadSpriteSheet(&sSpriteSheet_LightCone);
    LoadSpritePalette(&sSpritePalette_LightCircle);

    SetGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_OBJWIN_ON);
    SetGpuRegBits(REG_OFFSET_WINOUT, WINOUT_WINOBJ_BG_ALL | WINOUT_WINOBJ_OBJ);

    switch (trainerObj->facingDirection)
    {
    case DIR_NORTH:
        offsetY = -32;
        break;
    case DIR_WEST:
        offsetX = -32;
        break;
    case DIR_EAST:
        offsetX = 32;
        break;
    case DIR_SOUTH:
    default:
        offsetY = 32;
        break;
    }

    // 1. Create Flashlight Beam (data[3] = 0)
    for (i = 0; i < MAX_MAP_LIGHTS; i++)
    {
        if (sLightSpriteIds[i] == MAX_SPRITES)
            break;
    }
    if (i < MAX_MAP_LIGHTS)
    {
        beamSpriteId = CreateSprite(&sSpriteTemplate_LightCone, 
                                    gSprites[trainerObj->spriteId].x + offsetX, 
                                    gSprites[trainerObj->spriteId].y + offsetY, 0);
        if (beamSpriteId != MAX_SPRITES)
        {
            gSprites[beamSpriteId].coordOffsetEnabled = TRUE;
            gSprites[beamSpriteId].data[1] = trainerObj->localId;
            gSprites[beamSpriteId].data[2] = LIGHT_TYPE_FLASHLIGHT;
            gSprites[beamSpriteId].data[3] = 0; // Beam
            StartSpriteAnim(&gSprites[beamSpriteId], trainerObj->facingDirection);

            sLightSpriteIds[i] = beamSpriteId;
            sMapLightsActive = TRUE;
        }
    }

    // 2. Create Flashlight Ambient Glow (data[3] = 1)
    for (i = 0; i < MAX_MAP_LIGHTS; i++)
    {
        if (sLightSpriteIds[i] == MAX_SPRITES)
            break;
    }
    if (i < MAX_MAP_LIGHTS)
    {
        glowSpriteId = CreateSprite(&sSpriteTemplate_LightCone, 
                                    gSprites[trainerObj->spriteId].x, 
                                    gSprites[trainerObj->spriteId].y, 0);
        if (glowSpriteId != MAX_SPRITES)
        {
            gSprites[glowSpriteId].coordOffsetEnabled = TRUE;
            gSprites[glowSpriteId].data[1] = trainerObj->localId;
            gSprites[glowSpriteId].data[2] = LIGHT_TYPE_FLASHLIGHT;
            gSprites[glowSpriteId].data[3] = 1; // Glow
            StartSpriteAnim(&gSprites[glowSpriteId], LIGHT_CONE_ANIM_GLOW);

            sLightSpriteIds[i] = glowSpriteId;
            sMapLightsActive = TRUE;
        }
    }
}
