#include "global.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "field_effect.h"
#include "field_light_sources.h"
#include "field_player_avatar.h"
#include "field_screen_effect.h"
#include "field_weather.h"
#include "fieldmap.h"
#include "gpu_regs.h"
#include "overworld.h"
#include "palette.h"
#include "random.h"
#include "sprite.h"
#include "task.h"
#include "trig.h"
#include "sound.h"
#include "constants/field_effects.h"
#include "constants/flags.h"
#include "constants/maps.h"
#include "constants/global.h"
#include "constants/opponents.h"
#include "constants/songs.h"
#include "constants/species.h"
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

#define NUM_AUTUMN_LEAVES 6
static EWRAM_DATA u8 sAutumnLeafSpriteIds[NUM_AUTUMN_LEAVES] = {0};
static EWRAM_DATA bool8 sAutumnLeavesActive = FALSE;
static EWRAM_DATA bool8 sAutumnLeavesWindingOut = FALSE;

static void DestroyAutumnLeafSprite(struct Sprite *sprite)
{
    u8 i;
    u8 spriteId = MAX_SPRITES;
    bool8 anyRemaining = FALSE;

    for (i = 0; i < NUM_AUTUMN_LEAVES; i++)
    {
        if (sAutumnLeafSpriteIds[i] != MAX_SPRITES && &gSprites[sAutumnLeafSpriteIds[i]] == sprite)
        {
            spriteId = sAutumnLeafSpriteIds[i];
            sAutumnLeafSpriteIds[i] = MAX_SPRITES;
            break;
        }
    }

    if (spriteId != MAX_SPRITES)
        DestroySprite(sprite);

    for (i = 0; i < NUM_AUTUMN_LEAVES; i++)
    {
        if (sAutumnLeafSpriteIds[i] != MAX_SPRITES)
        {
            anyRemaining = TRUE;
            break;
        }
    }

    if (!anyRemaining)
    {
        FreeSpriteTilesByTag(FLDEFF_TILE_TAG_AUTUMN_LEAF);
        FreeSpritePaletteByTag(FLDEFF_PAL_TAG_AUTUMN_LEAF);
        sAutumnLeavesActive = FALSE;
        sAutumnLeavesWindingOut = FALSE;
    }
}

static void SpriteCallback_AutumnLeaf(struct Sprite *sprite)
{
    // If waiting for delayed entry during wind-in, decrement delay
    if (sprite->data[5] > 0)
    {
        sprite->data[5]--;
        if (sprite->data[5] == 0)
        {
            sprite->invisible = FALSE;
            sprite->x = -16;
            sprite->data[0] = 0;
            sprite->data[4] = 0;
        }
        return;
    }

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

    // Screen exit checks
    // Right edge exit (DISPLAY_WIDTH is 240)
    if (sprite->x >= DISPLAY_WIDTH + 16)
    {
        if (sprite->data[6] != 0) // Wind-out mode
        {
            DestroyAutumnLeafSprite(sprite);
            return;
        }
        // Normal wrap: send back to left edge with new random Y and phase
        sprite->x = -16;
        sprite->y = (Random() % (DISPLAY_HEIGHT + 20)) - 10;
        sprite->data[1] = Random() & 0xFF;
    }
    // Bottom edge exit (DISPLAY_HEIGHT is 160)
    if (sprite->y >= DISPLAY_HEIGHT + 16)
    {
        if (sprite->data[6] != 0) // Wind-out mode
        {
            DestroyAutumnLeafSprite(sprite);
            return;
        }
        // Normal wrap: send back to top edge
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

static void SpriteCallback_FlyingPidgey(struct Sprite *sprite);

static const struct OamData sOamData_FlyingPidgey = {
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x32),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(32x32),
    .tileNum = 0,
    .priority = 1, // Priority 1: High in the sky above trees and player
    .paletteNum = 0,
};

enum {
    PIDGEY_ANIM_FLYING,
    PIDGEY_ANIM_GLIDE,
    PIDGEY_ANIM_PERCHED,
};

static const union AnimCmd sAnim_PidgeyFlying[] = {
    ANIMCMD_FRAME(0,  6),
    ANIMCMD_FRAME(16, 6),
    ANIMCMD_FRAME(0,  6),
    ANIMCMD_FRAME(16, 6),
    ANIMCMD_FRAME(0, 16),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_PidgeyGlide[] = {
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_PidgeyPerched[] = {
    ANIMCMD_FRAME(32, 60),
    ANIMCMD_FRAME(48, 14),
    ANIMCMD_FRAME(32, 60),
    ANIMCMD_FRAME(48, 18),
    ANIMCMD_FRAME(32, 60),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd *const sAnims_FlyingPidgey[] = {
    [PIDGEY_ANIM_FLYING]  = sAnim_PidgeyFlying,
    [PIDGEY_ANIM_GLIDE]   = sAnim_PidgeyGlide,
    [PIDGEY_ANIM_PERCHED] = sAnim_PidgeyPerched,
};

static const u32 sFlyingPidgey_Gfx[] = INCBIN_U32("graphics/field_effects/pics/flying_pidgey.4bpp");

static const struct SpriteSheet sSpriteSheet_FlyingPidgey = {
    .data = sFlyingPidgey_Gfx,
    .size = 2048,
    .tag = FLDEFF_TILE_TAG_FLYING_PIDGEY,
};

static const u16 sFlyingPidgey_Pal[] = INCBIN_U16("graphics/pokemon/pidgey/overworld_normal.gbapal");

static const struct SpritePalette sSpritePalette_FlyingPidgey = {
    .data = sFlyingPidgey_Pal,
    .tag = FLDEFF_PAL_TAG_FLYING_PIDGEY,
};

static const struct SpriteTemplate sSpriteTemplate_FlyingPidgey = {
    .tileTag = FLDEFF_TILE_TAG_FLYING_PIDGEY,
    .paletteTag = FLDEFF_PAL_TAG_FLYING_PIDGEY,
    .oam = &sOamData_FlyingPidgey,
    .anims = sAnims_FlyingPidgey,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallback_FlyingPidgey,
};

static void SpriteCallback_TreePidgey(struct Sprite *sprite);

static const struct SpriteTemplate sSpriteTemplate_TreePidgey = {
    .tileTag = FLDEFF_TILE_TAG_FLYING_PIDGEY,
    .paletteTag = FLDEFF_PAL_TAG_FLYING_PIDGEY,
    .oam = &sOamData_FlyingPidgey,
    .anims = sAnims_FlyingPidgey,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallback_TreePidgey,
};

static const struct OamData sOamData_MagikarpSplash = {
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x32),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(32x32),
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
};

enum {
    MAGIKARP_ANIM_LEAP,  // Frame 0: Ascent / head up
    MAGIKARP_ANIM_FLAIL, // Frame 0 -> Frame 1 rapid flailing
    MAGIKARP_ANIM_DIVE,  // Frame 2: Descent / head down
};

static const union AnimCmd sAnim_MagikarpLeap[] = {
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_MagikarpFlail[] = {
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(16, 3),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_MagikarpDive[] = {
    ANIMCMD_FRAME(32, 8),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd *const sAnims_MagikarpSplash[] = {
    [MAGIKARP_ANIM_LEAP]  = sAnim_MagikarpLeap,
    [MAGIKARP_ANIM_FLAIL] = sAnim_MagikarpFlail,
    [MAGIKARP_ANIM_DIVE]  = sAnim_MagikarpDive,
};

static const u32 sMagikarpSplash_Gfx[] = INCBIN_U32("graphics/field_effects/pics/magikarp_splash.4bpp");

static const struct SpriteSheet sSpriteSheet_MagikarpSplash = {
    .data = sMagikarpSplash_Gfx,
    .size = 1536,
    .tag = FLDEFF_TILE_TAG_MAGIKARP_SPLASH,
};

static const u16 sMagikarpSplash_Pal[] = INCBIN_U16("graphics/pokemon/magikarp/overworld_normal.gbapal");

static const struct SpritePalette sSpritePalette_MagikarpSplash = {
    .data = sMagikarpSplash_Pal,
    .tag = FLDEFF_PAL_TAG_MAGIKARP_SPLASH,
};

static void SpriteCallback_MagikarpSplash(struct Sprite *sprite);

static const struct SpriteTemplate sSpriteTemplate_MagikarpSplash = {
    .tileTag = FLDEFF_TILE_TAG_MAGIKARP_SPLASH,
    .paletteTag = FLDEFF_PAL_TAG_MAGIKARP_SPLASH,
    .oam = &sOamData_MagikarpSplash,
    .anims = sAnims_MagikarpSplash,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallback_MagikarpSplash,
};

static const struct OamData sOamData_WingullSkim = {
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x32),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(32x32),
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
};

enum {
    WINGULL_ANIM_GLIDE, // Frame 0: Wings flat / gliding
    WINGULL_ANIM_SKIM,  // Frame 1: Low dipping skimming pose
    WINGULL_ANIM_FLAP,  // Alternates Frame 0 and Frame 2: Flapping wings
};

static const union AnimCmd sAnim_WingullGlide[] = {
    ANIMCMD_FRAME(0, 16),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_WingullSkim[] = {
    ANIMCMD_FRAME(16, 8),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_WingullFlap[] = {
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(32, 4),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd *const sAnims_WingullSkim[] = {
    [WINGULL_ANIM_GLIDE] = sAnim_WingullGlide,
    [WINGULL_ANIM_SKIM]  = sAnim_WingullSkim,
    [WINGULL_ANIM_FLAP]  = sAnim_WingullFlap,
};

static const u32 sWingullSkim_Gfx[] = INCBIN_U32("graphics/field_effects/pics/wingull_skim.4bpp");

static const struct SpriteSheet sSpriteSheet_WingullSkim = {
    .data = sWingullSkim_Gfx,
    .size = 1536,
    .tag = FLDEFF_TILE_TAG_WINGULL_SKIM,
};

static const u16 sWingullSkim_Pal[] = INCBIN_U16("graphics/pokemon/wingull/overworld_normal.gbapal");

static const struct SpritePalette sSpritePalette_WingullSkim = {
    .data = sWingullSkim_Pal,
    .tag = FLDEFF_PAL_TAG_WINGULL_SKIM,
};

static void SpriteCallback_WingullSkim(struct Sprite *sprite);

static const struct SpriteTemplate sSpriteTemplate_WingullSkim = {
    .tileTag = FLDEFF_TILE_TAG_WINGULL_SKIM,
    .paletteTag = FLDEFF_PAL_TAG_WINGULL_SKIM,
    .oam = &sOamData_WingullSkim,
    .anims = sAnims_WingullSkim,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallback_WingullSkim,
};

static const struct OamData sOamData_GastlySpook = {
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x32),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(32x32),
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
};

enum {
    GASTLY_ANIM_FLOAT,
    GASTLY_ANIM_SMOKE_PUFF,
};

static const union AnimCmd sAnim_GastlyFloat[] = {
    ANIMCMD_FRAME(0, 16),
    ANIMCMD_FRAME(16, 16),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_GastlySmokePuff[] = {
    ANIMCMD_FRAME(32, 4),
    ANIMCMD_FRAME(48, 4),
    ANIMCMD_FRAME(64, 4),
    ANIMCMD_FRAME(80, 4),
    ANIMCMD_FRAME(96, 6),
    ANIMCMD_END,
};

static const union AnimCmd *const sAnims_GastlySpook[] = {
    [GASTLY_ANIM_FLOAT]      = sAnim_GastlyFloat,
    [GASTLY_ANIM_SMOKE_PUFF] = sAnim_GastlySmokePuff,
};

static const u32 sGastlySpook_Gfx[] = INCBIN_U32("graphics/field_effects/pics/gastly_spook.4bpp");

static const struct SpriteSheet sSpriteSheet_GastlySpook = {
    .data = sGastlySpook_Gfx,
    .size = 3584,
    .tag = FLDEFF_TILE_TAG_GASTLY_SPOOK,
};

static const u16 sGastlySpook_Pal[] = INCBIN_U16("graphics/pokemon/gastly/overworld_normal.gbapal");

static const struct SpritePalette sSpritePalette_GastlySpook = {
    .data = sGastlySpook_Pal,
    .tag = FLDEFF_PAL_TAG_GASTLY_SPOOK,
};

static void SpriteCallback_GastlySpook(struct Sprite *sprite);

static const struct SpriteTemplate sSpriteTemplate_GastlySpook = {
    .tileTag = FLDEFF_TILE_TAG_GASTLY_SPOOK,
    .paletteTag = FLDEFF_PAL_TAG_GASTLY_SPOOK,
    .oam = &sOamData_GastlySpook,
    .anims = sAnims_GastlySpook,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallback_GastlySpook,
};

static const struct MapLightSource sMapLightSources[] = {
    // Ambient Gastly in Haunted Woods at (47, 33)
    {
        .mapGroup        = MAP_GROUP(MAP_HAUNTED_WOODS),
        .mapNum          = MAP_NUM(MAP_HAUNTED_WOODS),
        .x               = 47,
        .y               = 33,
        .type            = LIGHT_TYPE_GASTLY_SPOOK,
        .shape           = LIGHT_SHAPE_CIRCLE,
        .colorTint       = LIGHT_COLOR_NONE,
        .trackingLocalId = 0,
        .flagId          = 0,
    },
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
    // Flying Pidgey flock across Route 1
    {
        .mapGroup        = MAP_GROUP(MAP_ROUTE1),
        .mapNum          = MAP_NUM(MAP_ROUTE1),
        .x               = 0,
        .y               = 0,
        .type            = LIGHT_TYPE_FLYING_PIDGEY,
        .shape           = 0,
        .colorTint       = 0,
        .trackingLocalId = 0,
        .flagId          = 0,
    },
    // Ground & Tree Perched & Flying Pidgey on Route 8
    {
        .mapGroup        = MAP_GROUP(MAP_ROUTE8),
        .mapNum          = MAP_NUM(MAP_ROUTE8),
        .x               = 24,
        .y               = 4,
        .type            = LIGHT_TYPE_TREE_PIDGEY,
        .shape           = 0,
        .colorTint       = 0,
        .trackingLocalId = 0,
        .flagId          = 0,
    },
    // Ambient Magikarp Splash in Celadon City (Central Pond)
    {
        .mapGroup        = MAP_GROUP(MAP_CELADON_CITY),
        .mapNum          = MAP_NUM(MAP_CELADON_CITY),
        .x               = 26,
        .y               = 22,
        .type            = LIGHT_TYPE_MAGIKARP_SPLASH,
        .shape           = 0,
        .colorTint       = 0,
        .trackingLocalId = 0,
        .flagId          = 0,
    },
    // Ambient Wingull Skim on Route 12 at (20, 71)
    {
        .mapGroup        = MAP_GROUP(MAP_ROUTE12),
        .mapNum          = MAP_NUM(MAP_ROUTE12),
        .x               = 20,
        .y               = 71,
        .type            = LIGHT_TYPE_WINGULL_SKIM,
        .shape           = 0,
        .colorTint       = 0,
        .trackingLocalId = 0,
        .flagId          = 0,
    },
};

static EWRAM_DATA u8 sLightSpriteIds[MAX_MAP_LIGHTS] = {0};
static EWRAM_DATA bool8 sMapLightsActive = FALSE;

// FLAG_HAUNTED_WOODS_LIGHT_DISABLED / VAR_HAUNTED_WOODS_LIGHT_SIZE /
// FLAG_HAUNTED_WOODS_LIGHT_MOVE are driven by HauntedWoods' own map scripts as
// debug controls for its monument flame. They are checked in the shared flame
// code path, so without this scope check every LIGHT_TYPE_FLAME on every map
// would inherit Haunted Woods' toggle, size and 2x2 patrol state.
static bool8 IsHauntedWoodsFlameMap(void)
{
    return gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(MAP_HAUNTED_WOODS)
        && gSaveBlock1Ptr->location.mapNum == MAP_NUM(MAP_HAUNTED_WOODS);
}

static void SpriteCallback_MapLightSource(struct Sprite *sprite)
{
    s16 screenX;
    s16 screenY;

    // Check if flame light is toggled off
    if (sprite->data[2] == LIGHT_TYPE_FLAME && IsHauntedWoodsFlameMap() && FlagGet(FLAG_HAUNTED_WOODS_LIGHT_DISABLED))
    {
        sprite->invisible = TRUE;
        return;
    }

#define TRACKING_PLAYER 0xFF

    // NPC / Player Tracking
    if (sprite->data[1] != 0)
    {
        struct Sprite *targetSprite;
        u8 direction;

        if (sprite->data[1] == TRACKING_PLAYER)
        {
            if (gPlayerAvatar.spriteId >= MAX_SPRITES || !gObjectEvents[gPlayerAvatar.objectEventId].active)
            {
                sprite->invisible = TRUE;
                return;
            }
            targetSprite = &gSprites[gPlayerAvatar.spriteId];
            direction = gObjectEvents[gPlayerAvatar.objectEventId].facingDirection;
        }
        else
        {
            u8 objEventId;
            u8 localId = sprite->data[1];
            if (TryGetObjectEventIdByLocalIdAndMap(localId, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup, &objEventId))
            {
                sprite->invisible = TRUE;
                return;
            }

            struct ObjectEvent *obj = &gObjectEvents[objEventId];
            targetSprite = &gSprites[obj->spriteId];
            direction = obj->facingDirection;
            if (targetSprite->invisible || !obj->active)
            {
                sprite->invisible = TRUE;
                return;
            }
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

            sprite->x = targetSprite->x + offsetX;
            sprite->y = targetSprite->y + offsetY;
            sprite->x2 = targetSprite->x2;
            sprite->y2 = targetSprite->y2;

            if (direction < LIGHT_CONE_ANIM_GLOW)
                StartSpriteAnimIfDifferent(sprite, direction);
        }
        else if (sprite->data[2] == LIGHT_TYPE_FLASHLIGHT && sprite->data[3] == 1) // Flashlight Ambient Glow
        {
            sprite->x = targetSprite->x;
            sprite->y = targetSprite->y;
            sprite->x2 = targetSprite->x2;
            sprite->y2 = targetSprite->y2;

            StartSpriteAnimIfDifferent(sprite, LIGHT_CONE_ANIM_GLOW);
        }
        else
        {
            sprite->x = targetSprite->x;
            sprite->y = targetSprite->y;
            sprite->x2 = targetSprite->x2;
            sprite->y2 = targetSprite->y2;

            if (direction < ARRAY_COUNT(sAnims_LightCone))
                StartSpriteAnimIfDifferent(sprite, direction);
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
            bool8 isControlMap = IsHauntedWoodsFlameMap();
            u16 sizeVar = isControlMap ? VarGet(VAR_HAUNTED_WOODS_LIGHT_SIZE) : 0;
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
            if (isControlMap && FlagGet(FLAG_HAUNTED_WOODS_LIGHT_MOVE))
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
    // Extended margin by 26px (>1.5 tiles) so light sprites near screen edges don't flicker on and off.
    if (screenX <= -90 || screenX >= DISPLAY_WIDTH + 26 || screenY <= -90 || screenY >= DISPLAY_HEIGHT + 26)
    {
        sprite->invisible = TRUE;
    }
    else
    {
        sprite->invisible = FALSE;
    }
}

static const s16 sLeafStartX[] = { 15, 60, 110, 155, 195, 230 };
static const s16 sLeafStartY[] = { 20, 85, 130, 45,  105, 30 };
static const s16 sLeafSpeedX[] = { 36, 44, 32,  48,  38,  42 };
static const s16 sLeafDriftY[] = { 6,  8,  5,   10,  7,   9 };

static bool8 MapHasAutumnLeaves(u8 mapGroup, u8 mapNum)
{
    u32 i;
    for (i = 0; i < ARRAY_COUNT(sMapLightSources); i++)
    {
        if (sMapLightSources[i].mapGroup == mapGroup && sMapLightSources[i].mapNum == mapNum)
        {
            if (sMapLightSources[i].type == LIGHT_TYPE_AUTUMN_LEAVES)
                return TRUE;
        }
    }
    return FALSE;
}

static void SpawnAutumnLeaves(bool8 isWindIn)
{
    u8 leafIdx;

    if (GetSpriteTileStartByTag(FLDEFF_TILE_TAG_AUTUMN_LEAF) == 0xFFFF)
        LoadSpriteSheet(&sSpriteSheet_AutumnLeaf);
    {
        u8 palIndex = IndexOfSpritePaletteTag(FLDEFF_PAL_TAG_AUTUMN_LEAF);
        if (palIndex == 0xFF)
            FieldEffectScript_LoadFadedPal(&sSpritePalette_AutumnLeaf);
        else
            UpdateSpritePaletteWithWeather(palIndex, TRUE);
    }

    if (!sAutumnLeavesActive && !sAutumnLeavesWindingOut)
    {
        for (leafIdx = 0; leafIdx < NUM_AUTUMN_LEAVES; leafIdx++)
            sAutumnLeafSpriteIds[leafIdx] = MAX_SPRITES;
    }

    sAutumnLeavesActive = TRUE;
    sAutumnLeavesWindingOut = FALSE;

    for (leafIdx = 0; leafIdx < NUM_AUTUMN_LEAVES; leafIdx++)
    {
        s16 startX = isWindIn ? -16 : sLeafStartX[leafIdx];
        s16 startY = sLeafStartY[leafIdx];
        u8 delay = isWindIn ? (leafIdx * 20) : 0;

        if (sAutumnLeafSpriteIds[leafIdx] != MAX_SPRITES)
        {
            struct Sprite *sprite = &gSprites[sAutumnLeafSpriteIds[leafIdx]];
            sprite->data[6] = 0; // cancel wind-out
            continue;
        }

        u8 leafSpriteId = CreateSprite(&sSpriteTemplate_AutumnLeaf, startX, startY, 1);
        if (leafSpriteId != MAX_SPRITES)
        {
            struct Sprite *sprite = &gSprites[leafSpriteId];
            sprite->coordOffsetEnabled = FALSE;
            sprite->data[0] = 0;
            sprite->data[1] = leafIdx * 42;
            sprite->data[2] = sLeafSpeedX[leafIdx];
            sprite->data[3] = sLeafDriftY[leafIdx];
            sprite->data[4] = 0;
            sprite->data[5] = delay;
            sprite->data[6] = 0;
            sprite->invisible = (delay > 0);
            sAutumnLeafSpriteIds[leafIdx] = leafSpriteId;
        }
    }
}

static void WindOutAutumnLeaves(void)
{
    u8 i;
    sAutumnLeavesWindingOut = TRUE;

    for (i = 0; i < NUM_AUTUMN_LEAVES; i++)
    {
        if (sAutumnLeafSpriteIds[i] != MAX_SPRITES)
        {
            struct Sprite *sprite = &gSprites[sAutumnLeafSpriteIds[i]];
            if (sprite->data[5] > 0)
            {
                // Hasn't entered screen yet, destroy immediately
                DestroyAutumnLeafSprite(sprite);
            }
            else
            {
                // On screen: tell it to blow away and destroy itself on screen exit
                sprite->data[6] = 1;
            }
        }
    }
}

struct PidgeyFlockOffset {
    s16 x;
    s16 y;
    u8 phaseOffset;
    u8 animOffset;
};

#define NUM_FLYING_PIDGEY 5

static const struct PidgeyFlockOffset sPidgeyFlockOffsets[NUM_FLYING_PIDGEY] = {
    {   0,   0,   0, 0 }, // Leader
    { -24, -14,  40, 2 }, // Upper wingman
    { -22,  14,  80, 1 }, // Lower wingman
    { -48, -26, 120, 4 }, // Upper trailer
    { -46,  24, 160, 3 }, // Lower trailer
};

static EWRAM_DATA u8 sFlyingPidgeySpriteIds[NUM_FLYING_PIDGEY] = {0};
static EWRAM_DATA bool8 sFlyingPidgeyActive = FALSE;
static EWRAM_DATA bool8 sTreePidgeyActive = FALSE;
static EWRAM_DATA u16 sFlyingPidgeyFlockCooldown = 0;
static EWRAM_DATA s16 sFlyingPidgeyBaseX = 0;
static EWRAM_DATA s16 sFlyingPidgeyBaseY = 0;
static EWRAM_DATA u16 sFlyingPidgeySubX = 0;

static void SpriteCallback_FlyingPidgey(struct Sprite *sprite)
{
    u8 birdIdx = sprite->data[0];

    if (birdIdx == 0)
    {
        if (sFlyingPidgeyFlockCooldown > 0)
        {
            sFlyingPidgeyFlockCooldown--;
            if (sFlyingPidgeyFlockCooldown == 0)
            {
                u8 i;
                sFlyingPidgeyBaseX = -80;
                sFlyingPidgeySubX = 0;
                sFlyingPidgeyBaseY = 25 + (Random() % 50);

                for (i = 0; i < NUM_FLYING_PIDGEY; i++)
                {
                    if (sFlyingPidgeySpriteIds[i] != MAX_SPRITES)
                        SeekSpriteAnim(&gSprites[sFlyingPidgeySpriteIds[i]], sPidgeyFlockOffsets[i].animOffset);
                }
            }
        }
        else
        {
            // Move forward (24/16 = 1.5 pixels per frame)
            sFlyingPidgeySubX += 24;
            sFlyingPidgeyBaseX += sFlyingPidgeySubX >> 4;
            sFlyingPidgeySubX &= 0x0F;

            // When trailing bird passes offscreen right, start cooldown
            if (sFlyingPidgeyBaseX - 48 >= DISPLAY_WIDTH + 32)
            {
                sFlyingPidgeyFlockCooldown = 240 + (Random() % 180);
            }
        }
    }

    if (sFlyingPidgeyFlockCooldown > 0)
    {
        sprite->invisible = TRUE;
    }
    else
    {
        s16 targetX = sFlyingPidgeyBaseX + sPidgeyFlockOffsets[birdIdx].x;
        s16 targetY = sFlyingPidgeyBaseY + sPidgeyFlockOffsets[birdIdx].y;

        sprite->x = targetX;
        sprite->y = targetY;
        sprite->y2 = gSineTable[(gMain.vblankCounter1 * 2 + sPidgeyFlockOffsets[birdIdx].phaseOffset) & 0xFF] >> 6;
        sprite->invisible = (targetX < -32 || targetX > DISPLAY_WIDTH + 32);
    }
}

static bool8 MapHasFlyingPidgey(u8 mapGroup, u8 mapNum)
{
    u32 i;
    for (i = 0; i < ARRAY_COUNT(sMapLightSources); i++)
    {
        if (sMapLightSources[i].mapGroup == mapGroup && sMapLightSources[i].mapNum == mapNum)
        {
            if (sMapLightSources[i].type == LIGHT_TYPE_FLYING_PIDGEY)
                return TRUE;
        }
    }
    return FALSE;
}

static void SpawnFlyingPidgey(void)
{
    u8 i;

    if (sFlyingPidgeyActive)
        return;

    if (GetSpriteTileStartByTag(FLDEFF_TILE_TAG_FLYING_PIDGEY) == 0xFFFF)
        LoadSpriteSheet(&sSpriteSheet_FlyingPidgey);
    {
        u8 palIndex = IndexOfSpritePaletteTag(FLDEFF_PAL_TAG_FLYING_PIDGEY);
        if (palIndex == 0xFF)
            FieldEffectScript_LoadFadedPal(&sSpritePalette_FlyingPidgey);
        else
            UpdateSpritePaletteWithWeather(palIndex, TRUE);
    }

    sFlyingPidgeyActive = TRUE;
    sFlyingPidgeyFlockCooldown = 60; // 1 second after entering map
    sFlyingPidgeyBaseX = -80;
    sFlyingPidgeySubX = 0;
    sFlyingPidgeyBaseY = 25 + (Random() % 50);

    for (i = 0; i < NUM_FLYING_PIDGEY; i++)
        sFlyingPidgeySpriteIds[i] = MAX_SPRITES;

    for (i = 0; i < NUM_FLYING_PIDGEY; i++)
    {
        u8 spriteId = CreateSprite(&sSpriteTemplate_FlyingPidgey, -32, sFlyingPidgeyBaseY, 1);
        if (spriteId != MAX_SPRITES)
        {
            struct Sprite *sprite = &gSprites[spriteId];
            sprite->coordOffsetEnabled = FALSE;
            sprite->data[0] = i;
            sprite->invisible = TRUE;
            SeekSpriteAnim(sprite, sPidgeyFlockOffsets[i].animOffset);
            sFlyingPidgeySpriteIds[i] = spriteId;
        }
        else
        {
            sFlyingPidgeySpriteIds[i] = MAX_SPRITES;
        }
    }
}

static void DestroyFlyingPidgey(void)
{
    u8 i;

    if (!sFlyingPidgeyActive)
        return;

    for (i = 0; i < NUM_FLYING_PIDGEY; i++)
    {
        if (sFlyingPidgeySpriteIds[i] != MAX_SPRITES)
        {
            DestroySprite(&gSprites[sFlyingPidgeySpriteIds[i]]);
            sFlyingPidgeySpriteIds[i] = MAX_SPRITES;
        }
    }

    if (!sTreePidgeyActive)
    {
        FreeSpriteTilesByTag(FLDEFF_TILE_TAG_FLYING_PIDGEY);
        FreeSpritePaletteByTag(FLDEFF_PAL_TAG_FLYING_PIDGEY);
    }
    sFlyingPidgeyActive = FALSE;
    sFlyingPidgeyFlockCooldown = 0;
}

enum {
    GROUND_PIDGEY_STATE_PECKING,
    GROUND_PIDGEY_STATE_HOP_DELAY,
    GROUND_PIDGEY_STATE_HOPPING,
    GROUND_PIDGEY_STATE_FLY_AWAY_DELAY,
    GROUND_PIDGEY_STATE_FLYING_TO_TREE,
    GROUND_PIDGEY_STATE_TREE_PERCHED,
    GROUND_PIDGEY_STATE_FLYING_TO_GROUND,
};

#define NUM_TREE_PIDGEY 3

struct TreeBranchOffset {
    s16 x;
    s16 y;
};

static const struct TreeBranchOffset sTreeBranchOffsets[NUM_TREE_PIDGEY] = {
    { -6,  2 }, // Left branch
    {  6, -2 }, // Right branch
    {  0,  7 }, // Center/lower branch
};

static EWRAM_DATA u8 sTreePidgeySpriteIds[NUM_TREE_PIDGEY] = {0};
static EWRAM_DATA s16 sGroundPidgeyTileX[NUM_TREE_PIDGEY] = {0};
static EWRAM_DATA s16 sGroundPidgeyTileY[NUM_TREE_PIDGEY] = {0};
static EWRAM_DATA s16 sGroundPidgeyHomeX[NUM_TREE_PIDGEY] = {0};
static EWRAM_DATA s16 sGroundPidgeyHomeY[NUM_TREE_PIDGEY] = {0};
static EWRAM_DATA u8 sPidgeyTargetTree = 0; // 0 = Tree A (West), 1 = Tree B (East)

// Feeding-spot tile coords, taken from the LIGHT_TYPE_TREE_PIDGEY table entry.
static EWRAM_DATA s16 sTreePidgeyAnchorX = 0;
static EWRAM_DATA s16 sTreePidgeyAnchorY = 0;

// All Tree Pidgey geometry is expressed relative to that anchor. These used to
// be hardcoded Route 8 literals while the table entry's x/y went unread, so a
// second LIGHT_TYPE_TREE_PIDGEY entry on any other map would have spawned its
// birds on Route 8's tiles and flown them to Route 8's trees. With Route 8's
// anchor of (24, 4) each of these resolves to exactly the old literal value,
// so Route 8 behaviour is unchanged.
#define TREE_PIDGEY_ROAM_MIN_X  (sTreePidgeyAnchorX - 3) // was 21
#define TREE_PIDGEY_ROAM_MAX_X  (sTreePidgeyAnchorX + 3) // was 27
#define TREE_PIDGEY_ROAM_MIN_Y  (sTreePidgeyAnchorY - 1) // was 3
#define TREE_PIDGEY_ROAM_MAX_Y  (sTreePidgeyAnchorY + 1) // was 5
#define TREE_PIDGEY_TREE_A_X    (sTreePidgeyAnchorX - 5) // was 19
#define TREE_PIDGEY_TREE_B_X    (sTreePidgeyAnchorX + 4) // was 28
#define TREE_PIDGEY_TREE_Y      (sTreePidgeyAnchorY - 3) // was 1

static void TriggerPidgeyFlyAway(s16 playerTileX)
{
    u8 i;
    // If player approaches from west of the feeding spot, fly East to Tree B.
    // If player approaches from east of it, fly West to Tree A.
    sPidgeyTargetTree = (playerTileX <= sTreePidgeyAnchorX) ? 1 : 0;

    for (i = 0; i < NUM_TREE_PIDGEY; i++)
    {
        if (sTreePidgeySpriteIds[i] != MAX_SPRITES)
        {
            struct Sprite *sprite = &gSprites[sTreePidgeySpriteIds[i]];
            if (sprite->data[0] == GROUND_PIDGEY_STATE_PECKING
             || sprite->data[0] == GROUND_PIDGEY_STATE_HOPPING
             || sprite->data[0] == GROUND_PIDGEY_STATE_HOP_DELAY)
            {
                sprite->y2 = 0;
                sprite->data[0] = GROUND_PIDGEY_STATE_FLY_AWAY_DELAY;
                sprite->data[2] = i * 10; // Stagger: 0, 10, 20 frames
                sprite->hFlip = (sPidgeyTargetTree == 0); // Face West if flying to Tree A
            }
        }
    }
}

static void TriggerPidgeyHop(s16 playerTileX, s16 playerTileY)
{
    u8 i;

    for (i = 0; i < NUM_TREE_PIDGEY; i++)
    {
        if (sTreePidgeySpriteIds[i] != MAX_SPRITES)
        {
            struct Sprite *sprite = &gSprites[sTreePidgeySpriteIds[i]];
            if (sprite->data[0] == GROUND_PIDGEY_STATE_PECKING)
            {
                s16 hopTilesX = 2;
                s16 targetX, targetY;

                // Move horizontally away from player
                if (playerTileX <= sGroundPidgeyTileX[i])
                {
                    targetX = sGroundPidgeyTileX[i] + hopTilesX;
                    if (targetX > TREE_PIDGEY_ROAM_MAX_X)
                        targetX = sGroundPidgeyTileX[i] - hopTilesX;
                }
                else
                {
                    targetX = sGroundPidgeyTileX[i] - hopTilesX;
                    if (targetX < TREE_PIDGEY_ROAM_MIN_X)
                        targetX = sGroundPidgeyTileX[i] + hopTilesX;
                }

                // Move slightly on Y, staying within the roaming band
                targetY = sGroundPidgeyTileY[i];
                if (playerTileY >= sGroundPidgeyTileY[i])
                {
                    if (targetY > TREE_PIDGEY_ROAM_MIN_Y)
                        targetY--;
                }
                else
                {
                    if (targetY < TREE_PIDGEY_ROAM_MAX_Y)
                        targetY++;
                }

                sprite->data[0] = GROUND_PIDGEY_STATE_HOP_DELAY;
                sprite->data[2] = i * 4; // Stagger: 0, 4, 8 frames
                sprite->data[4] = sprite->x; // Start X
                sprite->data[5] = (targetX - sGroundPidgeyTileX[i]) * 16; // Delta X
                sprite->data[6] = sprite->y; // Start Y
                sprite->data[7] = (targetY - sGroundPidgeyTileY[i]) * 16; // Delta Y
                sprite->hFlip = (sprite->data[5] < 0); // Face West if hopping left
            }
        }
    }
}

static void SpriteCallback_TreePidgey(struct Sprite *sprite)
{
    u8 birdIdx = sprite->data[3];

    switch (sprite->data[0])
    {
    case GROUND_PIDGEY_STATE_PECKING:
        {
            s16 px, py;
            PlayerGetDestCoords(&px, &py);
            s16 playerTileX = px - MAP_OFFSET;
            s16 playerTileY = py - MAP_OFFSET;

            s16 dx = playerTileX - sGroundPidgeyTileX[birdIdx];
            s16 dy = playerTileY - sGroundPidgeyTileY[birdIdx];
            s16 distSq = dx * dx + dy * dy;

            // Running or biking: panic and fly away from up to 4.5 tiles away
            if ((gPlayerAvatar.dashing || IsPlayerBiking()) && distSq <= 20)
            {
                TriggerPidgeyFlyAway(playerTileX);
            }
            // Walking: scatter/hop a few spaces over when within 2 tiles
            else if (distSq <= 4)
            {
                TriggerPidgeyHop(playerTileX, playerTileY);
            }
        }
        break;

    case GROUND_PIDGEY_STATE_HOP_DELAY:
        if (sprite->data[2] > 0)
        {
            sprite->data[2]--;
            return;
        }
        StartSpriteAnim(sprite, PIDGEY_ANIM_FLYING);
        sprite->data[0] = GROUND_PIDGEY_STATE_HOPPING;
        sprite->data[1] = 0; // progress: 0..16
        break;

    case GROUND_PIDGEY_STATE_HOPPING:
        sprite->data[1]++;
        {
            u8 progress = sprite->data[1];
            sprite->x = sprite->data[4] + (sprite->data[5] * progress) / 16;
            sprite->y = sprite->data[6] + (sprite->data[7] * progress) / 16;
            // 10 px hop arc
            sprite->y2 = -((gSineTable[(progress * 128) / 16] * 10) >> 8);

            if (progress >= 16)
            {
                sprite->x = sprite->data[4] + sprite->data[5];
                sprite->y = sprite->data[6] + sprite->data[7];
                sprite->y2 = 0;
                sGroundPidgeyTileX[birdIdx] += sprite->data[5] / 16;
                sGroundPidgeyTileY[birdIdx] += sprite->data[7] / 16;
                StartSpriteAnim(sprite, PIDGEY_ANIM_PERCHED);
                SeekSpriteAnim(sprite, birdIdx * 2);
                sprite->data[0] = GROUND_PIDGEY_STATE_PECKING;
            }
        }
        break;

    case GROUND_PIDGEY_STATE_FLY_AWAY_DELAY:
        if (sprite->data[2] > 0)
        {
            sprite->data[2]--;
            return;
        }
        StartSpriteAnim(sprite, PIDGEY_ANIM_FLYING);
        sprite->data[0] = GROUND_PIDGEY_STATE_FLYING_TO_TREE;
        sprite->data[1] = 0; // progress 0..48
        sprite->data[4] = sprite->x; // Start flight X
        sprite->data[6] = sprite->y; // Start flight Y
        // Calculate destination X & Y on tree branches
        {
            s16 treeBaseX, treeBaseY;
            if (sPidgeyTargetTree == 0)
                treeBaseX = TREE_PIDGEY_TREE_A_X + MAP_OFFSET;
            else
                treeBaseX = TREE_PIDGEY_TREE_B_X + MAP_OFFSET;
            treeBaseY = TREE_PIDGEY_TREE_Y + MAP_OFFSET;
            SetSpritePosToOffsetMapCoords(&treeBaseX, &treeBaseY, 0, 0);
            s16 destX = treeBaseX + sTreeBranchOffsets[birdIdx].x;
            s16 destY = treeBaseY + 4 + sTreeBranchOffsets[birdIdx].y;
            sprite->data[5] = destX - sprite->data[4]; // Delta X
            sprite->data[7] = destY - sprite->data[6]; // Delta Y
        }
        break;

    case GROUND_PIDGEY_STATE_FLYING_TO_TREE:
        sprite->data[1]++;
        {
            u8 progress = sprite->data[1];
            sprite->x = sprite->data[4] + (sprite->data[5] * progress) / 48;
            sprite->y = sprite->data[6] + (sprite->data[7] * progress) / 48;
            // Swoop up into the tree canopy (24 px height arc)
            sprite->y2 = -((gSineTable[(progress * 128) / 48] * 24) >> 8);

            if (progress >= 36)
                StartSpriteAnimIfDifferent(sprite, PIDGEY_ANIM_GLIDE);

            if (progress >= 48)
            {
                sprite->x = sprite->data[4] + sprite->data[5];
                sprite->y = sprite->data[6] + sprite->data[7];
                sprite->y2 = 0;
                StartSpriteAnim(sprite, PIDGEY_ANIM_PERCHED);
                SeekSpriteAnim(sprite, birdIdx * 2);
                sprite->data[0] = GROUND_PIDGEY_STATE_TREE_PERCHED;
                sprite->data[1] = 720 + (birdIdx * 60); // ~12 to 14 seconds rest in tree
            }
        }
        break;

    case GROUND_PIDGEY_STATE_TREE_PERCHED:
        if (sprite->data[1] > 0)
        {
            sprite->data[1]--;
            // Bird 0 coordinates the return flight
            if (birdIdx == 0 && sprite->data[1] == 0)
            {
                s16 px, py;
                PlayerGetDestCoords(&px, &py);
                s16 playerTileX = px - MAP_OFFSET;
                s16 playerTileY = py - MAP_OFFSET;

                // If player is still right at the ground feeding spot, delay return
                if (playerTileX >= sTreePidgeyAnchorX - 2 && playerTileX <= sTreePidgeyAnchorX + 3
                 && playerTileY >= sTreePidgeyAnchorY - 1 && playerTileY <= sTreePidgeyAnchorY + 2)
                {
                    sprite->data[1] = 120; // Check again in 2 seconds
                    return;
                }

                // Trigger return flight for all birds
                u8 j;
                for (j = 0; j < NUM_TREE_PIDGEY; j++)
                {
                    if (sTreePidgeySpriteIds[j] != MAX_SPRITES)
                    {
                        struct Sprite *bird = &gSprites[sTreePidgeySpriteIds[j]];
                        if (bird->data[0] == GROUND_PIDGEY_STATE_TREE_PERCHED)
                        {
                            bird->data[0] = GROUND_PIDGEY_STATE_FLYING_TO_GROUND;
                            bird->data[1] = 0;
                            bird->data[4] = bird->x;
                            bird->data[6] = bird->y;
                            bird->data[5] = sGroundPidgeyHomeX[j] - bird->x;
                            bird->data[7] = sGroundPidgeyHomeY[j] - bird->y;
                            bird->hFlip = (bird->data[5] < 0);
                            StartSpriteAnim(bird, PIDGEY_ANIM_FLYING);
                        }
                    }
                }
            }
        }
        break;

    case GROUND_PIDGEY_STATE_FLYING_TO_GROUND:
        sprite->data[1]++;
        {
            u8 progress = sprite->data[1];
            sprite->x = sprite->data[4] + (sprite->data[5] * progress) / 48;
            sprite->y = sprite->data[6] + (sprite->data[7] * progress) / 48;
            sprite->y2 = -((gSineTable[(progress * 128) / 48] * 16) >> 8);

            if (progress >= 36)
                StartSpriteAnimIfDifferent(sprite, PIDGEY_ANIM_GLIDE);

            if (progress >= 48)
            {
                sprite->x = sGroundPidgeyHomeX[birdIdx];
                sprite->y = sGroundPidgeyHomeY[birdIdx];
                sprite->y2 = 0;
                sprite->hFlip = FALSE;
                sGroundPidgeyTileX[birdIdx] = sTreePidgeyAnchorX + ((birdIdx == 1) ? 1 : 0);
                sGroundPidgeyTileY[birdIdx] = sTreePidgeyAnchorY + ((birdIdx == 2) ? 1 : 0);
                StartSpriteAnim(sprite, PIDGEY_ANIM_PERCHED);
                SeekSpriteAnim(sprite, birdIdx * 2);
                sprite->data[0] = GROUND_PIDGEY_STATE_PECKING;
            }
        }
        break;
    }

    // Off-screen culling: prevents GBA 9-bit OAM wrapping (modulo 512px / 32 tiles) on wide maps
    {
        s16 screenX = sprite->x + sprite->x2 + sprite->centerToCornerVecX + gSpriteCoordOffsetX;
        s16 screenY = sprite->y + sprite->y2 + sprite->centerToCornerVecY + gSpriteCoordOffsetY;

        if (screenX <= -32 || screenX >= DISPLAY_WIDTH || screenY <= -32 || screenY >= DISPLAY_HEIGHT)
            sprite->invisible = TRUE;
        else
            sprite->invisible = FALSE;
    }
}

static bool8 MapHasTreePidgey(u8 mapGroup, u8 mapNum)
{
    u32 i;
    for (i = 0; i < ARRAY_COUNT(sMapLightSources); i++)
    {
        if (sMapLightSources[i].mapGroup == mapGroup && sMapLightSources[i].mapNum == mapNum)
        {
            if (sMapLightSources[i].type == LIGHT_TYPE_TREE_PIDGEY)
                return TRUE;
        }
    }
    return FALSE;
}

static void SpawnTreePidgey(void)
{
    u8 i;
    u32 entry;
    s16 baseX, baseY;
    u8 mapGroup = gSaveBlock1Ptr->location.mapGroup;
    u8 mapNum = gSaveBlock1Ptr->location.mapNum;

    static const struct TreeBranchOffset sGroundOffsets[NUM_TREE_PIDGEY] = {
        { -4,  2 }, // Bird 0: anchor tile      (-4, +2)
        { 18, -2 }, // Bird 1: anchor tile +1X  (+18, -2)
        {  6, 14 }, // Bird 2: anchor tile +1Y  (+6, +14)
    };

    if (sTreePidgeyActive)
        return;

    // Take the feeding spot from this map's table entry rather than assuming
    // Route 8's tiles. Every other coordinate in the Tree Pidgey behaviour is
    // derived from this anchor (see the TREE_PIDGEY_* macros above).
    sTreePidgeyAnchorX = 24;
    sTreePidgeyAnchorY = 4;
    for (entry = 0; entry < ARRAY_COUNT(sMapLightSources); entry++)
    {
        if (sMapLightSources[entry].mapGroup == mapGroup
         && sMapLightSources[entry].mapNum == mapNum
         && sMapLightSources[entry].type == LIGHT_TYPE_TREE_PIDGEY)
        {
            sTreePidgeyAnchorX = sMapLightSources[entry].x;
            sTreePidgeyAnchorY = sMapLightSources[entry].y;
            break;
        }
    }

    if (GetSpriteTileStartByTag(FLDEFF_TILE_TAG_FLYING_PIDGEY) == 0xFFFF)
        LoadSpriteSheet(&sSpriteSheet_FlyingPidgey);
    {
        u8 palIndex = IndexOfSpritePaletteTag(FLDEFF_PAL_TAG_FLYING_PIDGEY);
        if (palIndex == 0xFF)
            FieldEffectScript_LoadFadedPal(&sSpritePalette_FlyingPidgey);
        else
            UpdateSpritePaletteWithWeather(palIndex, TRUE);
    }

    sTreePidgeyActive = TRUE;

    baseX = sTreePidgeyAnchorX + MAP_OFFSET;
    baseY = sTreePidgeyAnchorY + MAP_OFFSET;
    SetSpritePosToOffsetMapCoords(&baseX, &baseY, 0, 0);

    for (i = 0; i < NUM_TREE_PIDGEY; i++)
        sTreePidgeySpriteIds[i] = MAX_SPRITES;

    sGroundPidgeyTileX[0] = sTreePidgeyAnchorX;     sGroundPidgeyTileY[0] = sTreePidgeyAnchorY;
    sGroundPidgeyTileX[1] = sTreePidgeyAnchorX + 1; sGroundPidgeyTileY[1] = sTreePidgeyAnchorY;
    sGroundPidgeyTileX[2] = sTreePidgeyAnchorX;     sGroundPidgeyTileY[2] = sTreePidgeyAnchorY + 1;

    for (i = 0; i < NUM_TREE_PIDGEY; i++)
    {
        s16 startX = baseX + sGroundOffsets[i].x;
        s16 startY = baseY + sGroundOffsets[i].y;

        u8 spriteId = CreateSprite(&sSpriteTemplate_TreePidgey, startX, startY, 1);
        if (spriteId != MAX_SPRITES)
        {
            struct Sprite *sprite = &gSprites[spriteId];
            sprite->coordOffsetEnabled = TRUE;
            sprite->data[0] = GROUND_PIDGEY_STATE_PECKING;
            sprite->data[1] = 0;
            sprite->data[2] = 0;
            sprite->data[3] = i;
            sprite->data[4] = startX;
            sprite->data[5] = 0;
            sprite->data[6] = startY;
            sprite->data[7] = 0;
            sGroundPidgeyHomeX[i] = startX;
            sGroundPidgeyHomeY[i] = startY;
            StartSpriteAnim(sprite, PIDGEY_ANIM_PERCHED);
            SeekSpriteAnim(sprite, i * 2);
            sTreePidgeySpriteIds[i] = spriteId;
        }
        else
        {
            sTreePidgeySpriteIds[i] = MAX_SPRITES;
        }
    }
}

static void DestroyTreePidgey(void)
{
    u8 i;

    if (!sTreePidgeyActive)
        return;

    for (i = 0; i < NUM_TREE_PIDGEY; i++)
    {
        if (sTreePidgeySpriteIds[i] != MAX_SPRITES)
        {
            DestroySprite(&gSprites[sTreePidgeySpriteIds[i]]);
            sTreePidgeySpriteIds[i] = MAX_SPRITES;
        }
    }

    if (!sFlyingPidgeyActive)
    {
        FreeSpriteTilesByTag(FLDEFF_TILE_TAG_FLYING_PIDGEY);
        FreeSpritePaletteByTag(FLDEFF_PAL_TAG_FLYING_PIDGEY);
    }
    sTreePidgeyActive = FALSE;
}

enum {
    MAGIKARP_STATE_SUBMERGED,
    MAGIKARP_STATE_LEAP,
    MAGIKARP_STATE_APEX,
    MAGIKARP_STATE_DIVE,
};

#define MAX_MAGIKARP_SPLASH 4
static EWRAM_DATA u8 sMagikarpSplashSpriteIds[MAX_MAGIKARP_SPLASH] = {0};
static EWRAM_DATA bool8 sMagikarpSplashActive = FALSE;

static void SpriteCallback_MagikarpSplash(struct Sprite *sprite)
{
    s16 screenX = sprite->x + sprite->x2 + sprite->centerToCornerVecX + gSpriteCoordOffsetX;
    s16 screenY = sprite->y + sprite->y2 + sprite->centerToCornerVecY + gSpriteCoordOffsetY;
    bool8 onScreen = (screenX >= -32 && screenX <= DISPLAY_WIDTH + 32 && screenY >= -32 && screenY <= DISPLAY_HEIGHT + 32);

    // Culling check: strictly enforce invisibility if submerged or off-screen
    if (!onScreen || sprite->data[0] == MAGIKARP_STATE_SUBMERGED)
        sprite->invisible = TRUE;

    switch (sprite->data[0])
    {
    case MAGIKARP_STATE_SUBMERGED:
        sprite->invisible = TRUE;
        sprite->x = sprite->data[5];
        sprite->y = sprite->data[6];
        sprite->y2 = 0;

        if (sprite->data[1] > 0)
        {
            sprite->data[1]--;

            // Telegraph: 20 frames before leaping, create a ripple and water sound if on screen
            if (sprite->data[1] == 20 && onScreen)
            {
                gFieldEffectArguments[0] = sprite->x;
                gFieldEffectArguments[1] = sprite->y + 4;
                gFieldEffectArguments[2] = 151;
                gFieldEffectArguments[3] = 2;
                FieldEffectStart(FLDEFF_RIPPLE);
                PlaySE(SE_PUDDLE);
            }

            if (sprite->data[1] == 0)
            {
                if (!onScreen)
                {
                    // Delay jump until player is near the pond
                    sprite->data[1] = 60 + (Random() % 60);
                    return;
                }

                gFieldEffectArguments[0] = sprite->data[3] + MAP_OFFSET;
                gFieldEffectArguments[1] = sprite->data[4] + MAP_OFFSET;
                gFieldEffectArguments[2] = 151;
                gFieldEffectArguments[3] = 2;
                FieldEffectStart(FLDEFF_JUMP_BIG_SPLASH);
                PlaySE(SE_PUDDLE);

                sprite->invisible = FALSE;
                sprite->hFlip = (Random() & 1);
                sprite->data[7] = sprite->hFlip ? 1 : -1; // Drift right if facing right, left if facing left
                StartSpriteAnim(sprite, MAGIKARP_ANIM_LEAP);
                sprite->data[0] = MAGIKARP_STATE_LEAP;
                sprite->data[1] = 0;
            }
        }
        break;

    case MAGIKARP_STATE_LEAP:
        sprite->data[1]++;
        {
            u8 progress = sprite->data[1]; // 1 to 16
            u8 angle = (progress * 64) / 16; // 0 to 64 (sine 0 to 256)
            s16 arcY = -((gSineTable[angle] * 24) >> 8); // Rise 24 pixels
            s16 driftX = (sprite->data[7] * 6 * progress) / 16; // Drift up to 6 pixels

            sprite->x = sprite->data[5] + driftX;
            sprite->y = sprite->data[6] + arcY;

            if (onScreen)
                sprite->invisible = FALSE;

            if (progress >= 16)
            {
                StartSpriteAnim(sprite, MAGIKARP_ANIM_FLAIL);
                sprite->data[0] = MAGIKARP_STATE_APEX;
                sprite->data[1] = 0;
            }
        }
        break;

    case MAGIKARP_STATE_APEX:
        sprite->data[1]++;
        {
            u8 apexTimer = sprite->data[1]; // 1 to 8
            // Flail at apex with slight bobbing
            sprite->y2 = ((apexTimer & 2) ? 1 : -1);

            if (onScreen)
                sprite->invisible = FALSE;

            if (apexTimer >= 8)
            {
                sprite->y2 = 0;
                StartSpriteAnim(sprite, MAGIKARP_ANIM_DIVE);
                sprite->data[0] = MAGIKARP_STATE_DIVE;
                sprite->data[1] = 0;
            }
        }
        break;

    case MAGIKARP_STATE_DIVE:
        sprite->data[1]++;
        {
            u8 progress = sprite->data[1]; // 1 to 16
            u8 angle = 64 + (progress * 64) / 16; // 64 to 128 (sine 256 to 0)
            s16 arcY = -((gSineTable[angle] * 24) >> 8); // Fall back down to surface
            s16 driftX = sprite->data[7] * (6 + (progress * 4) / 16); // Drift another 4 pixels (total 10)

            sprite->x = sprite->data[5] + driftX;
            sprite->y = sprite->data[6] + arcY;

            if (onScreen)
                sprite->invisible = FALSE;

            if (progress >= 16)
            {
                sprite->invisible = TRUE;
                sprite->x = sprite->data[5];
                sprite->y = sprite->data[6];
                sprite->y2 = 0;

                if (onScreen)
                {
                    gFieldEffectArguments[0] = sprite->data[3] + MAP_OFFSET;
                    gFieldEffectArguments[1] = sprite->data[4] + MAP_OFFSET;
                    gFieldEffectArguments[2] = 151;
                    gFieldEffectArguments[3] = 2;
                    FieldEffectStart(FLDEFF_JUMP_BIG_SPLASH);

                    gFieldEffectArguments[0] = sprite->x;
                    gFieldEffectArguments[1] = sprite->y + 4;
                    gFieldEffectArguments[2] = 151;
                    gFieldEffectArguments[3] = 2;
                    FieldEffectStart(FLDEFF_RIPPLE);

                    PlaySE(SE_PUDDLE);
                }

                sprite->data[0] = MAGIKARP_STATE_SUBMERGED;
                // 30% chance for rapid second flop
                if ((Random() % 100) < 30)
                    sprite->data[1] = 30 + (Random() % 30); // Quick follow-up flop in ~0.5 - 1 sec
                else
                    sprite->data[1] = 240 + (Random() % 240); // 4 - 8 seconds cooldown
            }
        }
        break;
    }
}

static bool8 MapHasMagikarpSplash(u8 mapGroup, u8 mapNum)
{
    u32 i;
    for (i = 0; i < ARRAY_COUNT(sMapLightSources); i++)
    {
        if (sMapLightSources[i].mapGroup == mapGroup && sMapLightSources[i].mapNum == mapNum)
        {
            if (sMapLightSources[i].type == LIGHT_TYPE_MAGIKARP_SPLASH)
                return TRUE;
        }
    }
    return FALSE;
}

static void SpawnMagikarpSplash(void)
{
    u8 mapGroup = gSaveBlock1Ptr->location.mapGroup;
    u8 mapNum = gSaveBlock1Ptr->location.mapNum;
    u32 i;
    u8 count = 0;

    if (sMagikarpSplashActive)
        return;

    if (GetSpriteTileStartByTag(FLDEFF_TILE_TAG_MAGIKARP_SPLASH) == 0xFFFF)
        LoadSpriteSheet(&sSpriteSheet_MagikarpSplash);
    {
        u8 palIndex = IndexOfSpritePaletteTag(FLDEFF_PAL_TAG_MAGIKARP_SPLASH);
        if (palIndex == 0xFF)
            FieldEffectScript_LoadFadedPal(&sSpritePalette_MagikarpSplash);
        else
            UpdateSpritePaletteWithWeather(palIndex, TRUE);
    }

    for (i = 0; i < MAX_MAGIKARP_SPLASH; i++)
        sMagikarpSplashSpriteIds[i] = MAX_SPRITES;

    for (i = 0; i < ARRAY_COUNT(sMapLightSources) && count < MAX_MAGIKARP_SPLASH; i++)
    {
        if (sMapLightSources[i].mapGroup == mapGroup && sMapLightSources[i].mapNum == mapNum)
        {
            if (sMapLightSources[i].type == LIGHT_TYPE_MAGIKARP_SPLASH)
            {
                s16 baseX = sMapLightSources[i].x + MAP_OFFSET;
                s16 baseY = sMapLightSources[i].y + MAP_OFFSET;
                SetSpritePosToOffsetMapCoords(&baseX, &baseY, 8, 8);

                u8 spriteId = CreateSprite(&sSpriteTemplate_MagikarpSplash, baseX, baseY, 2);
                if (spriteId != MAX_SPRITES)
                {
                    struct Sprite *sprite = &gSprites[spriteId];
                    sprite->coordOffsetEnabled = TRUE;
                    sprite->invisible = TRUE;
                    sprite->data[0] = MAGIKARP_STATE_SUBMERGED;
                    // Stagger initial jumps so all Magikarp don't jump simultaneously
                    sprite->data[1] = 60 + count * 150 + (Random() % 120);
                    sprite->data[2] = 0;
                    sprite->data[3] = sMapLightSources[i].x;
                    sprite->data[4] = sMapLightSources[i].y;
                    sprite->data[5] = baseX;
                    sprite->data[6] = baseY;
                    sprite->data[7] = 0;

                    sMagikarpSplashSpriteIds[count++] = spriteId;
                }
            }
        }
    }

    if (count > 0)
        sMagikarpSplashActive = TRUE;
}

static void DestroyMagikarpSplash(void)
{
    u8 i;

    if (!sMagikarpSplashActive)
        return;

    for (i = 0; i < MAX_MAGIKARP_SPLASH; i++)
    {
        if (sMagikarpSplashSpriteIds[i] != MAX_SPRITES)
        {
            DestroySprite(&gSprites[sMagikarpSplashSpriteIds[i]]);
            sMagikarpSplashSpriteIds[i] = MAX_SPRITES;
        }
    }

    FreeSpriteTilesByTag(FLDEFF_TILE_TAG_MAGIKARP_SPLASH);
    FreeSpritePaletteByTag(FLDEFF_PAL_TAG_MAGIKARP_SPLASH);
    sMagikarpSplashActive = FALSE;
}

enum {
    WINGULL_STATE_COOLDOWN,
    WINGULL_STATE_SWOOP_IN,
    WINGULL_STATE_SKIM,
    WINGULL_STATE_CLIMB_OUT,
};

#define MAX_WINGULL_SKIM 2
static EWRAM_DATA u8 sWingullSkimSpriteIds[MAX_WINGULL_SKIM] = {0};
static EWRAM_DATA bool8 sWingullSkimActive = FALSE;

static void SpriteCallback_WingullSkim(struct Sprite *sprite)
{
    s16 screenX = sprite->x + sprite->x2 + sprite->centerToCornerVecX + gSpriteCoordOffsetX;
    s16 screenY = sprite->y + sprite->y2 + sprite->centerToCornerVecY + gSpriteCoordOffsetY;
    bool8 onScreen = (screenX >= -32 && screenX <= DISPLAY_WIDTH + 32 && screenY >= -32 && screenY <= DISPLAY_HEIGHT + 32);

    // Culling check: strictly enforce invisibility if in cooldown or off-screen
    if (!onScreen || sprite->data[0] == WINGULL_STATE_COOLDOWN)
        sprite->invisible = TRUE;

    switch (sprite->data[0])
    {
    case WINGULL_STATE_COOLDOWN:
        sprite->invisible = TRUE;
        sprite->x = sprite->data[4];
        sprite->y = sprite->data[5];
        sprite->x2 = 0;
        sprite->y2 = 0;

        if (sprite->data[1] > 0)
        {
            sprite->data[1]--;
            if (sprite->data[1] == 0)
            {
                if (!onScreen)
                {
                    // Delay flight until player is near the skimming spot
                    sprite->data[1] = 60 + (Random() % 60);
                    return;
                }

                // Spawns 48px East and 36px North (over open ocean, high in air)
                sprite->x = sprite->data[4] + 48;
                sprite->y = sprite->data[5] - 36;
                sprite->invisible = FALSE;
                sprite->hFlip = FALSE; // Facing West toward pier
                StartSpriteAnim(sprite, WINGULL_ANIM_GLIDE);
                sprite->data[0] = WINGULL_STATE_SWOOP_IN;
                sprite->data[1] = 0;
            }
        }
        break;

    case WINGULL_STATE_SWOOP_IN:
        sprite->data[1]++;
        {
            u8 progress = sprite->data[1]; // 1 to 32
            // Linear descent on X from (baseX + 48) to baseX
            sprite->x = (sprite->data[4] + 48) - (48 * progress) / 32;
            // Smooth curved descent on Y from (baseY - 36) down to baseY
            s16 altRemain = 32 - progress;
            sprite->y = sprite->data[5] - (36 * altRemain * altRemain) / (32 * 32);

            if (onScreen)
                sprite->invisible = FALSE;

            if (progress == 8)
                PlayCry_Normal(SPECIES_WINGULL, 0);

            if (progress >= 32)
            {
                sprite->x = sprite->data[4];
                sprite->y = sprite->data[5];
                StartSpriteAnim(sprite, WINGULL_ANIM_SKIM);
                sprite->data[0] = WINGULL_STATE_SKIM;
                sprite->data[1] = 0;
            }
        }
        break;

    case WINGULL_STATE_SKIM:
        sprite->data[1]++;
        {
            u8 progress = sprite->data[1]; // 1 to 20
            // Skim horizontally across the water for 16 pixels
            sprite->x = sprite->data[4] - (16 * progress) / 20;
            sprite->y = sprite->data[5] + ((progress & 4) ? 1 : 0);

            if (onScreen)
                sprite->invisible = FALSE;

            if (progress == 1 || progress == 10)
            {
                if (onScreen)
                {
                    gFieldEffectArguments[0] = sprite->x;
                    gFieldEffectArguments[1] = sprite->y + 8;
                    gFieldEffectArguments[2] = 151;
                    gFieldEffectArguments[3] = 2;
                    FieldEffectStart(FLDEFF_RIPPLE);
                    PlaySE(SE_PUDDLE);
                }
            }

            if (progress >= 20)
            {
                StartSpriteAnim(sprite, WINGULL_ANIM_FLAP);
                sprite->hFlip = FALSE; // Continue facing West (Left)
                sprite->data[0] = WINGULL_STATE_CLIMB_OUT;
                sprite->data[1] = 0;
            }
        }
        break;

    case WINGULL_STATE_CLIMB_OUT:
        sprite->data[1]++;
        {
            u16 progress = sprite->data[1];
            // Fly West at a steady pace
            sprite->x = (sprite->data[4] - 16) - progress * 2;
            // Gentle upward climb (less of an arc so it exits off the left edge, not the top)
            sprite->y = sprite->data[5] - (progress / 2);

            s16 curScreenX = sprite->x + sprite->centerToCornerVecX + gSpriteCoordOffsetX;

            if (onScreen)
                sprite->invisible = FALSE;

            // Fly all the way off the left edge of the screen before entering cooldown
            if (curScreenX < -32 || progress >= 200)
            {
                sprite->invisible = TRUE;
                sprite->x = sprite->data[4];
                sprite->y = sprite->data[5];
                sprite->data[0] = WINGULL_STATE_COOLDOWN;
                sprite->data[1] = 240 + (Random() % 240); // 4 - 8 seconds cooldown
            }
        }
        break;
    }
}

static bool8 MapHasWingullSkim(u8 mapGroup, u8 mapNum)
{
    u32 i;
    for (i = 0; i < ARRAY_COUNT(sMapLightSources); i++)
    {
        if (sMapLightSources[i].mapGroup == mapGroup && sMapLightSources[i].mapNum == mapNum)
        {
            if (sMapLightSources[i].type == LIGHT_TYPE_WINGULL_SKIM)
                return TRUE;
        }
    }
    return FALSE;
}

static void SpawnWingullSkim(void)
{
    u8 mapGroup = gSaveBlock1Ptr->location.mapGroup;
    u8 mapNum = gSaveBlock1Ptr->location.mapNum;
    u32 i;
    u8 count = 0;

    if (sWingullSkimActive)
        return;

    if (GetSpriteTileStartByTag(FLDEFF_TILE_TAG_WINGULL_SKIM) == 0xFFFF)
        LoadSpriteSheet(&sSpriteSheet_WingullSkim);
    {
        u8 palIndex = IndexOfSpritePaletteTag(FLDEFF_PAL_TAG_WINGULL_SKIM);
        if (palIndex == 0xFF)
            FieldEffectScript_LoadFadedPal(&sSpritePalette_WingullSkim);
        else
            UpdateSpritePaletteWithWeather(palIndex, TRUE);
    }

    for (i = 0; i < MAX_WINGULL_SKIM; i++)
        sWingullSkimSpriteIds[i] = MAX_SPRITES;

    for (i = 0; i < ARRAY_COUNT(sMapLightSources) && count < MAX_WINGULL_SKIM; i++)
    {
        if (sMapLightSources[i].mapGroup == mapGroup && sMapLightSources[i].mapNum == mapNum)
        {
            if (sMapLightSources[i].type == LIGHT_TYPE_WINGULL_SKIM)
            {
                s16 baseX = sMapLightSources[i].x + MAP_OFFSET;
                s16 baseY = sMapLightSources[i].y + MAP_OFFSET;
                SetSpritePosToOffsetMapCoords(&baseX, &baseY, 8, 8);

                u8 spriteId = CreateSprite(&sSpriteTemplate_WingullSkim, baseX, baseY, 2);
                if (spriteId != MAX_SPRITES)
                {
                    struct Sprite *sprite = &gSprites[spriteId];
                    sprite->coordOffsetEnabled = TRUE;
                    sprite->invisible = TRUE;
                    sprite->data[0] = WINGULL_STATE_COOLDOWN;
                    sprite->data[1] = 60 + count * 150 + (Random() % 120);
                    sprite->data[2] = sMapLightSources[i].x;
                    sprite->data[3] = sMapLightSources[i].y;
                    sprite->data[4] = baseX;
                    sprite->data[5] = baseY;
                    sprite->data[6] = 0;
                    sprite->data[7] = 0;

                    sWingullSkimSpriteIds[count++] = spriteId;
                }
            }
        }
    }

    if (count > 0)
        sWingullSkimActive = TRUE;
}

static void DestroyWingullSkim(void)
{
    u8 i;

    if (!sWingullSkimActive)
        return;

    for (i = 0; i < MAX_WINGULL_SKIM; i++)
    {
        if (sWingullSkimSpriteIds[i] != MAX_SPRITES)
        {
            DestroySprite(&gSprites[sWingullSkimSpriteIds[i]]);
            sWingullSkimSpriteIds[i] = MAX_SPRITES;
        }
    }

    FreeSpriteTilesByTag(FLDEFF_TILE_TAG_WINGULL_SKIM);
    FreeSpritePaletteByTag(FLDEFF_PAL_TAG_WINGULL_SKIM);
    sWingullSkimActive = FALSE;
}

enum {
    GASTLY_STATE_IDLE,
    GASTLY_STATE_VANISHING,
    GASTLY_STATE_COOLDOWN,
};

#define MAX_GASTLY_SPOOK 4
static EWRAM_DATA u8 sGastlySpookSpriteIds[MAX_GASTLY_SPOOK] = {0};
static EWRAM_DATA bool8 sGastlySpookActive = FALSE;

static bool8 IsGastlyIlluminated(struct Sprite *sprite)
{
    s16 playerTileX = gSaveBlock1Ptr->pos.x;
    s16 playerTileY = gSaveBlock1Ptr->pos.y;
    s16 mapX = sprite->data[2];
    s16 mapY = sprite->data[3];
    s16 dx = abs(playerTileX - mapX);
    s16 dy = abs(playerTileY - mapY);

    // Trigger when player is within 1 tile
    if (dx <= 1 && dy <= 1)
        return TRUE;

    // Pixel distance on screen check (handles sub-tile movement within ~1.5 tiles)
    if (gPlayerAvatar.objectEventId < OBJECT_EVENTS_COUNT && gObjectEvents[gPlayerAvatar.objectEventId].active)
    {
        struct Sprite *playerSprite = &gSprites[gPlayerAvatar.spriteId];
        s16 playerScreenX = playerSprite->x + playerSprite->x2;
        s16 playerScreenY = playerSprite->y + playerSprite->y2;
        s16 gastlyScreenX = sprite->x + sprite->x2 + gSpriteCoordOffsetX;
        s16 gastlyScreenY = sprite->y + sprite->y2 + gSpriteCoordOffsetY;
        s16 pixelDx = abs(gastlyScreenX - playerScreenX);
        s16 pixelDy = abs(gastlyScreenY - playerScreenY);

        if (pixelDx <= 24 && pixelDy <= 24)
            return TRUE;
    }

    return FALSE;
}

static void SpriteCallback_GastlySpook(struct Sprite *sprite)
{
    s16 screenX = sprite->x + sprite->centerToCornerVecX + gSpriteCoordOffsetX;
    s16 screenY = sprite->y + sprite->centerToCornerVecY + gSpriteCoordOffsetY;
    bool8 onScreen = (screenX > -32 && screenX < DISPLAY_WIDTH && screenY > -32 && screenY < DISPLAY_HEIGHT);

    if (!onScreen || sprite->data[0] == GASTLY_STATE_COOLDOWN)
    {
        sprite->invisible = TRUE;
        if (sprite->data[0] == GASTLY_STATE_COOLDOWN)
        {
            if (sprite->data[1] > 0)
            {
                sprite->data[1]--;
            }
            else
            {
                // Cooldown ended. Ready to respawn once player moves away (> 2 tiles).
                if (!IsGastlyIlluminated(sprite))
                {
                    sprite->data[0] = GASTLY_STATE_IDLE;
                    sprite->data[1] = 0;
                    StartSpriteAnim(sprite, GASTLY_ANIM_FLOAT);
                }
            }
        }
        return;
    }

    switch (sprite->data[0])
    {
    case GASTLY_STATE_IDLE:
        sprite->invisible = FALSE;

        // Floating bobbing motion
        sprite->data[6] += 4;
        sprite->y2 = gSineTable[sprite->data[6] & 0xFF] >> 6;

        // Trigger when player is 2 tiles away
        if (IsGastlyIlluminated(sprite))
        {
            PlayCry_Normal(SPECIES_GASTLY, 0);
            PlaySE(SE_BALL_OPEN);
            StartSpriteAnim(sprite, GASTLY_ANIM_SMOKE_PUFF);
            sprite->y2 = 0;
            sprite->data[0] = GASTLY_STATE_VANISHING;
            sprite->data[1] = 0;
        }
        break;

    case GASTLY_STATE_VANISHING:
        sprite->invisible = FALSE;
        sprite->data[1]++;
        if (sprite->animEnded || sprite->data[1] >= 24)
        {
            sprite->invisible = TRUE;
            sprite->data[0] = GASTLY_STATE_COOLDOWN;
            sprite->data[1] = 600 + (Random() % 300); // 10 - 15 seconds cooldown
        }
        break;
    }
}

static bool8 MapHasGastlySpook(u8 mapGroup, u8 mapNum)
{
    u32 i;
    for (i = 0; i < ARRAY_COUNT(sMapLightSources); i++)
    {
        if (sMapLightSources[i].mapGroup == mapGroup && sMapLightSources[i].mapNum == mapNum)
        {
            if (sMapLightSources[i].type == LIGHT_TYPE_GASTLY_SPOOK)
                return TRUE;
        }
    }
    return FALSE;
}

static void SpawnGastlySpook(void)
{
    u8 mapGroup = gSaveBlock1Ptr->location.mapGroup;
    u8 mapNum = gSaveBlock1Ptr->location.mapNum;
    u32 i;
    u8 count = 0;

    if (sGastlySpookActive)
        return;

    if (GetSpriteTileStartByTag(FLDEFF_TILE_TAG_GASTLY_SPOOK) == 0xFFFF)
        LoadSpriteSheet(&sSpriteSheet_GastlySpook);
    {
        u8 palIndex = IndexOfSpritePaletteTag(FLDEFF_PAL_TAG_GASTLY_SPOOK);
        if (palIndex == 0xFF)
            FieldEffectScript_LoadFadedPal(&sSpritePalette_GastlySpook);
        else
            UpdateSpritePaletteWithWeather(palIndex, TRUE);
    }

    for (i = 0; i < MAX_GASTLY_SPOOK; i++)
        sGastlySpookSpriteIds[i] = MAX_SPRITES;

    for (i = 0; i < ARRAY_COUNT(sMapLightSources) && count < MAX_GASTLY_SPOOK; i++)
    {
        if (sMapLightSources[i].mapGroup == mapGroup && sMapLightSources[i].mapNum == mapNum)
        {
            if (sMapLightSources[i].type == LIGHT_TYPE_GASTLY_SPOOK)
            {
                s16 baseX = sMapLightSources[i].x + MAP_OFFSET;
                s16 baseY = sMapLightSources[i].y + MAP_OFFSET;
                SetSpritePosToOffsetMapCoords(&baseX, &baseY, 8, 8);

                u8 spriteId = CreateSprite(&sSpriteTemplate_GastlySpook, baseX, baseY, 2);
                if (spriteId != MAX_SPRITES)
                {
                    struct Sprite *sprite = &gSprites[spriteId];
                    sprite->coordOffsetEnabled = TRUE;
                    sprite->invisible = FALSE;
                    sprite->data[0] = GASTLY_STATE_IDLE;
                    sprite->data[1] = 0;
                    sprite->data[2] = sMapLightSources[i].x;
                    sprite->data[3] = sMapLightSources[i].y;
                    sprite->data[4] = baseX;
                    sprite->data[5] = baseY;
                    sprite->data[6] = Random() % 256;
                    sprite->data[7] = 0;

                    StartSpriteAnim(sprite, GASTLY_ANIM_FLOAT);
                    sGastlySpookSpriteIds[count++] = spriteId;
                }
            }
        }
    }

    if (count > 0)
        sGastlySpookActive = TRUE;
}

static void DestroyGastlySpook(void)
{
    u8 i;

    if (!sGastlySpookActive)
        return;

    for (i = 0; i < MAX_GASTLY_SPOOK; i++)
    {
        if (sGastlySpookSpriteIds[i] != MAX_SPRITES)
        {
            DestroySprite(&gSprites[sGastlySpookSpriteIds[i]]);
            sGastlySpookSpriteIds[i] = MAX_SPRITES;
        }
    }

    FreeSpriteTilesByTag(FLDEFF_TILE_TAG_GASTLY_SPOOK);
    FreeSpritePaletteByTag(FLDEFF_PAL_TAG_GASTLY_SPOOK);
    sGastlySpookActive = FALSE;
}

static void DestroyMapBoundLightSources(void)
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
    FreeSpritePaletteByTag(FLDEFF_PAL_TAG_LIGHT_CIRCLE);
    FreeSpritePaletteByTag(FLDEFF_PAL_TAG_LIGHT_AMBER);
    FreeSpritePaletteByTag(FLDEFF_PAL_TAG_LIGHT_BUGS);
    sMapLightsActive = FALSE;
}

static void SpawnMapBoundLightSources(u8 mapGroup, u8 mapNum)
{
    u32 i;
    u8 count = 0;
    bool8 hasMatchingLights = FALSE;
    bool8 isDarkMap = (GetFlashLevel() > 0);

    // Clear the tracking slots BEFORE the early return below. sLightSpriteIds
    // is zero-filled EWRAM, and 0 is a valid sprite index -- if a map has no
    // eligible lights and we bailed out first, the array would keep reading as
    // "32 occupied slots pointing at gSprites[0]". ActivateTrainerLight would
    // then match an unrelated sprite in its already-active check (forcing it
    // visible) and find no free slot to spawn the trainer's light into.
    // DestroyMapBoundLightSources always runs before this, so nothing live is
    // being dropped here.
    for (i = 0; i < MAX_MAP_LIGHTS; i++)
        sLightSpriteIds[i] = MAX_SPRITES;

    // The OBJ window is only ever enabled for the dark-map light masks, and
    // nothing else in the overworld turns it back off: a full map load rebuilds
    // DISPCNT in InitOverworldGraphicsRegisters, but a connection transition
    // does not. Without this, walking out of a flash cave into a connected lit
    // map leaves DISPCNT_OBJWIN_ON set. Clearing it restores the same baseline
    // InitOverworldGraphicsRegisters would have set, which also makes the stale
    // WINOUT WINOBJ bits inert.
    if (!isDarkMap)
        ClearGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_OBJWIN_ON);

    for (i = 0; i < ARRAY_COUNT(sMapLightSources); i++)
    {
        if (sMapLightSources[i].mapGroup == mapGroup && sMapLightSources[i].mapNum == mapNum)
        {
            if (sMapLightSources[i].type != LIGHT_TYPE_AUTUMN_LEAVES && sMapLightSources[i].type != LIGHT_TYPE_FLYING_PIDGEY && sMapLightSources[i].type != LIGHT_TYPE_TREE_PIDGEY && sMapLightSources[i].type != LIGHT_TYPE_MAGIKARP_SPLASH && sMapLightSources[i].type != LIGHT_TYPE_WINGULL_SKIM && sMapLightSources[i].type != LIGHT_TYPE_GASTLY_SPOOK)
            {
                if (sMapLightSources[i].flagId == 0 || FlagGet(sMapLightSources[i].flagId))
                {
                    hasMatchingLights = TRUE;
                    break;
                }
            }
        }
    }

    if (!hasMatchingLights && !isDarkMap)
        return;

    if (GetSpriteTileStartByTag(FLDEFF_TILE_TAG_LIGHT_CIRCLE) == 0xFFFF)
        LoadSpriteSheet(&sSpriteSheet_LightCircle);
    if (GetSpriteTileStartByTag(FLDEFF_TILE_TAG_LIGHT_CONE) == 0xFFFF)
        LoadSpriteSheet(&sSpriteSheet_LightCone);
    if (GetSpriteTileStartByTag(FLDEFF_TILE_TAG_FIREFLIES) == 0xFFFF)
        LoadSpriteSheet(&sSpriteSheet_Fireflies);

    if (IndexOfSpritePaletteTag(FLDEFF_PAL_TAG_LIGHT_CIRCLE) == 0xFF)
        LoadSpritePalette(&sSpritePalette_LightCircle);
    if (IndexOfSpritePaletteTag(FLDEFF_PAL_TAG_LIGHT_AMBER) == 0xFF)
        LoadSpritePalette(&sSpritePalette_Fireflies);
    {
        u8 bugPalIndex = IndexOfSpritePaletteTag(FLDEFF_PAL_TAG_LIGHT_BUGS);
        if (bugPalIndex == 0xFF)
            FieldEffectScript_LoadFadedPal(&sSpritePalette_Bugs);
        else
            UpdateSpritePaletteWithWeather(bugPalIndex, TRUE);
    }

    if (isDarkMap)
    {
        ClearGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_WIN0_ON | DISPCNT_WIN1_ON);
        SetGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_OBJWIN_ON);
        SetGpuRegBits(REG_OFFSET_WINOUT, WINOUT_WINOBJ_BG_ALL | WINOUT_WINOBJ_OBJ);

        // Player Flashlight Beam (data[3] = 0)
        if (count < MAX_MAP_LIGHTS)
        {
            u8 beamSpriteId = CreateSprite(&sSpriteTemplate_LightCone, 120, 80, 0);
            if (beamSpriteId != MAX_SPRITES)
            {
                gSprites[beamSpriteId].coordOffsetEnabled = TRUE;
                gSprites[beamSpriteId].data[1] = TRACKING_PLAYER;
                gSprites[beamSpriteId].data[2] = LIGHT_TYPE_FLASHLIGHT;
                gSprites[beamSpriteId].data[3] = 0; // Beam
                gSprites[beamSpriteId].invisible = TRUE;
                sLightSpriteIds[count++] = beamSpriteId;
            }
        }

        // Player Flashlight Ambient Glow (data[3] = 1)
        if (count < MAX_MAP_LIGHTS)
        {
            u8 glowSpriteId = CreateSprite(&sSpriteTemplate_LightCone, 120, 80, 0);
            if (glowSpriteId != MAX_SPRITES)
            {
                gSprites[glowSpriteId].coordOffsetEnabled = TRUE;
                gSprites[glowSpriteId].data[1] = TRACKING_PLAYER;
                gSprites[glowSpriteId].data[2] = LIGHT_TYPE_FLASHLIGHT;
                gSprites[glowSpriteId].data[3] = 1; // Glow
                gSprites[glowSpriteId].invisible = TRUE;
                StartSpriteAnim(&gSprites[glowSpriteId], LIGHT_CONE_ANIM_GLOW);
                sLightSpriteIds[count++] = glowSpriteId;
            }
        }
    }

    for (i = 0; i < ARRAY_COUNT(sMapLightSources) && count < MAX_MAP_LIGHTS; i++)
    {
        if (sMapLightSources[i].mapGroup == mapGroup && sMapLightSources[i].mapNum == mapNum)
        {
            if (sMapLightSources[i].type == LIGHT_TYPE_AUTUMN_LEAVES || sMapLightSources[i].type == LIGHT_TYPE_FLYING_PIDGEY || sMapLightSources[i].type == LIGHT_TYPE_TREE_PIDGEY || sMapLightSources[i].type == LIGHT_TYPE_MAGIKARP_SPLASH || sMapLightSources[i].type == LIGHT_TYPE_WINGULL_SKIM || sMapLightSources[i].type == LIGHT_TYPE_GASTLY_SPOOK)
                continue;

            if (sMapLightSources[i].flagId == 0 || FlagGet(sMapLightSources[i].flagId))
            {
                s16 x = sMapLightSources[i].x + MAP_OFFSET;
                s16 y = sMapLightSources[i].y + MAP_OFFSET;

                SetSpritePosToOffsetMapCoords(&x, &y, 8, 8);

                if (sMapLightSources[i].type == LIGHT_TYPE_FIREFLIES)
                {
                    // Capacity is checked before CreateSprite, not after: a
                    // sprite created once the table is full would never be
                    // recorded in sLightSpriteIds, so nothing would ever destroy
                    // it. Firefly and flashlight entries each consume two slots,
                    // so the loop's own count check can't catch this alone.
                    if (isDarkMap && count < MAX_MAP_LIGHTS)
                    {
                        u8 winSpriteId = CreateSprite(&sSpriteTemplate_Fireflies_Window, x, y, 0);
                        if (winSpriteId != MAX_SPRITES)
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
                    if (count < MAX_MAP_LIGHTS)
                    {
                        beamSpriteId = CreateSprite(&sSpriteTemplate_LightCone, beamX, beamY, 0);
                        if (beamSpriteId != MAX_SPRITES)
                        {
                            gSprites[beamSpriteId].coordOffsetEnabled = TRUE;
                            gSprites[beamSpriteId].data[1] = sMapLightSources[i].trackingLocalId;
                            gSprites[beamSpriteId].data[2] = LIGHT_TYPE_FLASHLIGHT;
                            gSprites[beamSpriteId].data[3] = 0; // Beam
                            StartSpriteAnim(&gSprites[beamSpriteId], dir);
                            sLightSpriteIds[count++] = beamSpriteId;
                        }
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
                else if (count < MAX_MAP_LIGHTS)
                {
                    u8 spriteId = CreateSprite(&sSpriteTemplate_LightCircle, x, y, 0);
                    if (spriteId != MAX_SPRITES)
                    {
                        // Size var is a Haunted Woods debug control, so only
                        // honour it there -- see IsHauntedWoodsFlameMap.
                        u16 sizeVar = IsHauntedWoodsFlameMap() ? VarGet(VAR_HAUNTED_WOODS_LIGHT_SIZE) : 0;
                        u8 anim = LIGHT_ANIM_FLAME_100;

                        gSprites[spriteId].coordOffsetEnabled = TRUE;
                        gSprites[spriteId].data[1] = sMapLightSources[i].trackingLocalId;
                        gSprites[spriteId].data[2] = sMapLightSources[i].type;
                        gSprites[spriteId].data[3] = 0;

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

void InitMapLightSources(void)
{
    u8 mapGroup = gSaveBlock1Ptr->location.mapGroup;
    u8 mapNum = gSaveBlock1Ptr->location.mapNum;

    DestroyMapLightSources();

    SpawnMapBoundLightSources(mapGroup, mapNum);

    if (MapHasAutumnLeaves(mapGroup, mapNum))
        SpawnAutumnLeaves(FALSE);

    if (MapHasFlyingPidgey(mapGroup, mapNum))
        SpawnFlyingPidgey();

    if (MapHasTreePidgey(mapGroup, mapNum))
        SpawnTreePidgey();

    if (MapHasMagikarpSplash(mapGroup, mapNum))
        SpawnMagikarpSplash();

    if (MapHasWingullSkim(mapGroup, mapNum))
        SpawnWingullSkim();

    if (MapHasGastlySpook(mapGroup, mapNum))
        SpawnGastlySpook();
}

void OnMapConnectionTransition(u8 mapGroup, u8 mapNum)
{
    // Handle Autumn Leaves transition (Option B)
    if (MapHasAutumnLeaves(mapGroup, mapNum))
    {
        SpawnAutumnLeaves(TRUE); // Wind-in
    }
    else if (sAutumnLeavesActive)
    {
        WindOutAutumnLeaves(); // Wind-out
    }

    // Handle Flying Pidgey transition
    if (MapHasFlyingPidgey(mapGroup, mapNum))
    {
        if (!sFlyingPidgeyActive)
            SpawnFlyingPidgey();
    }
    else if (sFlyingPidgeyActive)
    {
        DestroyFlyingPidgey();
    }

    // Handle Tree Pidgey transition
    if (MapHasTreePidgey(mapGroup, mapNum))
    {
        if (!sTreePidgeyActive)
            SpawnTreePidgey();
    }
    else if (sTreePidgeyActive)
    {
        DestroyTreePidgey();
    }

    // Handle Magikarp Splash transition
    if (MapHasMagikarpSplash(mapGroup, mapNum))
    {
        if (!sMagikarpSplashActive)
            SpawnMagikarpSplash();
    }
    else if (sMagikarpSplashActive)
    {
        DestroyMagikarpSplash();
    }

    // Handle Wingull Skim transition
    if (MapHasWingullSkim(mapGroup, mapNum))
    {
        if (!sWingullSkimActive)
            SpawnWingullSkim();
    }
    else if (sWingullSkimActive)
    {
        DestroyWingullSkim();
    }

    // Handle Gastly Spook transition
    if (MapHasGastlySpook(mapGroup, mapNum))
    {
        if (!sGastlySpookActive)
            SpawnGastlySpook();
    }
    else if (sGastlySpookActive)
    {
        DestroyGastlySpook();
    }

    // Refresh map-bound lights for new map
    DestroyMapBoundLightSources();
    SpawnMapBoundLightSources(mapGroup, mapNum);
}

void DestroyMapLightSources(void)
{
    u8 i;

    DestroyMapBoundLightSources();

    if (sAutumnLeavesActive || sAutumnLeavesWindingOut)
    {
        for (i = 0; i < NUM_AUTUMN_LEAVES; i++)
        {
            if (sAutumnLeafSpriteIds[i] != MAX_SPRITES)
            {
                DestroySprite(&gSprites[sAutumnLeafSpriteIds[i]]);
                sAutumnLeafSpriteIds[i] = MAX_SPRITES;
            }
        }
        FreeSpriteTilesByTag(FLDEFF_TILE_TAG_AUTUMN_LEAF);
        FreeSpritePaletteByTag(FLDEFF_PAL_TAG_AUTUMN_LEAF);
        sAutumnLeavesActive = FALSE;
        sAutumnLeavesWindingOut = FALSE;
    }

    if (sFlyingPidgeyActive)
        DestroyFlyingPidgey();

    if (sTreePidgeyActive)
        DestroyTreePidgey();

    if (sMagikarpSplashActive)
        DestroyMagikarpSplash();

    if (sWingullSkimActive)
        DestroyWingullSkim();

    if (sGastlySpookActive)
        DestroyGastlySpook();
}

// ============================================================================
// UNUSED -- kept for future use.
//
// UpdateMapLightSourcesVisibility(visible) force-hides or re-shows every active
// effect sprite in one call, and is smarter than a blanket `invisible` write:
// on the re-show path it respects each effect's own reason for being hidden, so
// it won't pop a sprite back on screen that should have stayed off. Per type it
// re-checks: autumn leaves still inside their staggered entry delay (data[5]),
// Pidgey flocks mid-cooldown or parked off-screen, and Magikarp/Wingull sitting
// in their submerged/cooldown states, plus the usual off-screen cull.
//
// Intended for cases where the field is still loaded but effects should freeze
// out of sight -- opening a fullscreen menu, a scripted cutscene, or a fade
// where leftover ambient sprites would show through. Nothing calls it today:
// map loads and connection transitions destroy and respawn the sprites outright
// instead, which is why the system works without it.
//
// To re-enable: uncomment this and its prototype in include/field_light_sources.h,
// then call it from wherever the field is being suspended/resumed. Note it only
// touches sprites that are already spawned -- it does not load or free anything.
/*
void UpdateMapLightSourcesVisibility(bool8 visible)
{
    u32 i;

    if (sMapLightsActive)
    {
        for (i = 0; i < MAX_MAP_LIGHTS; i++)
        {
            if (sLightSpriteIds[i] != MAX_SPRITES)
                gSprites[sLightSpriteIds[i]].invisible = !visible;
        }
    }

    if (sAutumnLeavesActive)
    {
        for (i = 0; i < NUM_AUTUMN_LEAVES; i++)
        {
            if (sAutumnLeafSpriteIds[i] != MAX_SPRITES)
            {
                if (!visible)
                    gSprites[sAutumnLeafSpriteIds[i]].invisible = TRUE;
                else if (gSprites[sAutumnLeafSpriteIds[i]].data[5] == 0)
                    gSprites[sAutumnLeafSpriteIds[i]].invisible = FALSE;
            }
        }
    }

    if (sFlyingPidgeyActive)
    {
        for (i = 0; i < NUM_FLYING_PIDGEY; i++)
        {
            if (sFlyingPidgeySpriteIds[i] != MAX_SPRITES)
            {
                if (!visible || sFlyingPidgeyFlockCooldown > 0)
                {
                    gSprites[sFlyingPidgeySpriteIds[i]].invisible = TRUE;
                }
                else
                {
                    s16 bx = gSprites[sFlyingPidgeySpriteIds[i]].x;
                    gSprites[sFlyingPidgeySpriteIds[i]].invisible = (bx < -32 || bx > DISPLAY_WIDTH + 32);
                }
            }
        }
    }

    if (sTreePidgeyActive)
    {
        for (i = 0; i < NUM_TREE_PIDGEY; i++)
        {
            if (sTreePidgeySpriteIds[i] != MAX_SPRITES)
                gSprites[sTreePidgeySpriteIds[i]].invisible = !visible;
        }
    }

    if (sMagikarpSplashActive)
    {
        for (i = 0; i < MAX_MAGIKARP_SPLASH; i++)
        {
            if (sMagikarpSplashSpriteIds[i] != MAX_SPRITES)
            {
                if (!visible)
                {
                    gSprites[sMagikarpSplashSpriteIds[i]].invisible = TRUE;
                }
                else if (gSprites[sMagikarpSplashSpriteIds[i]].data[0] != MAGIKARP_STATE_SUBMERGED)
                {
                    struct Sprite *spr = &gSprites[sMagikarpSplashSpriteIds[i]];
                    s16 sx = spr->x + spr->x2 + spr->centerToCornerVecX + gSpriteCoordOffsetX;
                    s16 sy = spr->y + spr->y2 + spr->centerToCornerVecY + gSpriteCoordOffsetY;
                    spr->invisible = (sx < -32 || sx > DISPLAY_WIDTH + 32 || sy < -32 || sy > DISPLAY_HEIGHT + 32);
                }
            }
        }
    }

    if (sWingullSkimActive)
    {
        for (i = 0; i < MAX_WINGULL_SKIM; i++)
        {
            if (sWingullSkimSpriteIds[i] != MAX_SPRITES)
            {
                if (!visible)
                {
                    gSprites[sWingullSkimSpriteIds[i]].invisible = TRUE;
                }
                else if (gSprites[sWingullSkimSpriteIds[i]].data[0] != WINGULL_STATE_COOLDOWN)
                {
                    struct Sprite *spr = &gSprites[sWingullSkimSpriteIds[i]];
                    s16 sx = spr->x + spr->x2 + spr->centerToCornerVecX + gSpriteCoordOffsetX;
                    s16 sy = spr->y + spr->y2 + spr->centerToCornerVecY + gSpriteCoordOffsetY;
                    spr->invisible = (sx < -32 || sx > DISPLAY_WIDTH + 32 || sy < -32 || sy > DISPLAY_HEIGHT + 32);
                }
            }
        }
    }
}
*/

// ============================================================================
// UNUSED -- kept for future use.
//
// Script-callable wrapper around InitMapLightSources: tears every effect down
// and respawns it from the table for the current map. The point of exposing it
// as a special is letting a map script refresh the lights after it changes
// something the spawn path reads but the sprites don't poll -- most importantly
// a light's gating flag (struct MapLightSource.flagId), since that is only
// evaluated at spawn time. Toggling such a flag mid-map has no visible effect
// until something respawns the lights.
//
// To re-enable: uncomment this and its prototype in include/field_light_sources.h,
// then add it to the specials table in data/specials.inc, e.g.
//     def_special Special_UpdateMapLightSources
// and call it from Poryscript as `special(Special_UpdateMapLightSources)`.
/*
void Special_UpdateMapLightSources(void)
{
    InitMapLightSources();
}
*/

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
