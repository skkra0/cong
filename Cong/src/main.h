#ifndef CONG_MAIN_H
#define CONG_MAIN_H

#include <raylib.h>
#include "pad.h"

typedef struct Player {
    Pad pad;
    int score;
} Player;

typedef struct GameData {
    Player player1;
    Player player2;
    Ball ball;
} GameData;

#endif
