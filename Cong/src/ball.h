#ifndef BALL_H
#define BALL_H
#include <raylib.h>

typedef struct Ball {
    Vector2 position;
    float radius;
    Vector2 velocity;
} Ball;

#endif
