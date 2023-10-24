#include "main.h"

static void Update(GameData* data);
static void Draw(GameData* data);
static void InitGameData(GameData* data);
static bool DetectBallHitPad(Ball* ball, Pad* pad);
static bool DetectBallMissed(Ball* ball, bool rightSide);

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 450;
const Vector2 SCREEN_CENTER = (Vector2) {
    .x = SCREEN_WIDTH / 2.f,
    .y = SCREEN_HEIGHT / 2.f
};

int main(void) {    
    int screenWidth = 800;
    int screenHeight = 450;
    InitWindow(screenWidth, screenHeight, "Pong");
    SetTargetFPS(60);

    GameData data;
    InitGameData(&data);

    while (!WindowShouldClose()) {
        Update(&data);
        Draw(&data);
    }
}

static void InitGameData(GameData* data) {
    data->player1 = (Player) {
        .pad = (Pad) {
            .rec = (Rectangle) {
                .x = 100,
                .y = 225,
                .width = 10,
                .height = 50
            },
            .speed = 550,
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
            .speed = 550,
            .upBtn = KEY_UP,
            .downBtn = KEY_DOWN
        },
        .score = 0
    };
    
    data->ball = (Ball) {
        .position = SCREEN_CENTER,
        .radius = 5,
        .velocity = (Vector2) {.x = -100, .y = 80}
    };
}

static void Update(GameData* data) {
    UpdatePad(&data->player1.pad);
    UpdatePad(&data->player2.pad);
    if (DetectBallHitY(&data->ball)) {
        data->ball.velocity.y *= -1;
    }

    if (DetectBallHitPad(&data->ball, &data->player1.pad) || DetectBallHitPad(&data->ball, &data->player2.pad)) {
        data->ball.velocity.x *= -1.4;
        data->ball.velocity.y *= 1.2;
    }
    
    UpdateBall(&data->ball);
}

static void Draw(GameData* data) {
    BeginDrawing();
    ClearBackground(BLACK);
    Vector2 from = {.x = (GetScreenWidth() / 2.f), .y = 5};
    Vector2 to = {.x = (GetScreenWidth() / 2.f), .y = (GetScreenHeight() - 5.f)};
    DrawLineEx(from, to, 3, WHITE);
    DrawPad(&data->player1.pad);
    DrawPad(&data->player2.pad);

    if (DetectBallMissed(&data->ball, false)) {
        data->player2.score++;
        for (int time = GetTime(); GetTime() < time + 1; ) {
        
        }

        data->ball.position = SCREEN_CENTER;
        data->ball.velocity = (Vector2) {.x = -100, .y = 80};
    }

    if (DetectBallMissed(&data->ball, true)) {
        data->player1.score++;
        for (int time = GetTime(); GetTime() < time + 1; ) {
        
        }

        data->ball.position = SCREEN_CENTER;
        data->ball.velocity = (Vector2) {.x = 100, .y = 80};
    }
    //DrawScore
    //DrawScore

    DrawBall(&data->ball);
    EndDrawing();
}

static bool DetectBallHitPad(Ball* ball, Pad* pad) {
    return CheckCollisionCircleRec(ball->position, ball->radius, pad->rec);
}

bool DetectBallMissed(Ball* ball, bool rightSide) {
    if (rightSide) {
        return ball->position.x > GetScreenWidth() + 2 * ball->radius;
    } else {
        return ball->position.x < -2 * ball->radius;
    }
}