#include "snake.h"

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 800;

    InitWindow(screenWidth, screenHeight, "Snake ultra shmultra mega game");
    Vector2 SquarePosition = {(float)screenWidth / 2, (float)screenHeight / 2};
    SnakeDirection dir = DIR_RIGHT;
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {

        checkDirection(&dir);
        moveSnake(&SquarePosition, &dir);

        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawRectangle(SquarePosition.x, SquarePosition.y, 100, 100, GREEN);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}