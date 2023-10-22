#include "main.h"
#include <stdio.h>
#include <stdbool.h>

static void update(void);
static void draw(void);

const int radius = 5;
int ballX = 400;
int ballY = radius;
bool penDown = 1;

int main(void) {
    printf("Hello, world!\n");
    int screenWidth = 800;
    int screenHeight = 450;
    InitWindow(screenWidth, screenHeight, "Pong");
    SetTargetFPS(60);
    
    while (!WindowShouldClose()) {
        update();
        draw();
    }
}

static void update(void) {
    if (IsKeyDown(KEY_LEFT)) ballX -= 5;
    if (IsKeyDown(KEY_RIGHT)) ballX += 5;
    if (IsKeyDown(KEY_UP)) ballY -= 5;
    if (IsKeyDown(KEY_DOWN)) ballY += 5;
    if (IsKeyPressed(KEY_SPACE)) penDown = !penDown;
}

static void draw(void) {
    BeginDrawing();
    ClearBackground(BLACK);
    if (penDown) DrawCircle(ballX, ballY, radius, WHITE);
    EndDrawing();
}