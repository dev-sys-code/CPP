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
        200.0f,
        200.0f,
        5.0f
    };

    while (!WindowShouldClose()) {
        BeginDrawing();

        DrawRectangle(player.position.x, player.position.y, player.width, player.height, BLUE);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
