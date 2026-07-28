#include <iostream>
#include <vector>
#include "raylib.h"

struct Player {
    Vector2 position;
    Vector2 velocity;
    const float size{35.0f}; // size of each segment
};

Player snakeUp (int size,
    Vector2& position,
    Vector2 velocity) {
    for (int i{}; i < size; i++) {
        position.y += velocity.y;
    }

    std::cout << position.y << "\n";
    return {position.x, position.y};
}
void snakeLeft();
void snakeRight();
void snakeDown();

int main() {
    const int WIDTH{600};
    const int HEIGHT{600};
    float currentPos{40.0f};
    
    InitWindow(WIDTH, HEIGHT, "Game");

    
    Player player {
        { WIDTH / 2, HEIGHT / 2 },
        { 300.0f, 300.0f },
    };
    
    std::vector<Vector2> body{
        { WIDTH / 2, HEIGHT / 2 },
        { WIDTH / 2, HEIGHT / 2 + 40.0f },
        { WIDTH / 2, HEIGHT / 2 + 80.0f }
    };

    body.push_back({WIDTH / 2, HEIGHT / 2 + 80.0f});

    while (!WindowShouldClose()) {
        if (IsKeyPressed(KEY_W) || IsKeyPressed(KEY_UP)) {
            snakeUp(body.size() -1, {player.position}, {player.velocity});
        }

        if (IsKeyPressed(KEY_A) || IsKeyPressed(KEY_LEFT)) {

        }

        if (IsKeyPressed(KEY_S) || IsKeyPressed(KEY_DOWN)) {

        }

        if (IsKeyPressed(KEY_D) || IsKeyPressed(KEY_RIGHT)) {

        }

        BeginDrawing(); 
            ClearBackground(RAYWHITE);
                for (int i{body.size() - 1}; i >= 0; i--) {
                    if (i == 0) {
                        DrawRectangleV(body[i], { player.size, player.size }, BLUE);
                    } else {
                        DrawRectangleV(body[i], { player.size, player.size }, BLACK);
                    }
                }
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
