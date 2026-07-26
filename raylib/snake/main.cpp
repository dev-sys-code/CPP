#include "raylib.h"
#include <iostream>
#include <random>

void applePos(const int WIDTH, const int HEIGHT, Vector2& apple) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> x(0, WIDTH);
    std::uniform_int_distribution<> y(0, HEIGHT);
    apple.x = (float)x(gen);
    apple.y = (float)y(gen);
}

int main() {
    const int WIDTH{800}, HEIGHT{800};
    int playerWidth{35}, playerHeight{35}, temp{};
    const int playerAdd(playerWidth);

    InitWindow(WIDTH, HEIGHT, "Snake Game");
    SetTargetFPS(144);

    struct Player {
        Vector2 position{(WIDTH / 2) - (35 / 2), (HEIGHT / 2) - (35 / 2)};
        float speed{300.0f};
    };

    struct Apple {
        Vector2 position{};
        float radius{20.0f};
    };

    Player player;
    Apple apple;

    applePos(WIDTH, HEIGHT, apple.position);

    bool up{false}, left{false}, right{true}, down{false};

    while (!WindowShouldClose()) {
        float dt{GetFrameTime()};

        if (IsKeyPressed(KEY_W)) {
            up = true;
            left = false;
            right = false;
            down = false; 
        }

        if (IsKeyPressed(KEY_A)) {
            up = false;
            left = true;
            right = false;
            down = false; 
        }

        if (IsKeyPressed(KEY_D)) {
            up = false;
            left = false;
            right = true;
            down = false; 
        }

        if (IsKeyPressed(KEY_S)) {
            up = false;
            left = false;
            right = false;
            down = true;
        }
        
        if (up) player.position.y -= player.speed * dt;
        if (left) player.position.x -= player.speed * dt;
        if (right) player.position.x += player.speed * dt;
        if (down) player.position.y += player.speed * dt;

        Rectangle playerRec{player.position.x, player.position.y, (float)playerWidth, (float)playerHeight};

        if (CheckCollisionCircleRec(apple.position, apple.radius, playerRec)) {
            applePos(WIDTH, HEIGHT, apple.position);
            if (up || down) {
                playerHeight += 35;
                playerHeight += playerWidth;
            }

            if (left || right) {
                playerWidth += 35;
                playerWidth += playerHeight;
            }
        }

        if (player.position.y < 0) {
            player.position.y = 0;
            DrawText("Game Over", (WIDTH / 4) + 50, (HEIGHT / 2) - 50, 50.0f, BLACK);
            CloseWindow();
        }

        if (player.position.y > HEIGHT - playerHeight) {
            player.position.y = HEIGHT - playerHeight;
            DrawText("Game Over", (WIDTH / 4) + 50, (HEIGHT / 2) - 50, 50.0f, BLACK);
            CloseWindow();
        }

        if (player.position.x < 0) {
            player.position.x = 0;
            DrawText("Game Over", (WIDTH / 4) + 50, (HEIGHT / 2) - 50, 50.0f, BLACK);
            CloseWindow();
        }

        if (player.position.x > WIDTH - playerWidth) {
            player.position.x = WIDTH - playerWidth;
            DrawText("Game Over", (WIDTH / 4) + 50, (HEIGHT / 2) - 50, 50.0f, BLACK);
            CloseWindow();
        }

        BeginDrawing();
        
        ClearBackground(RAYWHITE);
        DrawRectangle(player.position.x, player.position.y, playerWidth, playerHeight, BLUE);

        DrawCircleV(apple.position, apple.radius, RED);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
