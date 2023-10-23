#ifndef CONG_MAIN_H
#define CONG_MAIN_H

#include <raylib.h>
#include "pad.h"

typedef struct GameData {
    Pad player1;
    Pad player2;
    Ball ball;
    int score1;
    int score2;
} GameData;

#endif
