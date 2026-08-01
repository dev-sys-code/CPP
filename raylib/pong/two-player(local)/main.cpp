/*
(LOCAL): Two player pong game (W + S (player one)), (I + K(player two))
*/

#include "raylib.h"

struct Entity {
    Vector2 position;
    Vector2 velocity;
    Vector2 size;
};

int main() {
    int WIDTH{800};
    int HEIGHT{450};

    InitWindow(WIDTH, HEIGHT, "Pong Game");

    Entity playerOne {
        { 100, HEIGHT / 2 - 50 },
        { 400.0f, 400.0f },
        { 20.0f, 100.0f }
    };

    Entity playerTwo {
        { WIDTH - 100, HEIGHT / 2 - 50 },
        { 400.0f, 400.0f },
        { 20.0f, 100.0f }
    };

    Entity ball {
        { WIDTH / 2 - 20.0f, HEIGHT / 2 - 20.0f },
        { 600.0f, 600.0f },
        { 40.0f, 40.0f }
    };

    while (!WindowShouldClose()) {
        BeginDrawing();
        EndDrawing();
    }
    return 0;
}
