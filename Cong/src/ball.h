#ifndef BALL_H
#define BALL_H
#include <raylib.h>
#include <stdbool.h>

typedef struct Ball {
    Vector2 position;
    float radius;
    Vector2 velocity;
} Ball;

void UpdateBall(Ball* ball);
void DrawBall(Ball* ball);
bool DetectBallHitY(Ball* ball);
#endif
