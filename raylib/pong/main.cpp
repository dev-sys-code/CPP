#include "raylib.h"

struct Player {
    Vector2 position;
    float speed;
};

int main() {
    const int WIDTH{850};
    const int HEIGHT{400};

    InitWindow(WIDTH, HEIGHT, "RAYLIB");
    SetTargetFPS(144);

    Player player {
        { 20.0f, (HEIGHT / 2) - 100 / 2},
        400.0f
    };

    while (!WindowShouldClose()) {
        float dt{GetFrameTime()};

        if (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP)) player.position.y -= player.speed * dt;
        if (IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN)) player.position.y += player.speed * dt;

        if (player.position.y < 0) player.position.y = 0;
        if (player.position.y > HEIGHT - 100) player.position.y = HEIGHT - 100;

        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawRectangle(player.position.x, player.position.y, 30, 100, BLACK);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
