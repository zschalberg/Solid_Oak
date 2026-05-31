#include "global.h"
#include "data.h"
#include "decompress.h"
#include "malloc.h"
#include "palette.h"
#include "trainer_pokemon_sprites.h"
#include "trainer.h"
#include "window.h"
#include "data/graphics/pokedex_gen2_sprites.h"

#define PICS_COUNT 8

struct PicData
{
    u8 *frames;
    struct SpriteFrameImage *images;
    u16 paletteTag;
    u8 spriteId;
    u8 active;
};

static EWRAM_DATA struct SpriteTemplate sCreatingSpriteTemplate = {};
static EWRAM_DATA struct PicData sSpritePics[PICS_COUNT] = {};

static const struct PicData sDummyPicData = {};

static const struct OamData sOamData_64x64 =
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
    .tileNum = 0x000,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0
};

static const struct OamData sOamData_Affine =
{
    .affineMode = ST_OAM_AFFINE_NORMAL,
    .shape = SPRITE_SHAPE(64x64),
    .size = SPRITE_SIZE(64x64)
};

void DummyPicSpriteCallback(struct Sprite *sprite)
{
}

void ResetAllPicSprites(void)
{
    u32 i;

    for (i = 0; i < PICS_COUNT; i ++)
        sSpritePics[i] = sDummyPicData;
}

static void LoadMonPicPaletteByTagOrSlot(enum Species species, bool32 isShiny, u32 personality, u8 paletteSlot, u16 paletteTag)
{
    if (paletteTag == TAG_NONE)
    {
        sCreatingSpriteTemplate.paletteTag = TAG_NONE;
        LoadPalette(GetMonSpritePalFromSpeciesAndPersonality(species, isShiny, personality), OBJ_PLTT_ID(paletteSlot), PLTT_SIZE_4BPP);
    }
    else
    {
        sCreatingSpriteTemplate.paletteTag = paletteTag;
        LoadSpritePaletteWithTag(GetMonSpritePalFromSpeciesAndPersonality(species, isShiny, personality), paletteTag);
    }
}

void LoadMonFrontPicInWindow(enum Species species, bool32 isShiny, u32 personality, u8 paletteSlot, u8 windowId)
{
    u8 *framePics = Alloc(MON_PIC_SIZE * MAX_MON_PIC_FRAMES);

    if (!framePics)
        return;

    LoadSpecialPokePic(framePics, species, personality, TRUE);
    BlitBitmapRectToWindow(windowId, framePics, 0, 0, MON_PIC_WIDTH, MON_PIC_HEIGHT, 0, 0, MON_PIC_WIDTH, MON_PIC_HEIGHT);
    LoadPalette(GetMonSpritePalFromSpeciesAndPersonality(species, isShiny, personality), BG_PLTT_ID(paletteSlot), PLTT_SIZE_4BPP);
    Free(framePics);
}

// Set to TRUE to render Pokédex Gen 2 sprites in hand-drawn journal style grayscale.
#define POKEDEX_GEN2_GRAYSCALE FALSE

#if POKEDEX_GEN2_GRAYSCALE
static void ConvertPaletteToGrayscale(const u16 *src, u16 *dst)
{
    int i;
    dst[0] = src[0]; // Preserve transparent background color index 0
    for (i = 1; i < 16; i++)
    {
        u16 color = src[i];
        u32 r = color & 0x1F;
        u32 g = (color >> 5) & 0x1F;
        u32 b = (color >> 10) & 0x1F;
        // Luminance formula (0.299R + 0.587G + 0.114B)
        u32 gray = (r * 77 + g * 150 + b * 29) >> 8;
        if (gray > 31) gray = 31;
        dst[i] = gray | (gray << 5) | (gray << 10);
    }
}
#endif

void LoadMonFrontPicInWindowPokedex(enum Species species, bool32 isShiny, u32 personality, u8 paletteSlot, u8 windowId)
{
    u8 *framePics = Alloc(MON_PIC_SIZE * MAX_MON_PIC_FRAMES);
    const u16 *paletteData = NULL;
    enum Species sanitizedSpecies = SanitizeSpeciesId(species);

    if (!framePics)
        return;

    if (sanitizedSpecies < NUM_SPECIES && gPokedexGen2FrontPics[sanitizedSpecies] != NULL)
    {
        DecompressDataWithHeaderWram(gPokedexGen2FrontPics[sanitizedSpecies], framePics);
    }
    else
    {
        LoadSpecialPokePic(framePics, species, personality, TRUE);
    }

    BlitBitmapRectToWindow(windowId, framePics, 0, 0, MON_PIC_WIDTH, MON_PIC_HEIGHT, 0, 0, MON_PIC_WIDTH, MON_PIC_HEIGHT);

    if (sanitizedSpecies < NUM_SPECIES)
    {
        if (isShiny && gPokedexGen2ShinyPalettes[sanitizedSpecies] != NULL)
            paletteData = gPokedexGen2ShinyPalettes[sanitizedSpecies];
        else if (!isShiny && gPokedexGen2Palettes[sanitizedSpecies] != NULL)
            paletteData = gPokedexGen2Palettes[sanitizedSpecies];
    }

    if (paletteData == NULL)
    {
        paletteData = GetMonSpritePalFromSpeciesAndPersonality(species, isShiny, personality);
    }

#if POKEDEX_GEN2_GRAYSCALE
    u16 grayscalePal[16];
    ConvertPaletteToGrayscale(paletteData, grayscalePal);
    paletteData = grayscalePal;
#endif

    LoadPalette(paletteData, BG_PLTT_ID(paletteSlot), PLTT_SIZE_4BPP);
    Free(framePics);
}

void LoadTrainerFrontPicInWindow(enum TrainerPicID trainerPicId, u16 destX, u16 destY, u8 paletteSlot, u8 windowId)
{
    u8 *framePics = Alloc(TRAINER_PIC_SIZE);

    if (!framePics)
        return;

    DecompressDataWithHeaderWram(GetTrainerFrontPicData(trainerPicId), framePics);
    BlitBitmapRectToWindow(windowId, framePics, 0, 0, TRAINER_PIC_WIDTH, TRAINER_PIC_HEIGHT, destX, destY, TRAINER_PIC_WIDTH, TRAINER_PIC_HEIGHT);
    LoadPalette(GetTrainerFrontPicPalette(trainerPicId), BG_PLTT_ID(paletteSlot), PLTT_SIZE_4BPP);
    Free(framePics);
}

u16 CreateMonFrontPicSprite(enum Species species, bool32 isShiny, u32 personality, s16 x, s16 y, u8 paletteSlot, u16 paletteTag)
{
    u8 i;
    u8 *framePics;
    struct SpriteFrameImage *images;
    int j;
    u8 spriteId;

    for (i = 0; i < PICS_COUNT; i ++)
    {
        if (!sSpritePics[i].active)
            break;
    }
    if (i == PICS_COUNT)
        return 0xFFFF;

    framePics = Alloc(MON_PIC_SIZE * MAX_MON_PIC_FRAMES);
    if (!framePics)
        return 0xFFFF;

    images = Alloc(sizeof(struct SpriteFrameImage) * MAX_MON_PIC_FRAMES);
    if (!images)
    {
        Free(framePics);
        return 0xFFFF;
    }

    LoadSpecialPokePic(framePics, species, personality, TRUE);

    for (j = 0; j < MAX_MON_PIC_FRAMES; j ++)
    {
        images[j].data = framePics + MON_PIC_SIZE * j;
        images[j].size = MON_PIC_SIZE;
    }

    sCreatingSpriteTemplate.tileTag = TAG_NONE;
    sCreatingSpriteTemplate.oam = &sOamData_64x64;
    sCreatingSpriteTemplate.anims = gAnims_MonPic;
    sCreatingSpriteTemplate.images = images;
    sCreatingSpriteTemplate.affineAnims = gDummySpriteAffineAnimTable;
    sCreatingSpriteTemplate.callback = DummyPicSpriteCallback;

    LoadMonPicPaletteByTagOrSlot(species, isShiny, personality, paletteSlot, paletteTag);
    spriteId = CreateSprite(&sCreatingSpriteTemplate, x, y, 0);
    if (paletteTag == TAG_NONE)
        gSprites[spriteId].oam.paletteNum = paletteSlot;
    sSpritePics[i].frames = framePics;
    sSpritePics[i].images = images;
    sSpritePics[i].paletteTag = paletteTag;
    sSpritePics[i].spriteId = spriteId;
    sSpritePics[i].active = TRUE;
    return spriteId;
}

static void LoadMonPicPaletteByTagOrSlotPokedex(enum Species species, bool32 isShiny, u32 personality, u8 paletteSlot, u16 paletteTag)
{
    const u16 *paletteData = NULL;
    species = SanitizeSpeciesId(species);

    if (species < NUM_SPECIES)
    {
        if (isShiny && gPokedexGen2ShinyPalettes[species] != NULL)
            paletteData = gPokedexGen2ShinyPalettes[species];
        else if (!isShiny && gPokedexGen2Palettes[species] != NULL)
            paletteData = gPokedexGen2Palettes[species];
    }

    if (paletteData == NULL)
    {
        paletteData = GetMonSpritePalFromSpeciesAndPersonality(species, isShiny, personality);
    }

#if POKEDEX_GEN2_GRAYSCALE
    u16 grayscalePal[16];
    ConvertPaletteToGrayscale(paletteData, grayscalePal);
    paletteData = grayscalePal;
#endif

    if (paletteTag == TAG_NONE)
    {
        sCreatingSpriteTemplate.paletteTag = TAG_NONE;
        LoadPalette(paletteData, OBJ_PLTT_ID(paletteSlot), PLTT_SIZE_4BPP);
    }
    else
    {
        sCreatingSpriteTemplate.paletteTag = paletteTag;
        LoadSpritePaletteWithTag(paletteData, paletteTag);
    }
}

u16 CreateMonFrontPicSpritePokedex(enum Species species, bool32 isShiny, u32 personality, s16 x, s16 y, u8 paletteSlot, u16 paletteTag)
{
    u8 i;
    u8 *framePics;
    struct SpriteFrameImage *images;
    int j;
    u8 spriteId;
    enum Species sanitizedSpecies = SanitizeSpeciesId(species);

    for (i = 0; i < PICS_COUNT; i ++)
    {
        if (!sSpritePics[i].active)
            break;
    }
    if (i == PICS_COUNT)
        return 0xFFFF;

    framePics = Alloc(MON_PIC_SIZE * MAX_MON_PIC_FRAMES);
    if (!framePics)
        return 0xFFFF;

    images = Alloc(sizeof(struct SpriteFrameImage) * MAX_MON_PIC_FRAMES);
    if (!images)
    {
        Free(framePics);
        return 0xFFFF;
    }

    if (sanitizedSpecies < NUM_SPECIES && gPokedexGen2FrontPics[sanitizedSpecies] != NULL)
    {
        DecompressDataWithHeaderWram(gPokedexGen2FrontPics[sanitizedSpecies], framePics);
    }
    else
    {
        LoadSpecialPokePic(framePics, species, personality, TRUE);
    }

    for (j = 0; j < MAX_MON_PIC_FRAMES; j ++)
    {
        images[j].data = framePics + MON_PIC_SIZE * j;
        images[j].size = MON_PIC_SIZE;
    }

    sCreatingSpriteTemplate.tileTag = TAG_NONE;
    sCreatingSpriteTemplate.oam = &sOamData_64x64;
    sCreatingSpriteTemplate.anims = gAnims_MonPic;
    sCreatingSpriteTemplate.images = images;
    sCreatingSpriteTemplate.affineAnims = gDummySpriteAffineAnimTable;
    sCreatingSpriteTemplate.callback = DummyPicSpriteCallback;

    LoadMonPicPaletteByTagOrSlotPokedex(species, isShiny, personality, paletteSlot, paletteTag);
    spriteId = CreateSprite(&sCreatingSpriteTemplate, x, y, 0);
    if (paletteTag == TAG_NONE)
        gSprites[spriteId].oam.paletteNum = paletteSlot;
    sSpritePics[i].frames = framePics;
    sSpritePics[i].images = images;
    sSpritePics[i].paletteTag = paletteTag;
    sSpritePics[i].spriteId = spriteId;
    sSpritePics[i].active = TRUE;
    return spriteId;
}

u16 CreateMonPicSprite_Affine(enum Species species, bool8 isShiny, u32 personality, u8 flags, s16 x, s16 y, u8 paletteSlot, u16 paletteTag)
{
    u8 *framePics;
    struct SpriteFrameImage *images;
    int j;
    u8 i;
    u8 spriteId;
    u8 type;
    species = SanitizeSpeciesId(species);

    for (i = 0; i < PICS_COUNT; i++)
    {
        if (!sSpritePics[i].active)
            break;
    }
    if (i == PICS_COUNT)
        return 0xFFFF;

    framePics = Alloc(MON_PIC_SIZE * MAX_MON_PIC_FRAMES);
    if (!framePics)
        return 0xFFFF;

    if (flags & F_MON_PIC_NO_AFFINE)
    {
        flags &= ~F_MON_PIC_NO_AFFINE;
        type = MON_PIC_AFFINE_NONE;
    }
    else
    {
        type = flags;
    }
    images = Alloc(sizeof(struct SpriteFrameImage) * MAX_MON_PIC_FRAMES);
    if (!images)
    {
        Free(framePics);
        return 0xFFFF;
    }

    LoadSpecialPokePic(framePics, species, personality, flags);

    for (j = 0; j < MAX_MON_PIC_FRAMES; j ++)
    {
        images[j].data = framePics + MON_PIC_SIZE * j;
        images[j].size = MON_PIC_SIZE;
    }
    sCreatingSpriteTemplate.tileTag = TAG_NONE;
    sCreatingSpriteTemplate.anims = gSpeciesInfo[species].frontAnimFrames;
    sCreatingSpriteTemplate.images = images;
    if (type == MON_PIC_AFFINE_FRONT)
    {
        sCreatingSpriteTemplate.affineAnims = gAffineAnims_BattleSpriteOpponentSide;
        sCreatingSpriteTemplate.oam = &sOamData_Affine;
    }
    else if (type == MON_PIC_AFFINE_BACK)
    {
        sCreatingSpriteTemplate.affineAnims = gAffineAnims_BattleSpritePlayerSide;
        sCreatingSpriteTemplate.oam = &sOamData_Affine;
    }
    else // MON_PIC_AFFINE_NONE
    {
        sCreatingSpriteTemplate.oam = &sOamData_64x64;
        sCreatingSpriteTemplate.affineAnims = gDummySpriteAffineAnimTable;
    }
    sCreatingSpriteTemplate.callback = DummyPicSpriteCallback;

    LoadMonPicPaletteByTagOrSlot(species, isShiny, personality, paletteSlot, paletteTag);
    spriteId = CreateSprite(&sCreatingSpriteTemplate, x, y, 0);
    if (paletteTag == TAG_NONE)
        gSprites[spriteId].oam.paletteNum = paletteSlot;

    sSpritePics[i].frames = framePics;
    sSpritePics[i].images = images;
    sSpritePics[i].paletteTag = paletteTag;
    sSpritePics[i].spriteId = spriteId;
    sSpritePics[i].active = TRUE;

    return spriteId;
}

u16 CreateTrainerFrontPicSprite(enum TrainerPicID trainerPicId, s16 x, s16 y, u8 paletteSlot)
{

    u8 i;
    u8 *framePics;
    struct SpriteFrameImage *images;
    u8 spriteId;

    for (i = 0; i < PICS_COUNT; i ++)
    {
        if (!sSpritePics[i].active)
            break;
    }
    if (i == PICS_COUNT)
        return 0xFFFF;

    framePics = Alloc(TRAINER_PIC_SIZE);
    if (!framePics)
        return 0xFFFF;

    images = Alloc(sizeof(struct SpriteFrameImage));
    if (!images)
    {
        Free(framePics);
        return 0xFFFF;
    }
    DecompressDataWithHeaderWram(GetTrainerFrontPicData(trainerPicId), framePics);

    images->data = framePics;
    images->size = TRAINER_PIC_SIZE;

    sCreatingSpriteTemplate.tileTag = TAG_NONE;
    sCreatingSpriteTemplate.oam = &sOamData_64x64;
    sCreatingSpriteTemplate.anims = gAnims_Trainer;
    sCreatingSpriteTemplate.images = images;
    sCreatingSpriteTemplate.affineAnims = gDummySpriteAffineAnimTable;
    sCreatingSpriteTemplate.callback = DummyPicSpriteCallback;
    sCreatingSpriteTemplate.paletteTag = TAG_NONE;

    LoadPalette(GetTrainerFrontPicPalette(trainerPicId), OBJ_PLTT_ID(paletteSlot), PLTT_SIZE_4BPP);
    spriteId = CreateSprite(&sCreatingSpriteTemplate, x, y, 0);
    gSprites[spriteId].oam.paletteNum = paletteSlot;

    sSpritePics[i].frames = framePics;
    sSpritePics[i].images = images;
    sSpritePics[i].paletteTag = TAG_NONE;
    sSpritePics[i].spriteId = spriteId;
    sSpritePics[i].active = TRUE;
    return spriteId;
}

static void FreeAndDestroyPicSpriteInternal(u16 spriteId, bool8 clearPalette)
{
    u8 i;
    u8 *framePics;
    struct SpriteFrameImage *images;

    for (i = 0; i < PICS_COUNT; i ++)
    {
        if (sSpritePics[i].spriteId == spriteId)
            break;
    }

    if (i == PICS_COUNT)
        return;

    framePics = sSpritePics[i].frames;
    images = sSpritePics[i].images;
    if (clearPalette && sSpritePics[i].paletteTag != TAG_NONE)
        FreeSpritePaletteByTag(GetSpritePaletteTagByPaletteNum(gSprites[spriteId].oam.paletteNum));

    DestroySprite(&gSprites[spriteId]);
    Free(framePics);
    Free(images);
    sSpritePics[i] = sDummyPicData;
}

void FreeAndDestroyMonPicSprite(u16 spriteId)
{
    FreeAndDestroyPicSpriteInternal(spriteId, TRUE);
}

void FreeAndDestroyMonPicSpriteNoPalette(u16 spriteId)
{
    FreeAndDestroyPicSpriteInternal(spriteId, FALSE);
}

void FreeAndDestroyTrainerPicSprite(u16 spriteId)
{
    FreeAndDestroyPicSpriteInternal(spriteId, TRUE);
}

void CopyTrainerBackspriteFramesToDest(u8 trainerPicId, u8 *dest)
{
    const struct SpriteFrameImage *frame = GetTrainerBackPicImage(trainerPicId);
    // y_offset is repurposed to indicates how many frames does the trainer pic have.
    u32 size = (frame->size * GetTrainerBackPicCoords(trainerPicId)->y_offset);
    CpuSmartCopy16(frame->data, dest, size);
}

u8 CreateTrainerSprite(enum TrainerPicID trainerPicId, s16 x, s16 y, u8 subpriority, u8 *buffer)
{
    struct CompressedSpriteSheet spriteSheet;
    struct SpriteTemplate spriteTemplate;
    bool32 alloced = FALSE;

    spriteSheet.data = GetTrainerFrontPicData(trainerPicId);
    spriteSheet.size = GetTrainerFrontPicSize(trainerPicId);
    spriteSheet.tag = GetTrainerPicTag(trainerPicId, TRUE);

    // Allocate memory for buffer
    if (buffer == NULL)
    {
        buffer = Alloc(spriteSheet.size);
        alloced = TRUE;
    }

    LoadSpritePaletteWithTag(GetTrainerFrontPicPalette(trainerPicId), GetTrainerPicTag(trainerPicId, TRUE));
    LoadCompressedSpriteSheetOverrideBuffer(&spriteSheet, buffer);
    if (alloced)
        Free(buffer);

    spriteTemplate.tileTag = GetTrainerPicTag(trainerPicId, TRUE);
    spriteTemplate.paletteTag = GetTrainerPicTag(trainerPicId, TRUE);
    spriteTemplate.oam = &sOamData_64x64;
    spriteTemplate.anims = gDummySpriteAnimTable;
    spriteTemplate.images = NULL;
    spriteTemplate.affineAnims = gDummySpriteAffineAnimTable;
    spriteTemplate.callback = SpriteCallbackDummy;
    return CreateSprite(&spriteTemplate, x, y, subpriority);
}
