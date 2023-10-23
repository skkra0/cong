#include "pad.h"

void updatePad(Pad* pad) {
    if (IsKeyDown(pad->downBtn) && (pad->position.y + pad->size.y) < GetScreenHeight()) {
        pad->position.y += pad->speed;
    }
    if (IsKeyDown(pad->upBtn) && pad->position.y > 0) {
        pad->position.y -= pad->speed;
    }
}

void drawPad(Pad* pad) {
    DrawRectangleV(pad->position, pad->size, RAYWHITE);
}