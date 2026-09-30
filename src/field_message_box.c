#include "global.h"
#include "field_message_box.h"
#include "menu.h"
#include "quest_log.h"
#include "script.h"
#include "string_util.h"
#include "text_window.h"
#include "mugshot.h"
#include "window.h"
#include "constants/mugshots.h"
#include "constants/speaker_names.h"

// Speaker name plate: a small box sitting on the top-left edge of the
// dialogue frame (under the portrait, if one is shown).
#define NAMEBOX_TOP         13  // Straddles the dialogue frame's top border (row 14)
#define NAMEBOX_HEIGHT      2
#define NAMEBOX_MAX_WIDTH   12  // In tiles
#define NAMEBOX_MIN_PLATE_W 32  // In pixels

// The plate is drawn at the bottom of the 16px-tall window so it keeps straddling
// the frame border. FONT_SMALL caps occupy glyph rows 4-11 (incl. shadow), so
// NAMEBOX_TEXT_Y puts them 1px below the plate's inner ring.
#define NAMEBOX_FONT        FONT_SMALL
#define NAMEBOX_PLATE_H     13
#define NAMEBOX_PLATE_Y     (NAMEBOX_HEIGHT * 8 - NAMEBOX_PLATE_H)
#define NAMEBOX_TEXT_Y      (NAMEBOX_PLATE_Y + 3 - 4)
#define NAMEBOX_MIN_LEFT    2
#define NAMEBOX_MAX_RIGHT   28
// BG0 tiles start at charblock 2 (0x8000) and BG2's tilemap starts at 0xE000,
// so BG0 only has tiles 0x000-0x2FF. The plate needs up to 24 tiles (0x2C0-0x2D7).
#define NAMEBOX_BASE_BLOCK  0x2C0
#define NAMEBOX_PALETTE_NUM 15  // Same palette as the dialogue frame

// Colors in the dialogue frame palette
#define NAMEBOX_COLOR_OUTLINE 15
#define NAMEBOX_COLOR_RING    12
#define NAMEBOX_COLOR_FRAME_FILL 10 // White used inside the frame's edge tiles

// Horizontal centers of the left/right portraits (see mugshot.c)
#define NAMEBOX_ANCHOR_LEFT_X   36
#define NAMEBOX_ANCHOR_RIGHT_X  204

#define SPEAKER_NAME_BUFFER_SIZE 20

// sSpeakerId value for names given as a raw string rather than an SP_NAME_* preset
#define SP_NAME_CUSTOM 0xFF

static EWRAM_DATA u8 sMessageBoxType = 0;
static EWRAM_DATA u8 sSpeakerName[SPEAKER_NAME_BUFFER_SIZE] = {0};
static EWRAM_DATA u8 sSpeakerId = SP_NAME_NONE;
static EWRAM_DATA u8 sSpeakerPosition = MUGSHOT_LEFT;
// TRUE once a script uses setspeaker; stops portraits from overriding the name
static EWRAM_DATA bool8 sSpeakerExplicit = FALSE;
static EWRAM_DATA u8 sNameboxWindowId = 0; // Set to WINDOW_NONE in InitFieldMessageBox

static const u8 sSpeakerName_Agatha[] = _("Agatha");
static const u8 sSpeakerName_MrFuji[] = _("Mr. Fuji");
static const u8 sSpeakerName_ProfArbor[] = _("Prof. Arbor");
static const u8 sSpeakerName_Samuel[] = _("Samuel");

// SP_NAME_PLAYER is filled in at runtime from the save block
static const u8 *const sSpeakerNamesTable[SP_NAME_COUNT] =
{
    [SP_NAME_AGATHA]     = sSpeakerName_Agatha,
    [SP_NAME_MR_FUJI]    = sSpeakerName_MrFuji,
    [SP_NAME_PROF_ARBOR] = sSpeakerName_ProfArbor,
    [SP_NAME_SAMUEL]     = sSpeakerName_Samuel,
};

static void ExpandStringAndStartDrawFieldMessageBox(const u8 *str);
static void StartDrawFieldMessage(void);
static void DrawSpeakerNamebox(void);
static void RemoveSpeakerNamebox(void);

void InitFieldMessageBox(void)
{
    sMessageBoxType = FIELD_MESSAGE_BOX_HIDDEN;
    gTextFlags.canABSpeedUpPrint = FALSE;
    gTextFlags.useAlternateDownArrow = FALSE;
    gTextFlags.autoScroll = FALSE;
    sSpeakerName[0] = EOS;
    sSpeakerId = SP_NAME_NONE;
    sSpeakerPosition = MUGSHOT_LEFT;
    sSpeakerExplicit = FALSE;
    sNameboxWindowId = WINDOW_NONE; // Window buffers were already freed by the field reload
    InitMugshot();
}

static void CopySpeakerName(const u8 *name)
{
    u32 i = 0;

    if (name != NULL)
    {
        for (; i < SPEAKER_NAME_BUFFER_SIZE - 1 && name[i] != EOS; i++)
            sSpeakerName[i] = name[i];
    }
    sSpeakerName[i] = EOS;
}

static void SetSpeakerById(u32 id)
{
    sSpeakerId = id;
    if (id == SP_NAME_PLAYER)
        CopySpeakerName(gSaveBlock2Ptr->playerName);
    else if (id < SP_NAME_COUNT)
        CopySpeakerName(sSpeakerNamesTable[id]);
    else
        CopySpeakerName(NULL);
}

void SetSpeakerPosition(u8 position)
{
    sSpeakerPosition = (position == MUGSHOT_RIGHT) ? MUGSHOT_RIGHT : MUGSHOT_LEFT;
    sSpeakerExplicit = FALSE;
}

u8 GetSpeakerPosition(void)
{
    return sSpeakerPosition;
}

// Sets the name shown above the next message(s). NULL or an empty string hides it.
// The name is cleared when the message box closes.
void SetSpeakerName(const u8 *name)
{
    sSpeakerExplicit = TRUE;
    sSpeakerId = SP_NAME_CUSTOM;
    CopySpeakerName(name);

    if (IsMugshotActive(MUGSHOT_RIGHT) && !IsMugshotActive(MUGSHOT_LEFT))
    {
        sSpeakerPosition = MUGSHOT_RIGHT;
    }
    else if (IsMugshotActive(MUGSHOT_RIGHT) && IsMugshotActive(MUGSHOT_LEFT))
    {
        u8 rightSpeaker = GetMugshotSpeakerAt(MUGSHOT_RIGHT);
        u8 leftSpeaker = GetMugshotSpeakerAt(MUGSHOT_LEFT);
        const u8 *rightName = (rightSpeaker == SP_NAME_PLAYER) ? gSaveBlock2Ptr->playerName :
                              (rightSpeaker < SP_NAME_COUNT) ? sSpeakerNamesTable[rightSpeaker] : NULL;
        const u8 *leftName = (leftSpeaker == SP_NAME_PLAYER) ? gSaveBlock2Ptr->playerName :
                             (leftSpeaker < SP_NAME_COUNT) ? sSpeakerNamesTable[leftSpeaker] : NULL;

        if (rightName != NULL && StringCompare(name, rightName) == 0)
            sSpeakerPosition = MUGSHOT_RIGHT;
        else if (leftName != NULL && StringCompare(name, leftName) == 0)
            sSpeakerPosition = MUGSHOT_LEFT;
    }
}

// callnative for the `setspeaker` macro. Takes an SP_NAME_* constant or a string pointer.
void SetSpeaker(struct ScriptContext *ctx)
{
    u32 name = ScriptReadWord(ctx);

    if (name < SP_NAME_COUNT)
    {
        sSpeakerExplicit = TRUE;
        SetSpeakerById(name);

        if (IsMugshotActive(MUGSHOT_RIGHT) && GetMugshotSpeakerAt(MUGSHOT_RIGHT) == name)
            sSpeakerPosition = MUGSHOT_RIGHT;
        else if (IsMugshotActive(MUGSHOT_LEFT) && GetMugshotSpeakerAt(MUGSHOT_LEFT) == name)
            sSpeakerPosition = MUGSHOT_LEFT;
    }
    else
    {
        SetSpeakerName((const u8 *)name);
    }
}

void SetSpeakerSide(struct ScriptContext *ctx)
{
    u32 side = ScriptReadWord(ctx);
    sSpeakerPosition = (side == MUGSHOT_RIGHT) ? MUGSHOT_RIGHT : MUGSHOT_LEFT;
    sSpeakerExplicit = FALSE;
    RefreshSpeakerFromMugshots();
}

// Called whenever portraits change. Unless a script picked a speaker with
// setspeaker, the name follows the active portrait (left or right).
void RefreshSpeakerFromMugshots(void)
{
    u32 id;

    if (sSpeakerExplicit)
        return;

    if (sSpeakerPosition == MUGSHOT_RIGHT && IsMugshotActive(MUGSHOT_RIGHT))
        id = GetMugshotSpeakerAt(MUGSHOT_RIGHT);
    else if (sSpeakerPosition == MUGSHOT_LEFT && IsMugshotActive(MUGSHOT_LEFT))
        id = GetMugshotSpeakerAt(MUGSHOT_LEFT);
    else if (IsMugshotActive(MUGSHOT_LEFT))
    {
        id = GetMugshotSpeakerAt(MUGSHOT_LEFT);
        sSpeakerPosition = MUGSHOT_LEFT;
    }
    else if (IsMugshotActive(MUGSHOT_RIGHT))
    {
        id = GetMugshotSpeakerAt(MUGSHOT_RIGHT);
        sSpeakerPosition = MUGSHOT_RIGHT;
    }
    else
    {
        id = SP_NAME_NONE;
        sSpeakerPosition = MUGSHOT_LEFT;
    }

    SetSpeakerById(id);
}

// The window's bottom tile row replaces the dialogue frame's top edge in the tilemap, so
// the columns beside the plate must redraw that edge (DLG tile +2 in menu_message.png).
static void DrawNameboxMargin(u32 x, u32 w)
{
    if (w == 0)
        return;
    FillWindowPixelRect(sNameboxWindowId, PIXEL_FILL(0), x, 0, w, NAMEBOX_HEIGHT * 8);
    FillWindowPixelRect(sNameboxWindowId, PIXEL_FILL(NAMEBOX_COLOR_OUTLINE), x, 8 + 3, w, 1);
    FillWindowPixelRect(sNameboxWindowId, PIXEL_FILL(NAMEBOX_COLOR_RING), x, 8 + 4, w, 2);
    FillWindowPixelRect(sNameboxWindowId, PIXEL_FILL(NAMEBOX_COLOR_FRAME_FILL), x, 8 + 6, w, 2);
}

// Fills a rectangle of the plate, offset by the plate's position inside the window
#define PLATE_RECT(color, x, y, w, h) FillWindowPixelRect(sNameboxWindowId, PIXEL_FILL(color), plateX + (x), NAMEBOX_PLATE_Y + (y), w, h)

static void DrawSpeakerNamebox(void)
{
    static const u8 sTextColors[] = {TEXT_COLOR_WHITE, TEXT_COLOR_DARK_GRAY, TEXT_COLOR_LIGHT_GRAY};
    struct WindowTemplate template;
    s32 textWidth, anchorX, plateLeftPx, left, plateX;
    u32 width, plateW;

    if (sSpeakerName[0] == EOS || IsMsgSignpost() || gQuestLogState == QL_STATE_PLAYBACK)
        return;

    textWidth = GetStringWidth(NAMEBOX_FONT, sSpeakerName, 0);
    plateW = textWidth + 10; // Outline + ring + 3px padding per side
    if (plateW < NAMEBOX_MIN_PLATE_W)
        plateW = NAMEBOX_MIN_PLATE_W;
    if (plateW > NAMEBOX_MAX_WIDTH * 8)
        plateW = NAMEBOX_MAX_WIDTH * 8;

    // Sit under whichever portrait is speaking; default to the left side
    if (IsMugshotActive(MUGSHOT_RIGHT) && !IsMugshotActive(MUGSHOT_LEFT))
    {
        anchorX = NAMEBOX_ANCHOR_RIGHT_X;
    }
    else if (IsMugshotActive(MUGSHOT_RIGHT) && IsMugshotActive(MUGSHOT_LEFT))
    {
        if (sSpeakerPosition == MUGSHOT_RIGHT)
            anchorX = NAMEBOX_ANCHOR_RIGHT_X;
        else
            anchorX = NAMEBOX_ANCHOR_LEFT_X;
    }
    else
    {
        anchorX = NAMEBOX_ANCHOR_LEFT_X;
    }

    // The window is tile-aligned; the plate is centered on the anchor inside it
    plateLeftPx = anchorX - (s32)plateW / 2;
    left = plateLeftPx / 8;
    plateX = plateLeftPx - left * 8;
    width = (plateX + plateW + 7) / 8;
    if (left < NAMEBOX_MIN_LEFT)
    {
        left = NAMEBOX_MIN_LEFT;
        plateX = 0;
        width = (plateW + 7) / 8;
    }
    else if (left + width > NAMEBOX_MAX_RIGHT)
    {
        width = (plateW + 7) / 8;
        left = NAMEBOX_MAX_RIGHT - width;
        plateX = width * 8 - plateW;
    }

    template = CreateWindowTemplate(0, left, NAMEBOX_TOP, width, NAMEBOX_HEIGHT, NAMEBOX_PALETTE_NUM, NAMEBOX_BASE_BLOCK);
    sNameboxWindowId = AddWindow(&template);
    if (sNameboxWindowId == WINDOW_NONE)
        return;

    FillWindowPixelBuffer(sNameboxWindowId, PIXEL_FILL(TEXT_COLOR_WHITE));
    AddTextPrinterParameterized4(sNameboxWindowId, NAMEBOX_FONT, plateX + (plateW - textWidth) / 2, NAMEBOX_TEXT_Y,
                                 0, 0, sTextColors, TEXT_SKIP_DRAW, sSpeakerName);

    // Everything outside the plate is transparent. Drawn after the text so glyph backgrounds can't cover it.
    FillWindowPixelRect(sNameboxWindowId, PIXEL_FILL(0), 0, 0, width * 8, NAMEBOX_PLATE_Y);
    DrawNameboxMargin(0, plateX);
    DrawNameboxMargin(plateX + plateW, width * 8 - (plateX + plateW));

    PLATE_RECT(NAMEBOX_COLOR_OUTLINE, 0, 0, plateW, 1);
    PLATE_RECT(NAMEBOX_COLOR_OUTLINE, 0, NAMEBOX_PLATE_H - 1, plateW, 1);
    PLATE_RECT(NAMEBOX_COLOR_OUTLINE, 0, 0, 1, NAMEBOX_PLATE_H);
    PLATE_RECT(NAMEBOX_COLOR_OUTLINE, plateW - 1, 0, 1, NAMEBOX_PLATE_H);
    PLATE_RECT(NAMEBOX_COLOR_RING, 1, 1, plateW - 2, 1);
    PLATE_RECT(NAMEBOX_COLOR_RING, 1, NAMEBOX_PLATE_H - 2, plateW - 2, 1);
    PLATE_RECT(NAMEBOX_COLOR_RING, 1, 1, 1, NAMEBOX_PLATE_H - 2);
    PLATE_RECT(NAMEBOX_COLOR_RING, plateW - 2, 1, 1, NAMEBOX_PLATE_H - 2);
    // Rounded corners
    PLATE_RECT(0, 0, 0, 1, 1);
    PLATE_RECT(0, plateW - 1, 0, 1, 1);
    PLATE_RECT(0, 0, NAMEBOX_PLATE_H - 1, 1, 1);
    PLATE_RECT(0, plateW - 1, NAMEBOX_PLATE_H - 1, 1, 1);
    PLATE_RECT(NAMEBOX_COLOR_OUTLINE, 1, 1, 1, 1);
    PLATE_RECT(NAMEBOX_COLOR_OUTLINE, plateW - 2, 1, 1, 1);
    PLATE_RECT(NAMEBOX_COLOR_OUTLINE, 1, NAMEBOX_PLATE_H - 2, 1, 1);
    PLATE_RECT(NAMEBOX_COLOR_OUTLINE, plateW - 2, NAMEBOX_PLATE_H - 2, 1, 1);

    PutWindowTilemap(sNameboxWindowId);
    CopyWindowToVram(sNameboxWindowId, COPYWIN_FULL);
}

#undef PLATE_RECT

static void RemoveSpeakerNamebox(void)
{
    // Window 0 is always the dialogue box, so 0 also means "no plate"
    if (sNameboxWindowId == WINDOW_NONE || sNameboxWindowId == 0)
        return;

    ClearWindowTilemap(sNameboxWindowId);
    CopyWindowToVram(sNameboxWindowId, COPYWIN_MAP);
    RemoveWindow(sNameboxWindowId);
    sNameboxWindowId = WINDOW_NONE;
}

static void Task_DrawFieldMessageBox(u8 taskId)
{
    struct Task *task = &gTasks[taskId];
    switch (task->data[0])
    {
    case 0:
        if (gQuestLogState == QL_STATE_PLAYBACK)
        {
            gTextFlags.autoScroll = TRUE;
            LoadQuestLogWindowTiles(0, 0x200);
        }
        else if (!IsMsgSignpost())
            LoadMessageBoxAndBorderGfx();
        else
            LoadSignPostWindowFrameGfx();
        task->data[0]++;
        break;
    case 1:
        // Remove the previous plate first so the frame redraw restores the border under it
        RemoveSpeakerNamebox();
        DrawDialogueFrame(0, TRUE);
        DrawSpeakerNamebox();
        task->data[0]++;
        break;
    case 2:
        if (RunTextPrintersAndIsPrinter0Active() != TRUE)
        {
            sMessageBoxType = FIELD_MESSAGE_BOX_HIDDEN;
            DestroyTask(taskId);
        }
        break;
    }
}

static void CreateTask_DrawFieldMessageBox(void)
{
    CreateTask(Task_DrawFieldMessageBox, 80);
}

static void DestroyTask_DrawFieldMessageBox(void)
{
    u8 taskId = FindTaskIdByFunc(Task_DrawFieldMessageBox);
    if (taskId != 0xFF)
        DestroyTask(taskId);
}

bool8 ShowFieldMessage(const u8 *str)
{
    if (sMessageBoxType != FIELD_MESSAGE_BOX_HIDDEN)
        return FALSE;
    ExpandStringAndStartDrawFieldMessageBox(str);
    sMessageBoxType = FIELD_MESSAGE_BOX_NORMAL;
    return TRUE;
}

bool8 ShowFieldAutoScrollMessage(const u8 *str)
{
    if (sMessageBoxType != FIELD_MESSAGE_BOX_HIDDEN)
        return FALSE;
    sMessageBoxType = FIELD_MESSAGE_BOX_AUTO_SCROLL;
    ExpandStringAndStartDrawFieldMessageBox(str);
    return TRUE;
}

// Same as ShowFieldMessage, but instead of accepting a
// string arg it just prints whats already in gStringVar4
bool8 ShowFieldMessageFromBuffer(void)
{
    if (sMessageBoxType != FIELD_MESSAGE_BOX_HIDDEN)
        return FALSE;
    sMessageBoxType = FIELD_MESSAGE_BOX_NORMAL;
    StartDrawFieldMessage();
    return TRUE;
}

static void ExpandStringAndStartDrawFieldMessageBox(const u8 *str)
{
    StringExpandPlaceholders(gStringVar4, str);
    AddTextPrinterForMessage(TRUE);
    CreateTask_DrawFieldMessageBox();
}

static void StartDrawFieldMessage(void)
{
    AddTextPrinterForMessage(TRUE);
    CreateTask_DrawFieldMessageBox();
}

void HideFieldMessageBox(void)
{
    DestroyTask_DrawFieldMessageBox();
    RemoveSpeakerNamebox();
    ClearDialogWindowAndFrame(0, TRUE);
    sMessageBoxType = FIELD_MESSAGE_BOX_HIDDEN;
    sSpeakerExplicit = FALSE;
    SetSpeakerById(SP_NAME_NONE);
}

u8 GetFieldMessageBoxType(void)
{
    return sMessageBoxType;
}

bool8 IsFieldMessageBoxHidden(void)
{
    if (sMessageBoxType == FIELD_MESSAGE_BOX_HIDDEN)
        return TRUE;
    else
        return FALSE;
}
