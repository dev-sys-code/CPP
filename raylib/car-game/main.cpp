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

    InitWindow(WIDTH, HEIGHT, "Car game");

    while (!WindowShouldClose()) {
        BeginDrawing();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
