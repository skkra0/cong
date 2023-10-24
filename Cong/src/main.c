#include "main.h"

static void update(GameData* data);
static void draw(GameData* data);
static void initGameData(GameData* data);
static bool detectBallHitPad(Ball* ball, Pad* pad);

int main(void) {    
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
    data->player1 = (Player) {
        .pad = (Pad) {
            .rec = (Rectangle) {
                .x = 100,
                .y = 225,
                .width = 10,
                .height = 50
            },
            .speed = 300,
            .upBtn = KEY_W,
            .downBtn = KEY_S
        },
        .score = 0
    };
    data->player2 = (Player) {
        .pad = (Pad) {
            .rec = (Rectangle) {
                .x = 700,
                .y = 225,
                .width = 10,
                .height = 50
            },
            .speed = 300,
            .upBtn = KEY_UP,
            .downBtn = KEY_DOWN
        },
        .score = 0
    };
    
    data->ball = (Ball) {
        .position = (Vector2) {.x = 400, .y = 225}, // ?
        .radius = 5,
        .velocity = (Vector2) {.x = -100, .y = 80}
    };
}

static void update(GameData* data) {
    updatePad(&data->player1.pad);
    updatePad(&data->player2.pad);
    if (detectBallHitY(&data->ball)) {
        data->ball.velocity.y *= -1;
    }

    if (detectBallHitPad(&data->ball, &data->player1.pad) || detectBallHitPad(&data->ball, &data->player2.pad)) {
        data->ball.velocity.x *= -1.2;
        data->ball.velocity.y *= 0.8;
    }
    
    updateBall(&data->ball);
}

static void draw(GameData* data) {
    BeginDrawing();
    ClearBackground(BLACK);
    Vector2 from = {.x = (GetScreenWidth() / 2.f), .y = 5};
    Vector2 to = {.x = (GetScreenWidth() / 2.f), .y = (GetScreenHeight() - 5.f)};
    DrawLineEx(from, to, 3, WHITE);
    drawPad(&data->player1.pad);
    drawPad(&data->player2.pad);
    // drawScore
    // drawScore
    
    drawBall(&data->ball);
    EndDrawing();
}

bool detectBallHitPad(Ball* ball, Pad* pad) {
    return CheckCollisionCircleRec(ball->position, ball->radius, pad->rec);
}