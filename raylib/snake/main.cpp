#include "raylib.h"
#include <iostream>

int main() {
    const int WIDTH{800}, HEIGHT{800};
    const int playerWidth{50}, playerHeight{50};

    InitWindow(WIDTH, HEIGHT, "Snake Game");
    SetTargetFPS(144);

    struct Player {
        Vector2 position{(WIDTH / 2) - (playerWidth / 2), (HEIGHT / 2) - (playerHeight / 2)};
        float speed{300.0f};
    };

    Player player;


    bool up{false}, left{false}, right{false}, down{false};

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

        BeginDrawing();
        
        ClearBackground(RAYWHITE);
        DrawRectangle(player.position.x, player.position.y, 50, 50, BLUE);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
