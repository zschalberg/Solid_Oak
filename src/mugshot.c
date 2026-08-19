#include "global.h"
#include "sprite.h"
#include "mugshot.h"
#include "constants/mugshots.h"

#define MUGSHOT_TILE_TAG(pos)    (0x5500 + (pos))
#define MUGSHOT_PALETTE_TAG(pos) (0x5500 + (pos))

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

static const u32 sMugshotPic_ProfArbor[] = INCBIN_U32("graphics/mugshots/prof_arbor.4bpp");
static const u16 sMugshotPal_ProfArbor[] = INCBIN_U16("graphics/mugshots/prof_arbor.gbapal");

static const u32 sMugshotPic_AgathaUpdated[] = INCBIN_U32("graphics/mugshots/agatha_updated.4bpp");
static const u16 sMugshotPal_AgathaUpdated[] = INCBIN_U16("graphics/mugshots/agatha_updated.gbapal");

static const u32 sMugshotPic_MrFuji[] = INCBIN_U32("graphics/mugshots/mr_fuji.4bpp");
static const u16 sMugshotPal_MrFuji[] = INCBIN_U16("graphics/mugshots/mr_fuji.gbapal");

static const u32 sMugshotPic_MrFujiSad[] = INCBIN_U32("graphics/mugshots/mr_fuji_sad.4bpp");
static const u16 sMugshotPal_MrFujiSad[] = INCBIN_U16("graphics/mugshots/mr_fuji_sad.gbapal");

// Table mapping MUGSHOT_* constants to file references
static const struct MugshotData sMugshots[] =
{
    [MUGSHOT_PROF_OAK]        = { sMugshotPic_ProfOak, sMugshotPal_ProfOak },
    [MUGSHOT_AGATHA]          = { sMugshotPic_Agatha, sMugshotPal_Agatha },
    [MUGSHOT_PROF_ARBOR]      = { sMugshotPic_ProfArbor, sMugshotPal_ProfArbor },
    [MUGSHOT_AGATHA_UPDATED]  = { sMugshotPic_AgathaUpdated, sMugshotPal_AgathaUpdated },
    [MUGSHOT_MR_FUJI]         = { sMugshotPic_MrFuji, sMugshotPal_MrFuji },
    [MUGSHOT_MR_FUJI_SAD]     = { sMugshotPic_MrFujiSad, sMugshotPal_MrFujiSad },
};

static EWRAM_DATA u8 sMugshotSpriteIds[2] = {0, 0};
static EWRAM_DATA bool8 sMugshotActive[2] = {FALSE, FALSE};

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
    .tileTag = 0x5500, // Dummy tag, overwritten dynamically
    .paletteTag = 0x5500, // Dummy tag, overwritten dynamically
    .oam = &sOamData_Mugshot,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

void InitMugshot(void)
{
    sMugshotSpriteIds[MUGSHOT_LEFT] = MAX_SPRITES;
    sMugshotSpriteIds[MUGSHOT_RIGHT] = MAX_SPRITES;
    sMugshotActive[MUGSHOT_LEFT] = FALSE;
    sMugshotActive[MUGSHOT_RIGHT] = FALSE;
}

void ShowMugshot(u16 mugshotId, u8 position)
{
    struct SpriteSheet spriteSheet;
    struct SpritePalette spritePalette;
    struct SpriteTemplate template;
    u8 x;

    if (position > MUGSHOT_RIGHT)
        return;

    ClearMugshotAt(position);

    if (mugshotId == MUGSHOT_NONE || mugshotId >= ARRAY_COUNT(sMugshots) || sMugshots[mugshotId].gfx == NULL)
        return;

    // Load tiles into VRAM with unique tag for this position
    spriteSheet.data = sMugshots[mugshotId].gfx;
    spriteSheet.size = 0x800; // 64x64 4bpp sprite = 2048 bytes
    spriteSheet.tag = MUGSHOT_TILE_TAG(position);
    LoadSpriteSheet(&spriteSheet);

    // Load palette into OBJ Palette RAM with unique tag for this position
    spritePalette.data = sMugshots[mugshotId].pal;
    spritePalette.tag = MUGSHOT_PALETTE_TAG(position);
    LoadSpritePalette(&spritePalette);

    // Determine horizontal position
    x = (position == MUGSHOT_RIGHT) ? MUGSHOT_RIGHT_X : MUGSHOT_LEFT_X;

    // Prepare template with correct tags
    CpuCopy16(&sMugshotSpriteTemplate, &template, sizeof(struct SpriteTemplate));
    template.tileTag = MUGSHOT_TILE_TAG(position);
    template.paletteTag = MUGSHOT_PALETTE_TAG(position);

    // Render OBJ sprite
    sMugshotSpriteIds[position] = CreateSprite(&template, x, MUGSHOT_Y, 0);
    sMugshotActive[position] = (sMugshotSpriteIds[position] != MAX_SPRITES);

    // If sprite slot allocation failed, release VRAM tiles/palette immediately
    if (sMugshotSpriteIds[position] == MAX_SPRITES)
    {
        FreeSpriteTilesByTag(MUGSHOT_TILE_TAG(position));
        FreeSpritePaletteByTag(MUGSHOT_PALETTE_TAG(position));
    }
}

void ClearMugshotAt(u8 position)
{
    if (position > MUGSHOT_RIGHT)
        return;

    if (sMugshotActive[position])
    {
        DestroySprite(&gSprites[sMugshotSpriteIds[position]]);
        FreeSpriteTilesByTag(MUGSHOT_TILE_TAG(position));
        FreeSpritePaletteByTag(MUGSHOT_PALETTE_TAG(position));
        sMugshotSpriteIds[position] = MAX_SPRITES;
        sMugshotActive[position] = FALSE;
    }
}

void ClearMugshot(void)
{
    ClearMugshotAt(MUGSHOT_LEFT);
    ClearMugshotAt(MUGSHOT_RIGHT);
}
