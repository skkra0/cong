#ifndef BALL_H
#define BALL_H
#include <raylib.h>

typedef struct Ball {
    Vector2 position;
    Vector2 size;
    Vector2 velocity;
} Ball;

void updateBall(Ball* ball);
void drawBall(Ball* ball);
#endif
