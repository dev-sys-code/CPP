#include "raylib.h"

struct Player {
    Vector2 pos;
    float speed;
};

int main() {
    InitWindow(800, 450, "Raylib");
    SetTargetFPS(144);

    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(RAYWHITE);
        DrawText("Raylib!", 300, 200, 20, BLACK);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
