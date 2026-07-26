#include "raylib.h"
#include <iostream>

int main() {
    const int WIDTH{800};
    const int HEIGHT{800};

    InitWindow(WIDTH, HEIGHT, "Snake Game");
    SetTargetFPS(144);

    struct Player {
        Vector2 position{WIDTH / 2 - 25, HEIGHT / 2 - 25};
        float speed{4000.0f};
    };

    Player player;
    
    while (!WindowShouldClose()) {
        float dt{GetFrameTime()};
        bool up{false}, left{false}, right{false}, down{false};

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

        BeginDrawing();
        
        ClearBackground(RAYWHITE);
        DrawRectangle(player.position.x, player.position.y, 50, 50, BLUE);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
