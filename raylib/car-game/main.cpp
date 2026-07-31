#include "raylib.h"
#include <iostream>

struct Player {
    Vector2 position;
    Vector2 velocity;
    Vector2 size;
};

int main() {
    int WIDTH{600};
    int HEIGHT{600};

    Player player {
        { ((float)HEIGHT / 2.0f) - 17.5f, ((float)WIDTH / 2.0f) - 17.5f },
        { 400.0f, 400.0f },
        { 35.0f, 35.0f }
    };

    InitWindow(WIDTH, HEIGHT, "Car game");

    while (!WindowShouldClose()) {
        BeginDrawing();
            DrawRectangleV(player.position, player.size, BLUE);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
