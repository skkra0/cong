#include "ball.h"

void updateBall(Ball* ball) {
  ball->position.x += GetFrameTime() * ball->velocity.x;
  ball-> position.y += GetFrameTime() * ball->velocity.y;
}

void drawBall(Ball* ball) {
  DrawCircleV(ball->position, ball->radius, RAYWHITE);
}

bool detectBallHitY(Ball* ball) {
  return ball->position.y <= ball->radius || ball->position.y >= GetScreenHeight() - ball->radius;
}

bool detectBallHitPad(Ball* ball, Pad* pad) {
  if (ball->position.x >= pad->position.x && ball->position.x <= pad->position.x + pad->size.x) {
    return ball->position.y >= pad->position.y - (pad->size.y / 2) && ball->position.y <= pad->position.y + (pad->size.y / 2);
  }
  return false;
}
