#include "ball.h"

void UpdateBall(Ball* ball) {
  ball->position.x += GetFrameTime() * ball->velocity.x;
  ball-> position.y += GetFrameTime() * ball->velocity.y;
}

void DrawBall(Ball* ball) {
  DrawCircleV(ball->position, ball->radius, RAYWHITE);
}

bool DetectBallHitY(Ball* ball) {
  return ball->position.y <= ball->radius || ball->position.y >= GetScreenHeight() - ball->radius;
}

