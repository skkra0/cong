#include "pad.h"

void updatePad(Pad* pad) {
    if (IsKeyDown(pad->downBtn) && (pad->rec.y + pad->rec.height) < GetScreenHeight()) {
        pad->rec.y += GetFrameTime() * pad->speed;
    }
    if (IsKeyDown(pad->upBtn) && pad->rec.y > 0) {
        pad->rec.y -= GetFrameTime() * pad->speed;
    }
}

void drawPad(Pad* pad) {
    DrawRectangleRec(pad->rec, RAYWHITE);
}
