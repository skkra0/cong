#ifndef PAD_H
#define PAD_H
#include <raylib.h>


typedef struct Pad {
    int upBtn;
    int downBtn;
    float speed;
    Rectangle rec;
} Pad;

void updatePad(Pad* pad);
void drawPad(Pad* pad);
#endif

