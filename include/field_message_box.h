#ifndef GUARD_FIELD_MESSAGE_BOX_H
#define GUARD_FIELD_MESSAGE_BOX_H

#include "global.h"

enum {
    FIELD_MESSAGE_BOX_HIDDEN,
    FIELD_MESSAGE_BOX_UNUSED,
    FIELD_MESSAGE_BOX_NORMAL,
    FIELD_MESSAGE_BOX_AUTO_SCROLL,
};

bool8 ShowFieldMessage(const u8 *message);
bool8 ShowFieldMessageFromBuffer(void);
bool8 ShowFieldAutoScrollMessage(const u8 *message);
void HideFieldMessageBox(void);
bool8 IsFieldMessageBoxHidden(void);
u8 GetFieldMessageBoxType(void);
void InitFieldMessageBox(void);
void SetSpeakerName(const u8 *name);
void RefreshSpeakerFromMugshots(void);
void SetSpeakerPosition(u8 position);
u8 GetSpeakerPosition(void);

struct ScriptContext;
void SetSpeaker(struct ScriptContext *ctx);
void SetSpeakerSide(struct ScriptContext *ctx);

#endif // GUARD_FIELD_MESSAGE_BOX_H
