#include "raylib.h"
#include <iostream>
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
    int score{}, cpu_score{};

    InitWindow(WIDTH, HEIGHT, "RAYLIB");
    SetTargetFPS(144);

    Player player {
        { 20.0f, (HEIGHT / 2) - 100 / 2},
        { 400.0f }
    };

    Ball ball {
        { WIDTH / 2, randomNum(HEIGHT) },
        { 500.0f, 500.0f },
        { 15.0f }
    };

    CPU cpu {
        { WIDTH - 50.0f, (HEIGHT / 2) - 100 / 2 },
        { 350.0f }
    };

    Texture2D background{LoadTexture("images/Background.png")};

    while (!WindowShouldClose()) {
        float dt{GetFrameTime()};

        if (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP)) player.position.y -= player.speed * dt;
        if (IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN)) player.position.y += player.speed * dt;


        if (cpu.position.y + 50.0f < ball.position.y) {
            cpu.position.y += cpu.speed * dt;
        } else if (cpu.position.y + 50.0f > ball.position.y) {
            cpu.position.y -= cpu.speed * dt;
        }

        if (cpu.position.y < 0) cpu.position.y = 0;
        if (cpu.position.y > HEIGHT - 100) cpu.position.y = HEIGHT - 100;

        if (player.position.y < 0) player.position.y = 0;
        if (player.position.y > HEIGHT - 100) player.position.y = HEIGHT - 100;

        ball.position.x += ball.velocity.x * dt;
        ball.position.y += ball.velocity.y * dt;

        if (ball.position.y - ball.radius <= 0 || ball.position.y + ball.radius >= HEIGHT) {
            ball.velocity.y *= -1.0f;
        }

        if (ball.position.x + ball.radius >= WIDTH) {
            ball.velocity.x *= -1.0f;
            score ++;
        }

        if (ball.position.x - ball.radius <= 0) {
            ball.velocity.x *= -1.0f;
            cpu_score ++;
        }

        Rectangle playerRect{ player.position.x, player.position.y, 30.0f, 100.0f };
        Rectangle cpuRect{ cpu.position.x, cpu.position.y, 30.0f, 100.0f };

        if (CheckCollisionCircleRec(ball.position, ball.radius, playerRect)  && ball.velocity.x < 0) {
            ball.velocity.x *= -1.0f;
            score ++;
        }

        if (CheckCollisionCircleRec(ball.position, ball.radius, cpuRect)  && ball.velocity.x > 0) {
            ball.velocity.x *= -1.0f;
            cpu_score++;
        }

        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawTexture(background, 0, 0, WHITE);
            DrawText(TextFormat("%i", score), WIDTH / 4, HEIGHT / 2 - 50, 100.0f, BLACK);
            DrawText("|", WIDTH / 2, HEIGHT / 2 - 50, 100.0f, BLACK);
            DrawText(TextFormat("%i", cpu_score), WIDTH - WIDTH / 4, HEIGHT / 2 - 50, 100.0f, BLACK);
    
            DrawRectangle(player.position.x, player.position.y, 30, 100, BLACK); // player paddle
            DrawCircleV(ball.position, ball.radius, BLACK); // ball
            DrawRectangle(cpu.position.x, cpu.position.y, 30, 100, BLACK); // cpu paddle
        EndDrawing();
    }

    UnloadTexture(background);
    CloseWindow();
    return 0;
}

int randomNum(const int HEIGHT) {
    static std::random_device rd;
    static std::mt19937 gen(rd());

    std::uniform_int_distribution random(50, HEIGHT - 50);
    return random(gen);
}
