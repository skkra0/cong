#include "main.h"
#include <stdio.h>

static void update(GameData* data);
static void draw(GameData* data);
static void initGameData(GameData* data);

int main(void) {
    printf("Hello, world!\n");
    

    int screenWidth = 800;
    int screenHeight = 450;
    InitWindow(screenWidth, screenHeight, "Pong");
    SetTargetFPS(60);

    GameData data;
    initGameData(&data);

    while (!WindowShouldClose()) {
        update(&data);
        draw(&data);
    }
}

static void initGameData(GameData* data) {
    data->player1 = (Pad) {
        .position = (Vector2) {.x = 100, .y = 225},
        .size = (Vector2) {.x = 10, .y = 50},
        .speed = 5,
        .upBtn = KEY_W,
        .downBtn = KEY_S
    };
    data->player2 = (Pad) {
        .position = (Vector2) {.x = 700, .y = 225},
        .size = (Vector2) {.x = 10, .y = 50},
        .speed = 5,
        .upBtn = KEY_UP,
        .downBtn = KEY_DOWN
    };
    data->ball = (Ball) {
        .position = (Vector2) {.x = GetScreenWidth() / 2.f, .y = GetScreenHeight() / 2.f}, // ?
        .radius = 5,
        .velocity = (Vector2) {.x = -2, .y = 0}
    };
    data->score1 = 0;
    data->score2 = 0;
}

static void update(GameData* data) {
    updatePad(&data->player1);
    updatePad(&data->player2);
    if (DetectBallHitY(&data->ball) {
        data->ball.velocity.x *= -1;
    }
    updateBall(&data->ball);
}

static void draw(GameData* data) {
    BeginDrawing();
    ClearBackground(BLACK);
    Vector2 from = {.x = (GetScreenWidth() / 2.f), .y = 5};
    Vector2 to = {.x = (GetScreenWidth() / 2.f), .y = (GetScreenHeight() - 5.f)};
    DrawLineEx(from, to, 3, WHITE);
    drawPad(&data->player1);
    drawPad(&data->player2);
    EndDrawing();
}
