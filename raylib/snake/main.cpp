#include <iostream>
#include <vector>
#include "raylib.h"

struct Player {
    Vector2 position;
    Vector2 velocity;
    int boxes; // size of snake
    const float size{35.0f}; // size of each 'box'
};

int main() {
    const int WIDTH{600};
    const int HEIGHT{600};
    float currentPos{40.0f};
    InitWindow(WIDTH, HEIGHT, "Game");

    
    Player player {
        { WIDTH / 2, HEIGHT / 2 },
        { 300.0f, 300.0f },
        { 2 },
    };
    
    std::vector<Vector2> body{
        { WIDTH / 2, HEIGHT / 2 },
        { WIDTH / 2, HEIGHT / 2 + 40.0f }
    };

    body.push_back({WIDTH / 2, HEIGHT / 2 + 80.0f});

    while (!WindowShouldClose()) {
        BeginDrawing(); 
            ClearBackground(RAYWHITE);
                for (int i{body.size() - 1}; i >= 0; i--) {
                    if (i == 0) {
                        DrawRectangleV(body[i], { player.size, player.size }, RED);
                    } else {
                        DrawRectangleV(body[i], { player.size, player.size }, BLACK);
                    }
                }
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
