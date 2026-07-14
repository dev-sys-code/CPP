#include "raylib.h"

struct Player {
    Vector2 position;
    float speed;
};

int main() {
    int width{800}, height{500};;

    const int PLAYERWIDTH{50}, PLAYERHEIGHT{50};

    InitWindow(width, height, "First program");

    Player p;
    p.position = {(float)width / 2, (float)height / 2};
    p.speed = 5.0f;

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        if (IsKeyDown(KEY_W)) p.position.y -= p.speed;
        if (IsKeyDown(KEY_A)) p.position.x -= p.speed;
        if (IsKeyDown(KEY_S)) p.position.y += p.speed;
        if (IsKeyDown(KEY_D)) p.position.x += p.speed;

        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawRectangle((int)p.position.x, (int)p.position.y, PLAYERWIDTH, PLAYERHEIGHT, BLUE);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
