#include "raylib.h"

struct Player {
    Vector2 position;
    float width;
    float height;
    float speed;
};

int main() {
    const int WIDTH{850};
    const int HEIGHT{400};

    InitWindow(WIDTH, HEIGHT, "RAYLIB");

    Player player {
        { WIDTH / 2, HEIGHT / 2 },
        50.0f,
        50.0f,
        5.0f
    };

    while (!WindowShouldClose()) {

        if (IsKeyDown(KEY_W)) player.position.y -= player.speed;
        if (IsKeyDown(KEY_A)) player.position.x -= player.speed;
        if (IsKeyDown(KEY_S)) player.position.y += player.speed;
        if (IsKeyDown(KEY_D)) player.position.x += player.speed;

        ClearBackground(RAYWHITE);
        BeginDrawing();
        
        DrawRectangle(player.position.x, player.position.y, player.width, player.height, BLUE);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
