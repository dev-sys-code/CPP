#include <iostream>
#include "raylib.h"
#include <random>

struct Entity {
    Vector2 position;
    Vector2 speed;
    float radius;
    Color color;
};

void reset(Entity &player, const int WIDTH, const int HEIGHT);
int randomNumberGen(const int SIZE);

int main() {
    const int WIDTH{800};
    const int HEIGHT{450};
    InitWindow(WIDTH, HEIGHT, "Raylib");

    Entity player {
        { (float)WIDTH / 2, (float)HEIGHT / 2 },
        { 4.0f, 4.0f},
        20.0f,
        BLUE
    };

    Entity enemy {
        { (float)randomNumberGen(WIDTH) - 20.0f, (float)randomNumberGen(HEIGHT) - 20.0f},
        { 4.0f, 4.0f },
        20.0f,
        RED
    };
    
    SetTargetFPS(144);

    while (!WindowShouldClose()) {
        if (IsKeyDown(KEY_W)) player.position.y -= player.speed.y;
        if (IsKeyDown(KEY_S)) player.position.y += player.speed.y;
        if (IsKeyDown(KEY_A)) player.position.x -= player.speed.x;
        if (IsKeyDown(KEY_D)) player.position.x += player.speed.x;

        if (IsKeyDown(KEY_R)) reset(player, WIDTH, HEIGHT);

        BeginDrawing();

        ClearBackground(RAYWHITE);
        DrawCircleV(player.position, player.radius, player.color);
        DrawCircleV(enemy.position, enemy.radius, enemy.color);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}

void reset(Entity &player, const int WIDTH, const int HEIGHT) {
    player.position.x = (float)WIDTH / 2;
    player.position.y = (float)HEIGHT / 2;
}

int randomNumberGen(const int SIZE) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> random(0, SIZE);

    return random(gen);
}
