#include "global.h"
#include "sprite.h"
#include "mugshot.h"
#include "constants/mugshots.h"

#define MUGSHOT_TILE_TAG 0x5500
#define MUGSHOT_PALETTE_TAG 0x5500

// Centering coordinates above dialogue box
#define MUGSHOT_LEFT_X   36
#define MUGSHOT_RIGHT_X  204
#define MUGSHOT_Y        80

struct MugshotData
{
    const u32 *gfx;
    const u16 *pal;
};

// Graphics declarations
static const u32 sMugshotPic_ProfOak[] = INCBIN_U32("graphics/mugshots/prof_oak.4bpp");
static const u16 sMugshotPal_ProfOak[] = INCBIN_U16("graphics/mugshots/prof_oak.gbapal");

static const u32 sMugshotPic_Agatha[] = INCBIN_U32("graphics/mugshots/agatha.4bpp");
static const u16 sMugshotPal_Agatha[] = INCBIN_U16("graphics/mugshots/agatha.gbapal");

// Table mapping MUGSHOT_* constants to file references
static const struct MugshotData sMugshots[] =
{
    [MUGSHOT_PROF_OAK] = { sMugshotPic_ProfOak, sMugshotPal_ProfOak },
    [MUGSHOT_AGATHA]   = { sMugshotPic_Agatha, sMugshotPal_Agatha },
};

static EWRAM_DATA u8 sMugshotSpriteId = 0;

static const struct OamData sOamData_Mugshot =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(64x64),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(64x64),
    .tileNum = 0,
    .priority = 0, // Render on top of standard background layers
    .paletteNum = 0,
};

static const struct SpriteTemplate sMugshotSpriteTemplate =
{
    .tileTag = MUGSHOT_TILE_TAG,
    .paletteTag = MUGSHOT_PALETTE_TAG,
    .oam = &sOamData_Mugshot,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

void InitMugshot(void)
{
    sMugshotSpriteId = MAX_SPRITES;
}

void ShowMugshot(u16 mugshotId, u8 position)
{
    struct SpriteSheet spriteSheet;
    struct SpritePalette spritePalette;
    u8 x;

    ClearMugshot();

    if (mugshotId == MUGSHOT_NONE || mugshotId >= ARRAY_COUNT(sMugshots) || sMugshots[mugshotId].gfx == NULL)
        return;

    // Load tiles into VRAM
    spriteSheet.data = sMugshots[mugshotId].gfx;
    spriteSheet.size = 0x800; // 64x64 4bpp sprite = 2048 bytes
    spriteSheet.tag = MUGSHOT_TILE_TAG;
    LoadSpriteSheet(&spriteSheet);

    // Load palette into OBJ Palette RAM
    spritePalette.data = sMugshots[mugshotId].pal;
    spritePalette.tag = MUGSHOT_PALETTE_TAG;
    LoadSpritePalette(&spritePalette);

    // Determine horizontal position
    x = (position == MUGSHOT_RIGHT) ? MUGSHOT_RIGHT_X : MUGSHOT_LEFT_X;

    // Render OBJ sprite
    sMugshotSpriteId = CreateSprite(&sMugshotSpriteTemplate, x, MUGSHOT_Y, 0);

    // If sprite slot allocation failed, release VRAM tiles/palette immediately
    if (sMugshotSpriteId == MAX_SPRITES)
    {
        FreeSpriteTilesByTag(MUGSHOT_TILE_TAG);
        FreeSpritePaletteByTag(MUGSHOT_PALETTE_TAG);
    }
}

void ClearMugshot(void)
{
    if (sMugshotSpriteId != MAX_SPRITES)
    {
        DestroySprite(&gSprites[sMugshotSpriteId]);
        FreeSpriteTilesByTag(MUGSHOT_TILE_TAG);
        FreeSpritePaletteByTag(MUGSHOT_PALETTE_TAG);
        sMugshotSpriteId = MAX_SPRITES;
    }
}
