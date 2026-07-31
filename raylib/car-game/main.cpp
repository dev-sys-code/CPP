#include "raylib.h"
#include <iostream>
#include <random>

int random(const int num);

struct Player {
    Vector2 position;
    Vector2 velocity;
    Vector2 size;
};

struct Enemy {
    Vector2 position;
    Vector2 velocity;
    Vector2 size;
};

int main() {
    const int WIDTH{600};
    const int HEIGHT{600};

    int score{};

    InitWindow(WIDTH, HEIGHT, "Car game");\

    Player player {
        { ((float)HEIGHT / 2.0f) - 17.5f, ((float)WIDTH / 2.0f) - 17.5f },
        { 100.0f, 300.0f },
        { 50.0f, 85.0f }
    };

    Enemy enemy {
        { (float)random(WIDTH), -85.0f },
        { 100.0f, 350.0f },
        { 50.0f, 85.0f },
    };

    while (!WindowShouldClose()) {
        if (IsKeyDown(KEY_W)) player.position.y -= player.velocity.y * GetFrameTime();
        if (IsKeyDown(KEY_A)) player.position.x -= player.velocity.x * GetFrameTime();
        if (IsKeyDown(KEY_S)) player.position.y += player.velocity.y * GetFrameTime();
        if (IsKeyDown(KEY_D)) player.position.x += player.velocity.x * GetFrameTime();

        if (player.position.y < 0) player.position.y = 0;
        if (player.position.y > HEIGHT - player.size.y) player.position.y = HEIGHT - player.size.y;
        if (player.position.x < 0) player.position.x = 0;
        if (player.position.x > WIDTH - player.size.x) player.position.x = WIDTH - player.size.x;
        
        enemy.position.y += enemy.velocity.y * GetFrameTime();
        if (enemy.position.y > HEIGHT) {
            score ++;
            enemy.position.x = random(WIDTH);
            enemy.position.y = -200.0f; // not -85.0f because it looks odd
        }
        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawRectangleV(player.position, player.size, BLUE);
            DrawRectangleV(enemy.position, enemy.size, RED);
            DrawText(TextFormat("Score: %i", score), 10.0f, 10.0f, 20.0f, BLACK);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}

int random(const int num) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<int> random(10, num);
    return random(gen);
}
