#include <iostream>
#include "raylib.h"

struct Player {
    Vector2 position;
    Vector2 speed;
    float radius;
    Color color;
};

void reset(Player &player, const int WIDTH, const int HEIGHT) {
    player.position.x = (float)WIDTH / 2;
    player.position.y = (float)HEIGHT / 2;
}

int main() {
    const int WIDTH{800};
    const int HEIGHT{450};
    InitWindow(WIDTH, HEIGHT, "Raylib structs");

    Player player {
        { (float)WIDTH / 2, (float)HEIGHT / 2 },
        { 4.0f, 4.0f},
        20.0f,
        BLUE
    };
    
    SetTargetFPS(144);

    while (!WindowShouldClose()) {
        if (IsKeyDown(KEY_W)) player.position.y -= player.speed.y;
        if (IsKeyDown(KEY_S)) player.position.y += player.speed.y;
        if (IsKeyDown(KEY_A)) player.position.x -= player.speed.x;
        if (IsKeyDown(KEY_D)) player.position.x += player.speed.x;

        if (IsKeyDown(KEY_R)) reset(player, WIDTH, HEIGHT);

        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawCircleV(player.position, player.radius, player.color);
        EndDrawing();

    }
    CloseWindow();
    return 0;
}
