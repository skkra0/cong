// include raylib.h with header guards
#ifndef PAD_H
#define PAD_H
#include <raylib.h>


typedef struct Pad {
    int upBtn;
    int downBtn;
    float speed;
    Vector2 position;
    Vector2 size;
} Pad;

void updatePad(Pad* pad);
void drawPad(Pad* pad);
#endif

