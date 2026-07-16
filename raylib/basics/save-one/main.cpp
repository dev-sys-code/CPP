#include "raylib.h"

struct Player {
    Vector2 pos;
    float speed;
};

int main() {
    int width{800}, height{500};;

    InitWindow(width, height, "My first game");
    Player p{((float)width/2), ((float)height/2)};
    p.speed = 500.0f;

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        float dt{GetFrameTime()};

        if (IsKeyDown(KEY_W)) p.pos.y -= p.speed * dt;
        if (IsKeyDown(KEY_S)) p.pos.y += p.speed * dt;
        if (IsKeyDown(KEY_A)) p.pos.x -= p.speed * dt;
        if (IsKeyDown(KEY_D)) p.pos.x += p.speed * dt;

        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawRectangleV(p.pos, {50, 50}, BLUE);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
