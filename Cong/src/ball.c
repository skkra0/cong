#include "ball.h"

void updateBall(Ball* ball) {
  ball->position.x += GetFrameTime() * ball->velocity.x;
  ball-> position.y += GetFrameTime() * ball->velocity.y;
}

void drawBall(Ball* ball) {
  DrawCircleV(ball->position, ball->radius, RAYWHITE);
}