#include <iostream>
#include "raylib.h"

int main() {
    int WIDTH{800};
    int HEIGHT{450};

    InitWindow(WIDTH, HEIGHT, "Raylib");
    SetTargetFPS(144);

    while (!WindowShouldClose()) {
        BeginDrawing();

        int PLAYER_WIDTH{50};
        int PLAYER_HEIGHT{50};

        ClearBackground(RAYWHITE);
        DrawRectangle((WIDTH / 2) - (PLAYER_WIDTH / 2), (HEIGHT / 2) - (PLAYER_HEIGHT / 2), 50, 50, BLUE);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
