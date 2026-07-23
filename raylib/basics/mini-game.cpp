#include <iostream>
#include "raylib.h"
#include <random>

int makeRandomNum(const int numOne, const int numTwo);

int main() {
    const int WIDTH{800};
    const int HEIGHT{450};

    const int PLAYER_WIDTH{50};
    const int PLAYER_HEIGHT{50};

    const int ENEMY_SIZE{15};

    InitWindow(WIDTH, HEIGHT, "Raylib");
    SetTargetFPS(144);

    float playerX{(WIDTH / 2.0f) - (PLAYER_WIDTH / 2.0f)};
    float playerY{(HEIGHT / 2.0f) - (PLAYER_HEIGHT / 2.0f)};
    float playerSpeed{5.0f};

    int result{};

    int enemyY{makeRandomNum(0, HEIGHT)};
    int enemyX{makeRandomNum(0, WIDTH)};

    while (!WindowShouldClose()) {
        if (IsKeyDown(KEY_W)) playerY -= playerSpeed;
        if (IsKeyDown(KEY_S)) playerY += playerSpeed;
        if (IsKeyDown(KEY_A)) playerX -= playerSpeed;
        if (IsKeyDown(KEY_D)) playerX += playerSpeed;

        if (playerY < 0) playerY = 0;
        if (playerX < 0) playerX = 0;
        if (playerY > HEIGHT - PLAYER_HEIGHT) playerY = (HEIGHT - PLAYER_HEIGHT);
        if (playerX > WIDTH - PLAYER_WIDTH) playerX = (WIDTH - PLAYER_WIDTH);

        BeginDrawing();
        
        ClearBackground(RAYWHITE);
        DrawRectangle(playerX, playerY, PLAYER_WIDTH, PLAYER_HEIGHT, BLUE);
        DrawCircle(enemyX, enemyY, ENEMY_SIZE, RED);

        if (playerX == (enemyX + ENEMY_SIZE)) DrawText("Game Over", (WIDTH / 2), (HEIGHT - 2), 20, BLACK);
        if (playerY == (enemyY + ENEMY_SIZE)) DrawText("Game Over", (WIDTH / 2), (HEIGHT - 2), 20, BLACK);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}

int makeRandomNum(const int numOne, const int numTwo) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> random(numOne, numTwo);

    return random(gen);
}
