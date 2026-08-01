/*
(LOCAL): Two player pong game (W + S (player one)), (I + K(player two))
*/

#include "raylib.h"

struct Entity {
    Vector2 position;
    Vector2 velocity;
    Vector2 size;
};

struct Ball {
    Vector2 position;
    Vector2 velocity;
    float radius;
};

int main() {
    const int WIDTH{800}, HEIGHT{450};

    int p1Score{}, p2Score{};

    InitWindow(WIDTH, HEIGHT, "Pong Game");

    Entity playerOne {
        { 50, HEIGHT / 2 - 50 },
        { 400.0f, 400.0f },
        { 20.0f, 100.0f }
    };

    Entity playerTwo {
        { WIDTH - 50, HEIGHT / 2 - 50 },
        { 400.0f, 400.0f },
        { 20.0f, 100.0f }
    };

    Ball ball {
        { WIDTH / 2, HEIGHT / 2 },
        { 600.0f, 600.0f },
        { 15.0f }
    };

    while (!WindowShouldClose()) {
        if (IsKeyDown(KEY_W)) playerOne.position.y -= playerOne.velocity.y * GetFrameTime();
        if (IsKeyDown(KEY_S)) playerOne.position.y += playerOne.velocity.y * GetFrameTime();
        if (IsKeyDown(KEY_I)) playerTwo.position.y -= playerTwo.velocity.y * GetFrameTime();
        if (IsKeyDown(KEY_K)) playerTwo.position.y += playerTwo.velocity.y * GetFrameTime();

        if (playerOne.position.y < 0) playerOne.position.y = 0;
        if (playerOne.position.y > HEIGHT - playerOne.size.y) playerOne.position.y = HEIGHT - playerOne.size.y;
        if (playerTwo.position.y < 0) playerTwo.position.y = 0;
        if (playerTwo.position.y > HEIGHT - playerTwo.size.y) playerTwo.position.y = HEIGHT - playerTwo.size.y;

        if (ball.position.y < 0) ball.velocity.y *= -1.0f;
        if (ball.position.y > HEIGHT) ball.velocity.y  *= -1.0f;
        if (ball.position.x < 0) ball.velocity.x *= -1.0f;
        if (ball.position.x > WIDTH) ball.velocity.x *= -1.0f;

        ball.position.y -= ball.velocity.y * GetFrameTime();
        ball.position.x -= ball.velocity.x * GetFrameTime();
        
        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawRectangleV(playerOne.position, playerOne.size, BLACK);
            DrawRectangleV(playerTwo.position, playerTwo.size, BLACK);
            DrawCircleV(ball.position, ball.radius, BLACK);
        EndDrawing();
    }
    return 0;
}
