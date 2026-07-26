#include "raylib.h"
#include <iostream>

struct Player {
    Vector2 position;
    Vector2 velocity;
    float speed;
};

int main() {
    const int WIDTH{450};
    const int HEIGHT{800};

    InitWindow(WIDTH, HEIGHT, "Flappy bird");
    SetTargetFPS(144);
    Color bg { 0, 175, 255, 255 };

    Player player {
        { WIDTH / 2 - 25, HEIGHT / 2 - 25 },
        { 200.0f, 200.0f },
        400.0f
    };

    while (!WindowShouldClose()) {
        float dt{GetFrameTime()};
        float gravity{900.0f};
        player.velocity.y += gravity * dt;
        if (IsKeyPressed(KEY_SPACE)) player.velocity.y = -550.0f;

        player.position.y += player.velocity.y * dt;


        if (player.position.y < 0) {
            player.position.y = 0;
            DrawText("Game Over!", WIDTH / 4 - 25, HEIGHT / 2 - 25, 50.0f, BLACK);
        }

        if (player.position.y > HEIGHT - 50) {
            player.position.y = HEIGHT - 50;
            DrawText("Game Over!", WIDTH / 4 - 25, HEIGHT / 2 - 25, 50.0f, BLACK);
        }

        BeginDrawing();
            ClearBackground(bg);
            DrawRectangle(player.position.x, player.position.y, 50, 50, BLACK);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
