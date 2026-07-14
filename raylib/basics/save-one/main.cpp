#include "raylib.h"

struct Player {
    int position;
    int speed;
};

int main() {
    int width{800}, height{500};;

    const int PLAYERWIDTH{50}, PLAYERHEIGHT{50};

    InitWindow(width, height, "First program");

    Player p;
    p.position = 5;

    while (!WindowShouldClose()) {
        BeginDrawing();
        DrawRectangle((width / 2), (height / 2), PLAYERWIDTH, PLAYERHEIGHT, BLUE);

        if (IsKeyDown(KEY_W)) 
        EndDrawing();
    }

}
