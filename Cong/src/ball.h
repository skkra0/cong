#ifndef BALL_H
#define BALL_H
#include <raylib.h>
#include <stdbool.h>

typedef struct Ball {
    Vector2 position;
    float radius;
    Vector2 velocity;
} Ball;

void updateBall(Ball* ball);
void drawBall(Ball* ball);
void detectBallHitY(Ball* ball);
void detectBallHitPad(Ball* ball, Pad* pad);
#endif
