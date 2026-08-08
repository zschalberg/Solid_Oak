#include "global.h"
#include "bg.h"
#include "event_data.h"
#include "gpu_regs.h"
#include "main.h"
#include "map_name_popup_emerald.h"
#include "menu.h"
#include "overworld.h"
#include "palette.h"
#include "sound.h"
#include "string_util.h"
#include "task.h"
#include "text.h"
#include "text_window.h"
#include "toast_notification.h"
#include "window.h"
#include "constants/songs.h"

#define TOAST_WIN_PAL_NUM 14
#define MAX_QUEUE_SIZE 4
#define TOAST_TILEMAP_RIGHT_EDGE 29
#define TOAST_TILEMAP_TOP 0
#define TOAST_TEXT_X 6
#define TOAST_TEXT_PADDING_PX 12 // 6px left padding, 6px right padding

struct ToastMessage
{
    u8 header[32];
    u8 message[48];
    u16 sfx;
    u8 headerColorIndex; // 0 = Gold, 1 = Cyan, 2 = Green, 3 = White
};

struct ToastQueue
{
    struct ToastMessage queue[MAX_QUEUE_SIZE];
    u8 count;
};

static EWRAM_DATA struct ToastQueue sToastQueue = {0};

static const u8 sHeader_QuestStart[]    = _("NEW QUEST {R_BUTTON}");
static const u8 sHeader_QuestUpdate[]   = _("QUEST UPDATED {R_BUTTON}");
static const u8 sHeader_QuestComplete[] = _("QUEST COMPLETE {R_BUTTON}");

static void Task_ToastNotification(u8 taskId);
static u16 ToastCreateWindow(const u8 *header, const u8 *message, u8 headerColorIndex);
static void ProcessNextQueueItem(void);
static void ToastCopyStringTruncated(u8 *dest, const u8 *src, u16 destSize);

#define tState           data[0]
#define tTimer           data[1]
#define tYPos            data[2]
#define tWindowId        data[3]
#define tWindowExists    data[4]

enum
{
    STATE_WAIT_CLEAR, // Wait for the map name popup to finish (they share BG0VOFS)
    STATE_SLIDE_IN,
    STATE_HOLD,
    STATE_SLIDE_OUT,
};

void ShowQuestToast(u8 toastType, const u8 *questName)
{
    const u8 *header = sHeader_QuestStart;
    u16 sfx = SE_PIN;
    u8 colorIdx = 0;

    switch (toastType)
    {
    case TOAST_QUEST_START:
        header = sHeader_QuestStart;
        sfx = SE_PIN;
        colorIdx = 0;
        break;
    case TOAST_QUEST_UPDATE:
        header = sHeader_QuestUpdate;
        sfx = SE_SELECT;
        colorIdx = 1;
        break;
    case TOAST_QUEST_COMPLETE:
        header = sHeader_QuestComplete;
        sfx = SE_SUCCESS;
        colorIdx = 2;
        break;
    }

    ShowCustomToast(header, questName, sfx, colorIdx);
}

static void ToastCopyStringTruncated(u8 *dest, const u8 *src, u16 destSize)
{
    u16 i;

    if (src == NULL)
    {
        dest[0] = EOS;
        return;
    }

    for (i = 0; i < destSize - 1 && src[i] != EOS; i++)
        dest[i] = src[i];
    dest[i] = EOS;
}

void ShowCustomToast(const u8 *headerText, const u8 *messageText, u16 sfx, u8 headerColorIndex)
{
    struct ToastMessage *msg;

    if (sToastQueue.count >= MAX_QUEUE_SIZE)
        return;

    msg = &sToastQueue.queue[sToastQueue.count];
    ToastCopyStringTruncated(msg->header, headerText, sizeof(msg->header));
    ToastCopyStringTruncated(msg->message, messageText, sizeof(msg->message));
    msg->sfx = sfx;
    msg->headerColorIndex = headerColorIndex;
    sToastQueue.count++;

    // Don't spawn the task while in battle - ResumeMap() calls ResetTasks()
    // when returning to the field, which would destroy it before it can
    // display anything. FlushToastQueue() starts it once we're back.
    if (!gMain.inBattle && !IsToastNotificationActive())
    {
        ProcessNextQueueItem();
    }
}

void FlushToastQueue(void)
{
    if (sToastQueue.count > 0 && !IsToastNotificationActive())
    {
        ProcessNextQueueItem();
    }
}

static void ProcessNextQueueItem(void)
{
    u8 taskId;

    if (sToastQueue.count == 0)
        return;

    taskId = CreateTask(Task_ToastNotification, 80);
    gTasks[taskId].tState = STATE_WAIT_CLEAR;
    gTasks[taskId].tYPos = -32; // Start offscreen above
    gTasks[taskId].tWindowExists = FALSE;
}

static void PopQueue(void)
{
    u8 i;
    if (sToastQueue.count == 0)
        return;

    for (i = 0; i < sToastQueue.count - 1; i++)
    {
        sToastQueue.queue[i] = sToastQueue.queue[i + 1];
    }
    sToastQueue.count--;
}

static const u8 sHeaderColors[][3] = {
    [0] = { TEXT_COLOR_TRANSPARENT, TEXT_COLOR_RED,       TEXT_COLOR_LIGHT_RED   }, // Gold / Red header
    [1] = { TEXT_COLOR_TRANSPARENT, TEXT_COLOR_BLUE,      TEXT_COLOR_LIGHT_BLUE  }, // Cyan / Blue header
    [2] = { TEXT_COLOR_TRANSPARENT, TEXT_COLOR_GREEN,     TEXT_COLOR_LIGHT_GREEN }, // Green header
    [3] = { TEXT_COLOR_TRANSPARENT, TEXT_COLOR_WHITE,     TEXT_COLOR_DARK_GRAY   }, // White header
};
static const u8 sWoodTextColor[3] = { TEXT_COLOR_TRANSPARENT, TEXT_COLOR_WHITE, TEXT_COLOR_DARK_GRAY };

static const u16 sWoodPalette[16] = INCBIN_U16("graphics/map_popup/wood.gbapal");
static const u8 sWoodGfx[]        = INCBIN_U8("graphics/map_popup/wood.4bpp");

static u16 ToastCreateWindow(const u8 *header, const u8 *message, u8 headerColorIndex)
{
    const u8 *hColor = (headerColorIndex <= 3) ? sHeaderColors[headerColorIndex] : sHeaderColors[3];
    bool32 hasMessage = (message != NULL && message[0] != EOS);
    s32 headerWidthPx = GetStringWidth(FONT_SMALL, header, 0);
    s32 messageWidthPx = hasMessage ? GetStringWidth(FONT_NORMAL, message, 0) : 0;
    s32 maxTextWidthPx = (messageWidthPx > headerWidthPx) ? messageWidthPx : headerWidthPx;

    u8 widthTiles = (maxTextWidthPx + TOAST_TEXT_PADDING_PX + 7) / 8;
    u8 heightTiles = hasMessage ? 4 : 3;
    u8 tilemapLeft;

    if (widthTiles < 10)
        widthTiles = 10;
    if (widthTiles > 28)
        widthTiles = 28;

    // Right-align window on GBA screen
    tilemapLeft = (TOAST_TILEMAP_RIGHT_EDGE >= widthTiles) ? (TOAST_TILEMAP_RIGHT_EDGE - widthTiles) : 1;

    struct WindowTemplate windowTemplate = {
        .bg = 0,
        .tilemapLeft = tilemapLeft,
        .tilemapTop = TOAST_TILEMAP_TOP,
        .width = widthTiles,
        .height = heightTiles,
        .paletteNum = TOAST_WIN_PAL_NUM,
        .baseBlock = 0x0A0
    };
    u16 windowId = AddWindow(&windowTemplate);

    LoadPalette(sWoodPalette, BG_PLTT_ID(TOAST_WIN_PAL_NUM), PLTT_SIZE_4BPP);
    LoadStdWindowTiles(windowId, 0x01D);

    // Blit Wood Grain 4bpp texture across the window background
    {
        u16 x, y;
        u16 winWidthPx = widthTiles * 8;
        u16 winHeightPx = heightTiles * 8;

        for (y = 0; y < winHeightPx; y += 24)
        {
            for (x = 0; x < winWidthPx; x += 80)
            {
                u16 blitW = (winWidthPx - x > 80) ? 80 : (winWidthPx - x);
                u16 blitH = (winHeightPx - y > 24) ? 24 : (winHeightPx - y);
                BlitBitmapRectToWindow(windowId, sWoodGfx, 0, 0, 80, 24, x, y, blitW, blitH);
            }
        }
    }

    DrawTextBorderOuter(windowId, 0x01D, TOAST_WIN_PAL_NUM);
    PutWindowTilemap(windowId);

    if (hasMessage)
    {
        // 2-line mode: Line 1 = Header at Y=2, Line 2 = Message at Y=14
        AddTextPrinterParameterized3(windowId, FONT_SMALL, TOAST_TEXT_X, 2, hColor, 0, header);
        AddTextPrinterParameterized3(windowId, FONT_NORMAL, TOAST_TEXT_X, 14, sWoodTextColor, 0, message);
    }
    else
    {
        // 1-line mode: Line 1 = Header centered vertically at Y=6
        AddTextPrinterParameterized3(windowId, FONT_SMALL, TOAST_TEXT_X, 6, hColor, 0, header);
    }

    CopyWindowToVram(windowId, COPYWIN_FULL);
    return windowId;
}

static void Task_ToastNotification(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    switch (task->tState)
    {
    case STATE_WAIT_CLEAR:
        if (gMain.inBattle || IsMapNamePopUpActive() || gPaletteFade.active)
            return;

        if (sToastQueue.queue[0].sfx != 0)
            PlaySE(sToastQueue.queue[0].sfx);

        task->tWindowId = ToastCreateWindow(sToastQueue.queue[0].header, sToastQueue.queue[0].message, sToastQueue.queue[0].headerColorIndex);
        task->tWindowExists = TRUE;
        task->tState = STATE_SLIDE_IN;
        // fallthrough

    case STATE_SLIDE_IN:
        task->tYPos += 4;
        if (task->tYPos >= 0)
        {
            task->tYPos = 0;
            task->tState = STATE_HOLD;
            task->tTimer = 0;
        }
        SetGpuReg(REG_OFFSET_BG0VOFS, task->tYPos);
        break;

    case STATE_HOLD:
        task->tTimer++;
        if (task->tTimer >= 360) // 6.0 seconds (360 frames @ 60fps)
        {
            task->tTimer = 0;
            task->tState = STATE_SLIDE_OUT;
        }
        break;

    case STATE_SLIDE_OUT:
        task->tYPos -= 4;
        if (task->tYPos <= -32)
        {
            task->tYPos = -32;
            SetGpuReg(REG_OFFSET_BG0VOFS, 0);

            if (task->tWindowExists)
            {
                ClearWindow(task->tWindowId);
                CopyWindowToVram(task->tWindowId, COPYWIN_MAP);
                RemoveWindow(task->tWindowId);
                task->tWindowExists = FALSE;
            }

            PopQueue();
            DestroyTask(taskId);

            if (sToastQueue.count > 0)
            {
                ProcessNextQueueItem();
            }
            return;
        }
        SetGpuReg(REG_OFFSET_BG0VOFS, task->tYPos);
        break;
    }
}

void HideToastNotification(void)
{
    u8 taskId = FindTaskIdByFunc(Task_ToastNotification);
    if (taskId != TASK_NONE)
    {
        struct Task *task = &gTasks[taskId];
        if (task->tWindowExists)
        {
            ClearWindow(task->tWindowId);
            CopyWindowToVram(task->tWindowId, COPYWIN_MAP);
            RemoveWindow(task->tWindowId);
            task->tWindowExists = FALSE;
        }
        SetGpuReg(REG_OFFSET_BG0VOFS, 0);
        DestroyTask(taskId);
        sToastQueue.count = 0;
    }
}

bool32 IsToastNotificationActive(void)
{
    return FindTaskIdByFunc(Task_ToastNotification) != TASK_NONE;
}
