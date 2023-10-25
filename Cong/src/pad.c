#include "pad.h"

void UpdatePad(Pad* pad) {
    if (IsKeyDown(pad->downBtn) && (pad->rec.y + pad->rec.height) < GetScreenHeight()) {
        pad->rec.y += pad->speed;
    }
    if (IsKeyDown(pad->upBtn) && pad->rec.y > 0) {
        pad->rec.y -= pad->speed;
    }
}

void DrawPad(Pad* pad) {
    DrawRectangleRec(pad->rec, RAYWHITE);
}
