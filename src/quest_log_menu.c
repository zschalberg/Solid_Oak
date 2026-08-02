#include "global.h"
#include "bg.h"
#include "decompress.h"
#include "gpu_regs.h"
#include "graphics.h"
#include "help_system.h"
#include "list_menu.h"
#include "malloc.h"
#include "menu_helpers.h"
#include "menu.h"
#include "palette.h"
#include "pc_screen_effect.h"
#include "scanline_effect.h"
#include "sound.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"
#include "text_window.h"
#include "constants/flags.h"
#include "constants/songs.h"
#include "event_data.h"
#include "item_icon.h"
#include "constants/items.h"
#include "pokemon_icon.h"
#include "constants/species.h"
#include "region_map.h"

struct QuestLogMenuResources
{
    MainCallback savedCallback;
    u8 maxShowed;
    u8 nQuests;
    u8 nQuestsInGroup;
    u8 scrollIndicatorArrowPairId;
    s16 data[3];
};

struct QuestLogMenuStaticResources
{
    MainCallback savedCallback;
    u16 scroll;
    u16 row;
    u8 initialized;
};

enum QuestGroup
{
    QUEST_GROUP_MAIN,
    QUEST_GROUP_SIDE,
    QUEST_GROUP_RESEARCH,
    QUEST_GROUP_COUNT
};

struct Quest
{
    const u8 *name;
    const u8 *desc;
    u16 unlockFlag;
    u16 completeFlag;
    u16 itemId;
    bool8 isPokemonIcon;
    u8 group;
    u16 mapsec;
};

#define TAG_QUEST_ITEM_ICON 0x5400
static EWRAM_DATA u8 sQuestItemIconSpriteId;
static EWRAM_DATA u8 sActiveQuestGroup;
static EWRAM_DATA bool8 sIsQuestIconMon;

static EWRAM_DATA struct QuestLogMenuResources *sQuestLogMenuState = NULL;
static EWRAM_DATA u8 *sBg1TilemapBuffer = NULL;
static EWRAM_DATA struct ListMenuItem *sListMenuItems = NULL;
static EWRAM_DATA struct QuestLogMenuStaticResources sQuestLogListMenuState = {};
static EWRAM_DATA u8 sFormattedQuestNames[8][32];

static void QuestLogMenu_RunSetup(void);
static bool8 QuestLogMenu_DoGfxSetup(void);
static void QuestLogMenu_FadeAndBail(void);
static void Task_QuestLogMenuWaitFadeAndBail(u8 taskId);
static bool8 QuestLogMenu_InitBgs(void);
static bool8 QuestLogMenu_LoadGraphics(void);
static bool8 QuestLogMenu_AllocateResourcesForListMenu(void);
static void QuestLogMenu_BuildListMenuTemplate(void);
static void QuestLogMenu_MoveCursorFunc(s32 itemIndex, bool8 onInit, struct ListMenu *list);
static void QuestLogMenu_PrintHeader(void);
static void QuestLogMenu_PlaceScrollIndicatorArrows(void);
static void QuestLogMenu_FreeResources(void);
static void Task_QuestLogMenuTurnOff1(u8 taskId);
static void Task_QuestLogMenuTurnOff2(u8 taskId);
static void Task_QuestLogMenuMain(u8 taskId);
static void QuestLogMenu_InitWindows(void);
static void QuestLogMenu_AddTextPrinterParameterized(u8 windowId, u8 fontId, const u8 *str, u8 x, u8 y, u8 letterSpacing, u8 lineSpacing, u8 speed, u8 colorIdx);
static void Task_QuestLogMenuFadeToMap(u8 taskId);
static void CB2_ReturnToQuestLogFromMap(void);

static const struct Quest sQuests[] = {
    {
        .name = COMPOUND_STRING("FUJI'S RESEARCH"),
        .desc = COMPOUND_STRING("Meet Mr. Fuji at his lab in LAVENDER\nTOWN.\nStatus: {STR_VAR_1}"),
        .unlockFlag = FLAG_QUEST_MRFUJI_RESEARCH_ACTIVE,
        .completeFlag = FLAG_QUEST_MRFUJI_RESEARCH_COMPLETED,
        .itemId = ITEM_RESEARCH_BALL,
        .isPokemonIcon = FALSE,
        .group = QUEST_GROUP_MAIN,
        .mapsec = MAPSEC_LAVENDER_TOWN
    },
    {
        .name = COMPOUND_STRING("SILPH TESTING"),
        .desc = COMPOUND_STRING("Meet PROF. ARBOR's contact at Silph Co.\nin SAFFRON CITY.\nStatus: {STR_VAR_1}"),
        .unlockFlag = FLAG_QUEST_SILPH_TESTING_ACTIVE,
        .completeFlag = FLAG_QUEST_SILPH_TESTING_COMPLETED,
        .itemId = ITEM_RESEARCH_BALL,
        .isPokemonIcon = FALSE,
        .group = QUEST_GROUP_MAIN,
        .mapsec = MAPSEC_SAFFRON_CITY
    },
    {
        .name = COMPOUND_STRING("PROTOBALL TEST"),
        .desc = COMPOUND_STRING("Catch any 2 Pokemon and bring them\nback to Silph for testing.\nStatus: {STR_VAR_1}"),
        .unlockFlag = FLAG_QUEST_REDPROTOBALL_ACTIVE,
        .completeFlag = FLAG_QUEST_REDPROTOBALL_COMPLETED,
        .itemId = ITEM_RED_PROTOBALL,
        .isPokemonIcon = FALSE,
        .group = QUEST_GROUP_MAIN,
        .mapsec = MAPSEC_SAFFRON_CITY
    },
    {
        .name = COMPOUND_STRING("KRAB FISHING"),
        .desc = COMPOUND_STRING("Catch 2 KRABBY.\nStatus: {STR_VAR_1}"),
        .unlockFlag = FLAG_KRABBY_QUEST_GIVEN,
        .completeFlag = FLAG_KRABBY_QUEST_COMPLETE,
        .itemId = SPECIES_KRABBY,
        .isPokemonIcon = TRUE,
        .group = QUEST_GROUP_RESEARCH,
        .mapsec = MAPSEC_FUCHSIA_CITY
    },
    {
        .name = COMPOUND_STRING("PEWTER GYM CHALLENGE"),
        .desc = COMPOUND_STRING("Defeat LEADER BROCK at the PEWTER GYM\nto earn the BOULDER BADGE.\nStatus: {STR_VAR_1}"),
        .unlockFlag = FLAG_QUEST_3_ACTIVE,
        .completeFlag = FLAG_QUEST_3_COMPLETED,
        .itemId = ITEM_DOME_FOSSIL,
        .isPokemonIcon = FALSE,
        .group = QUEST_GROUP_MAIN,
        .mapsec = MAPSEC_PEWTER_CITY
    },
    {
        .name = COMPOUND_STRING("CERULEAN GYM CHALLENGE"),
        .desc = COMPOUND_STRING("Defeat LEADER MISTY at the CERULEAN GYM\nto earn the CASCADE BADGE.\nStatus: {STR_VAR_1}"),
        .unlockFlag = FLAG_QUEST_4_ACTIVE,
        .completeFlag = FLAG_QUEST_4_COMPLETED,
        .itemId = ITEM_BICYCLE,
        .isPokemonIcon = FALSE,
        .group = QUEST_GROUP_MAIN,
        .mapsec = MAPSEC_CERULEAN_CITY
    },
    {
        .name = COMPOUND_STRING("POKéMON CHAMPIONSHIP"),
        .desc = COMPOUND_STRING("Defeat the ELITE FOUR and challenge the\nCHAMPION at the INDIGO PLATEAU.\nStatus: {STR_VAR_1}"),
        .unlockFlag = FLAG_QUEST_5_ACTIVE,
        .completeFlag = FLAG_QUEST_5_COMPLETED,
        .itemId = ITEM_POKE_FLUTE,
        .isPokemonIcon = FALSE,
        .group = QUEST_GROUP_MAIN,
        .mapsec = MAPSEC_INDIGO_PLATEAU
    },
    
    {
        .name = COMPOUND_STRING("GENGAR EVOLUTION"),
        .desc = COMPOUND_STRING("Study the evolution of GENGAR and\ndocument its ghostly capabilities.\nStatus: {STR_VAR_1}"),
        .unlockFlag = FLAG_QUEST_7_ACTIVE,
        .completeFlag = FLAG_QUEST_7_COMPLETED,
        .itemId = SPECIES_GENGAR,
        .isPokemonIcon = TRUE,
        .group = QUEST_GROUP_RESEARCH,
        .mapsec = MAPSEC_LAVENDER_TOWN
    }
    
};

static const struct BgTemplate sBgTemplates[2] = {
    {
        .bg = 0,
        .charBaseIndex = 0,
        .mapBaseIndex = 31,
        .priority = 0
    }, {
        .bg = 1,
        .charBaseIndex = 3,
        .mapBaseIndex = 30,
        .priority = 1
    }
};

static const u8 sTextColors[][3] = {
    {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_WHITE, TEXT_COLOR_DARK_GRAY},
    {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_DARK_GRAY, TEXT_COLOR_LIGHT_GRAY},
    {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_LIGHT_GRAY, TEXT_COLOR_DARK_GRAY},
    {TEXT_COLOR_TRANSPARENT, TEXT_DYNAMIC_COLOR_1, TEXT_COLOR_DARK_GRAY}
};

static const struct WindowTemplate sWindowTemplates[] = {
    {
        .bg = 0,
        .tilemapLeft = 7,
        .tilemapTop = 1,
        .width = 19,
        .height = 12,
        .paletteNum = 15,
        .baseBlock = 0x02bf
    }, {
        .bg = 0,
        .tilemapLeft = 5,
        .tilemapTop = 14,
        .width = 25,
        .height = 6,
        .paletteNum = 13,
        .baseBlock = 0x0229
    }, {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 1,
        .width = 5,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = 0x0215
    }, DUMMY_WIN_TEMPLATE
};

static void QuestLogMenu_MainCB(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    DoScheduledBgTilemapCopiesToVram();
    UpdatePaletteFade();
}

static void QuestLogMenu_VBlankCB(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

void QuestLogMenu_Init(MainCallback callback)
{
    if ((sQuestLogMenuState = AllocZeroed(sizeof(struct QuestLogMenuResources))) == NULL)
    {
        SetMainCallback2(callback);
        return;
    }
    
    sQuestLogListMenuState.savedCallback = callback;
    sQuestLogListMenuState.scroll = sQuestLogListMenuState.row = 0;
    sQuestItemIconSpriteId = SPRITE_NONE;
    sActiveQuestGroup = QUEST_GROUP_MAIN;
    sIsQuestIconMon = FALSE;
    
    sQuestLogMenuState->nQuests = ARRAY_COUNT(sQuests);
    sQuestLogMenuState->nQuestsInGroup = 0;
    sQuestLogMenuState->maxShowed = 6;
    sQuestLogMenuState->scrollIndicatorArrowPairId = 0xFF;
    
    SetMainCallback2(QuestLogMenu_RunSetup);
}

static void QuestLogMenu_RunSetup(void)
{
    while (1)
    {
        if (QuestLogMenu_DoGfxSetup() == TRUE)
            break;
    }
}

static bool8 QuestLogMenu_DoGfxSetup(void)
{
    u8 taskId;
    switch (gMain.state)
    {
    case 0:
        SetVBlankHBlankCallbacksToNull();
        ClearScheduledBgCopiesToVram();
        gMain.state++;
        break;
    case 1:
        ScanlineEffect_Stop();
        gMain.state++;
        break;
    case 2:
        FreeAllSpritePalettes();
        gMain.state++;
        break;
    case 3:
        ResetPaletteFade();
        gMain.state++;
        break;
    case 4:
        ResetSpriteData();
        gMain.state++;
        break;
    case 5:
        ResetTasks();
        gMain.state++;
        break;
    case 6:
        if (QuestLogMenu_InitBgs())
        {
            sQuestLogMenuState->data[0] = 0;
            gMain.state++;
        }
        else
        {
            QuestLogMenu_FadeAndBail();
            return TRUE;
        }
        break;
    case 7:
        if (QuestLogMenu_LoadGraphics() == TRUE)
            gMain.state++;
        break;
    case 8:
        QuestLogMenu_InitWindows();
        PutWindowTilemap(0);
        PutWindowTilemap(1);
        PutWindowTilemap(2);
        gMain.state++;
        break;
    case 9:
        if (QuestLogMenu_AllocateResourcesForListMenu())
            gMain.state++;
        else
        {
            QuestLogMenu_FadeAndBail();
            return TRUE;
        }
        break;
    case 10:
        QuestLogMenu_BuildListMenuTemplate();
        gMain.state++;
        break;
    case 11:
        QuestLogMenu_PrintHeader();
        gMain.state++;
        break;
    case 12:
        taskId = CreateTask(Task_QuestLogMenuMain, 0);
        gTasks[taskId].data[0] = ListMenuInit(&gMultiuseListMenuTemplate, sQuestLogListMenuState.scroll, sQuestLogListMenuState.row);
        CopyWindowToVram(0, COPYWIN_FULL);
        gMain.state++;
        break;
    case 13:
        QuestLogMenu_PlaceScrollIndicatorArrows();
        gMain.state++;
        break;
    case 14:
        if (sQuestLogListMenuState.initialized == 1)
        {
            BlendPalettes(PALETTES_ALL, 16, RGB_BLACK);
        }
        gMain.state++;
        break;
    case 15:
        if (sQuestLogListMenuState.initialized == 1)
        {
            BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
        }
        else
        {
            BeginPCScreenEffect_TurnOn(0, 0, 0);
            sQuestLogListMenuState.initialized = 1;
            PlaySE(SE_PC_LOGIN);
        }
        gMain.state++;
        break;
    default:
        SetVBlankCallback(QuestLogMenu_VBlankCB);
        SetMainCallback2(QuestLogMenu_MainCB);
        return TRUE;
    }
    return FALSE;
}

static void QuestLogMenu_FadeAndBail(void)
{
    BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
    CreateTask(Task_QuestLogMenuWaitFadeAndBail, 0);
    SetVBlankCallback(QuestLogMenu_VBlankCB);
    SetMainCallback2(QuestLogMenu_MainCB);
}

static void Task_QuestLogMenuWaitFadeAndBail(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        SetMainCallback2(sQuestLogListMenuState.savedCallback);
        QuestLogMenu_FreeResources();
        DestroyTask(taskId);
    }
}

static bool8 QuestLogMenu_InitBgs(void)
{
    ResetVramOamAndBgCntRegs();
    sBg1TilemapBuffer = Alloc(0x800);
    if (sBg1TilemapBuffer == NULL)
        return FALSE;
    memset(sBg1TilemapBuffer, 0, 0x800);
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, sBgTemplates, ARRAY_COUNT(sBgTemplates));
    SetBgTilemapBuffer(1, sBg1TilemapBuffer);
    ResetAllBgsCoordinates();
    ScheduleBgCopyTilemapToVram(1);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_1D_MAP | DISPCNT_OBJ_ON);
    SetGpuReg(REG_OFFSET_BLDCNT , 0);
    ShowBg(0);
    ShowBg(1);
    return TRUE;
}

static bool8 QuestLogMenu_LoadGraphics(void)
{
    switch (sQuestLogMenuState->data[0])
    {
    case 0:
        ResetTempTileDataBuffers();
        DecompressAndCopyTileDataToVram(1, gItemPcTiles, 0, 0, 0);
        sQuestLogMenuState->data[0]++;
        break;
    case 1:
        if (FreeTempTileDataBuffersIfPossible() != TRUE)
        {
            DecompressDataWithHeaderWram(gItemPcTilemap, sBg1TilemapBuffer);
            sQuestLogMenuState->data[0]++;
        }
        break;
    case 2:
        LoadPalette(gItemPcBgPals, BG_PLTT_ID(0), 3 * PLTT_SIZE_4BPP);
        LoadPalette(GetTextWindowPalette(2), BG_PLTT_ID(15), PLTT_SIZE_4BPP);
        LoadPalette(GetTextWindowPalette(2), BG_PLTT_ID(13), PLTT_SIZE_4BPP);
        sQuestLogMenuState->data[0]++;
        break;
    default:
        sQuestLogMenuState->data[0] = 0;
        return TRUE;
    }
    return FALSE;
}

static bool8 QuestLogMenu_AllocateResourcesForListMenu(void)
{
    sListMenuItems = Alloc(sizeof(struct ListMenuItem) * (sQuestLogMenuState->nQuests + 1));
    if (sListMenuItems == NULL)
    {
        QuestLogMenu_FreeResources();
        QuestLogMenu_FadeAndBail();
        return FALSE;
    }
    return TRUE;
}

static void QuestLogMenu_BuildListMenuTemplate(void)
{
    u16 i, k = 0;

    for (i = 0; i < sQuestLogMenuState->nQuests; i++)
    {
        if (sQuests[i].group != sActiveQuestGroup)
            continue;

        if (FlagGet(sQuests[i].completeFlag))
        {
            StringCopy(sFormattedQuestNames[k], COMPOUND_STRING("{COLOR GREEN}{SHADOW LIGHT_GREEN}"));
            StringAppend(sFormattedQuestNames[k], sQuests[i].name);
        }
        else if (FlagGet(sQuests[i].unlockFlag))
        {
            StringCopy(sFormattedQuestNames[k], COMPOUND_STRING("{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY}"));
            StringAppend(sFormattedQuestNames[k], sQuests[i].name);
        }
        else
        {
            StringCopy(sFormattedQuestNames[k], COMPOUND_STRING("{COLOR RED}{SHADOW LIGHT_RED}????"));
        }
        sListMenuItems[k].name = sFormattedQuestNames[k];
        sListMenuItems[k].id = i;
        k++;
    }
    StringCopy(sFormattedQuestNames[k], COMPOUND_STRING("{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY}"));
    StringAppend(sFormattedQuestNames[k], gText_Cancel);
    sListMenuItems[k].name = sFormattedQuestNames[k];
    sListMenuItems[k].id = -2;
    k++;

    sQuestLogMenuState->nQuestsInGroup = k;
    sQuestLogMenuState->maxShowed = k <= 6 ? k : 6;

    gMultiuseListMenuTemplate.items = sListMenuItems;
    gMultiuseListMenuTemplate.totalItems = sQuestLogMenuState->nQuestsInGroup;
    gMultiuseListMenuTemplate.windowId = 0;
    gMultiuseListMenuTemplate.header_X = 0;
    gMultiuseListMenuTemplate.item_X = 9;
    gMultiuseListMenuTemplate.cursor_X = 1;
    gMultiuseListMenuTemplate.lettersSpacing = 1;
    gMultiuseListMenuTemplate.itemVerticalPadding = 2;
    gMultiuseListMenuTemplate.upText_Y = 2;
    gMultiuseListMenuTemplate.maxShowed = sQuestLogMenuState->maxShowed;
    gMultiuseListMenuTemplate.fontId = FONT_NORMAL;
    gMultiuseListMenuTemplate.cursorPal = 2;
    gMultiuseListMenuTemplate.fillValue = 0;
    gMultiuseListMenuTemplate.cursorShadowPal = 3;
    gMultiuseListMenuTemplate.moveCursorFunc = QuestLogMenu_MoveCursorFunc;
    gMultiuseListMenuTemplate.itemPrintFunc = NULL;
    gMultiuseListMenuTemplate.scrollMultiple = 0;
    gMultiuseListMenuTemplate.cursorKind = 0;
}

static void QuestLogMenu_AddItemIcon(u16 itemId, bool8 isPokemonIcon)
{
    if (sQuestItemIconSpriteId == SPRITE_NONE)
    {
        sIsQuestIconMon = isPokemonIcon;
        if (isPokemonIcon)
        {
            LoadMonIconPalettes();
            sQuestItemIconSpriteId = CreateMonIcon(itemId, SpriteCallbackDummy, 24 - 4, 140 - 6, 0, 0);
            if (sQuestItemIconSpriteId != MAX_SPRITES)
            {
                gSprites[sQuestItemIconSpriteId].oam.priority = 0;
            }
        }
        else
        {
            FreeSpriteTilesByTag(TAG_QUEST_ITEM_ICON);
            FreeSpritePaletteByTag(TAG_QUEST_ITEM_ICON);
            sQuestItemIconSpriteId = AddItemIconSprite(TAG_QUEST_ITEM_ICON, TAG_QUEST_ITEM_ICON, itemId);
            if (sQuestItemIconSpriteId != MAX_SPRITES)
            {
                gSprites[sQuestItemIconSpriteId].x2 = 24;
                gSprites[sQuestItemIconSpriteId].y2 = 140;
            }
        }
    }
}

static void QuestLogMenu_RemoveItemIcon(void)
{
    if (sQuestItemIconSpriteId != SPRITE_NONE)
    {
        if (sIsQuestIconMon)
        {
            FreeAndDestroyMonIconSprite(&gSprites[sQuestItemIconSpriteId]);
        }
        else
        {
            FreeSpriteTilesByTag(TAG_QUEST_ITEM_ICON);
            FreeSpritePaletteByTag(TAG_QUEST_ITEM_ICON);
            DestroySprite(&gSprites[sQuestItemIconSpriteId]);
        }
        sQuestItemIconSpriteId = SPRITE_NONE;
    }
}

static void QuestLogMenu_MoveCursorFunc(s32 itemIndex, bool8 onInit, struct ListMenu *list)
{
    const u8 *desc;
    if (onInit != TRUE)
        PlaySE(SE_SELECT);

    QuestLogMenu_RemoveItemIcon();

    if (itemIndex != -2)
    {
        if (FlagGet(sQuests[itemIndex].unlockFlag) || sQuests[itemIndex].unlockFlag == 0)
        {
            if (FlagGet(sQuests[itemIndex].completeFlag))
                StringCopy(gStringVar1, COMPOUND_STRING("Completed"));
            else
                StringCopy(gStringVar1, COMPOUND_STRING("Active"));

            StringExpandPlaceholders(gStringVar4, sQuests[itemIndex].desc);
            desc = gStringVar4;
            QuestLogMenu_AddItemIcon(sQuests[itemIndex].itemId, sQuests[itemIndex].isPokemonIcon);
        }
        else
        {
            desc = COMPOUND_STRING("{COLOR RED}{SHADOW LIGHT_RED}????");
            QuestLogMenu_AddItemIcon(ITEM_NONE, FALSE);
        }
    }
    else
    {
        desc = COMPOUND_STRING("Close the QUEST LOG.");
        QuestLogMenu_AddItemIcon(ITEM_FIELD_ARROW, FALSE);
    }
    FillWindowPixelBuffer(1, 0);
    QuestLogMenu_AddTextPrinterParameterized(1, FONT_NORMAL, desc, 0, 3, 2, 0, 0, 0);
    CopyWindowToVram(1, COPYWIN_FULL);
}

static const u8 *const sGroupHeaders[] = {
    COMPOUND_STRING("MAIN\nSTORY"),
    COMPOUND_STRING("SIDE\nQUESTS"),
    COMPOUND_STRING("RESEARCH")
};

static void QuestLogMenu_PrintHeader(void)
{
    FillWindowPixelBuffer(2, 0);
    QuestLogMenu_AddTextPrinterParameterized(2, FONT_SMALL, sGroupHeaders[sActiveQuestGroup], 0, 1, 0, 1, 0, 0);
    CopyWindowToVram(2, COPYWIN_FULL);
}

static void QuestLogMenu_PlaceScrollIndicatorArrows(void)
{
    if (sQuestLogMenuState->nQuestsInGroup > sQuestLogMenuState->maxShowed)
    {
        sQuestLogMenuState->scrollIndicatorArrowPairId = AddScrollIndicatorArrowPairParameterized(
            2,
            128,
            8,
            104,
            sQuestLogMenuState->nQuestsInGroup - sQuestLogMenuState->maxShowed,
            110,
            110,
            &sQuestLogListMenuState.scroll
        );
    }
}

static void QuestLogMenu_RemoveScrollIndicatorArrowPair(void)
{
    if (sQuestLogMenuState->scrollIndicatorArrowPairId != 0xFF)
    {
        RemoveScrollIndicatorArrowPair(sQuestLogMenuState->scrollIndicatorArrowPairId);
        sQuestLogMenuState->scrollIndicatorArrowPairId = 0xFF;
    }
}

static void QuestLogMenu_ChangeGroup(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    QuestLogMenu_RemoveScrollIndicatorArrowPair();
    DestroyListMenuTask(data[0], NULL, NULL);
    sQuestLogListMenuState.scroll = sQuestLogListMenuState.row = 0;
    QuestLogMenu_BuildListMenuTemplate();
    QuestLogMenu_PrintHeader();
    data[0] = ListMenuInit(&gMultiuseListMenuTemplate, 0, 0);
    CopyWindowToVram(0, COPYWIN_FULL);
    QuestLogMenu_PlaceScrollIndicatorArrows();
    QuestLogMenu_MoveCursorFunc(sListMenuItems[0].id, TRUE, NULL);
}

static void QuestLogMenu_FreeResources(void)
{
    QuestLogMenu_RemoveItemIcon();
    if (sQuestLogMenuState != NULL)
    {
        Free(sQuestLogMenuState);
        sQuestLogMenuState = NULL;
    }
    if (sBg1TilemapBuffer != NULL)
    {
        Free(sBg1TilemapBuffer);
        sBg1TilemapBuffer = NULL;
    }
    if (sListMenuItems != NULL)
    {
        Free(sListMenuItems);
        sListMenuItems = NULL;
    }
    FreeAllWindowBuffers();
}

static void Task_QuestLogMenuTurnOff1(u8 taskId)
{
    if (sQuestLogListMenuState.initialized == 1)
    {
        BeginPCScreenEffect_TurnOff(0, 0, 0);
        PlaySE(SE_PC_OFF);
    }
    gTasks[taskId].func = Task_QuestLogMenuTurnOff2;
}

static void Task_QuestLogMenuTurnOff2(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    if (!IsPCScreenEffectRunning_TurnOff())
    {
        DestroyListMenuTask(data[0], &sQuestLogListMenuState.scroll, &sQuestLogListMenuState.row);
        SetMainCallback2(sQuestLogListMenuState.savedCallback);
        QuestLogMenu_RemoveScrollIndicatorArrowPair();
        QuestLogMenu_FreeResources();
        sQuestLogListMenuState.initialized = 0;
    }
}

static void Task_QuestLogMenuFadeToMap(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    if (data[2] == 0)
    {
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        data[2] = 1;
    }
    else if (!gPaletteFade.active)
    {
        u16 mapsec = (u16)data[1];
        DestroyListMenuTask(data[0], &sQuestLogListMenuState.scroll, &sQuestLogListMenuState.row);
        QuestLogMenu_RemoveScrollIndicatorArrowPair();
        QuestLogMenu_FreeResources();
        DestroyTask(taskId);

        gRegionMapSelectedMapsecOverride = mapsec;
        gRegionMapHasOverride = TRUE;
        InitRegionMapWithExitCB(REGIONMAP_TYPE_NORMAL, CB2_ReturnToQuestLogFromMap);
    }
}

static void CB2_ReturnToQuestLogFromMap(void)
{
    gRegionMapSelectedMapsecOverride = 0;
    gRegionMapHasOverride = FALSE;

    if ((sQuestLogMenuState = AllocZeroed(sizeof(struct QuestLogMenuResources))) == NULL)
    {
        SetMainCallback2(sQuestLogListMenuState.savedCallback);
        return;
    }

    sQuestItemIconSpriteId = SPRITE_NONE;
    sIsQuestIconMon = FALSE;

    sQuestLogMenuState->nQuests = ARRAY_COUNT(sQuests);
    sQuestLogMenuState->nQuestsInGroup = 0;
    sQuestLogMenuState->maxShowed = 6;
    sQuestLogMenuState->scrollIndicatorArrowPairId = 0xFF;

    sQuestLogListMenuState.initialized = 1;

    gMain.state = 0;
    SetMainCallback2(QuestLogMenu_RunSetup);
}

static void Task_QuestLogMenuMain(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    s32 input;

    if (!IsPCScreenEffectRunning_TurnOn())
    {
        if (JOY_NEW(DPAD_LEFT))
        {
            PlaySE(SE_SELECT);
            if (sActiveQuestGroup == 0)
                sActiveQuestGroup = QUEST_GROUP_COUNT - 1;
            else
                sActiveQuestGroup--;
            QuestLogMenu_ChangeGroup(taskId);
            return;
        }
        else if (JOY_NEW(DPAD_RIGHT))
        {
            PlaySE(SE_SELECT);
            if (sActiveQuestGroup == QUEST_GROUP_COUNT - 1)
                sActiveQuestGroup = 0;
            else
                sActiveQuestGroup++;
            QuestLogMenu_ChangeGroup(taskId);
            return;
        }

        input = ListMenu_ProcessInput(data[0]);
        ListMenuGetScrollAndRow(data[0], &sQuestLogListMenuState.scroll, &sQuestLogListMenuState.row);
        switch (input)
        {
        case -1:
            break;
        case -2:
            PlaySE(SE_SELECT);
            gTasks[taskId].func = Task_QuestLogMenuTurnOff1;
            break;
        default:
            if (input >= 0 && input < ARRAY_COUNT(sQuests))
            {
                if ((FlagGet(sQuests[input].unlockFlag) || sQuests[input].unlockFlag == 0)
                    && sQuests[input].mapsec != MAPSEC_NONE)
                {
                    PlaySE(SE_SELECT);
                    data[1] = sQuests[input].mapsec;
                    data[2] = 0;
                    gTasks[taskId].func = Task_QuestLogMenuFadeToMap;
                }
                else
                {
                    PlaySE(SE_SELECT);
                }
            }
            break;
        }
    }
}

static void QuestLogMenu_InitWindows(void)
{
    InitWindows(sWindowTemplates);
}

static void QuestLogMenu_AddTextPrinterParameterized(u8 windowId, u8 fontId, const u8 *str, u8 x, u8 y, u8 letterSpacing, u8 lineSpacing, u8 speed, u8 colorIdx)
{
    AddTextPrinterParameterized4(windowId, fontId, x, y, letterSpacing, lineSpacing, sTextColors[colorIdx], speed, str);
}
