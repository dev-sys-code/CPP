#include "raylib.h"
#include <random>

int randomNum(const int HEIGHT);

struct Player {
    Vector2 position;
    float speed;
};

struct Ball {
    Vector2 position;
    Vector2 velocity;
    float radius;
};

struct CPU {
    Vector2 position;
    float speed;
};

int main() {
    const int WIDTH{850};
    const int HEIGHT{400};

    InitWindow(WIDTH, HEIGHT, "RAYLIB");
    SetTargetFPS(144);

    Player player {
        { 20.0f, (HEIGHT / 2) - 100 / 2},
        400.0f
    };

    Ball ball {
        { WIDTH / 2, randomNum(HEIGHT) },
        800.0f,
        15.0f
    };

    CPU cpu {
        { WIDTH - 50.0f, (HEIGHT / 2) - 100 / 2 },
        350.0f
    };

    while (!WindowShouldClose()) {
        float dt{GetFrameTime()};

        if (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP)) player.position.y -= player.speed * dt;
        if (IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN)) player.position.y += player.speed * dt;

        if (player.position.y < 0) player.position.y = 0;
        if (player.position.y > HEIGHT - 100) player.position.y = HEIGHT - 100;

        if (cpu.position.y + 50.0f < ball.position.y) {
            cpu.position.y += cpu.speed * dt;
        } else if (cpu.position.y + 50.0f > ball.position.y) {
            cpu.position.y -= cpu.speed * dt;
        }

        if (cpu.position.y < 0) cpu.position.y = 0;
        if (cpu.position.y > HEIGHT - 100) cpu.position.y = HEIGHT - 100;

        BeginDrawing();

        ClearBackground(RAYWHITE);
        DrawRectangle(player.position.x, player.position.y, 30, 100, BLACK); // player paddle
        DrawCircleV(ball.position, ball.radius, RED); // ball
        DrawRectangle(cpu.position.x, cpu.position.y, 30, 100, BLACK); // cpu paddle

        EndDrawing();
    }

    CloseWindow();
    return 0;
}

int randomNum(const int HEIGHT) {
    static std::random_device rd;
    static std::mt19937 gen(rd());

    std::uniform_int_distribution random(0, HEIGHT);
    return random(gen);
}
