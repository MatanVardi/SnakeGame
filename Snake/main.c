#include "snake.h"
#include "grid.h"

typedef enum GameScreen
{
    GAMEPLAY,
    ENDING
} GameScreen;

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 800;

    InitWindow(screenWidth, screenHeight, "Snake ultra game");
    GameScreen currentScreen = GAMEPLAY;
    Vector2 SquarePosition = {(float)screenWidth / 2, (float)screenHeight / 2};
    SnakeDirection dir = DIR_RIGHT;
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        switch (currentScreen)
        {
        case GAMEPLAY:
        {
            checkDirection(&dir);
            moveSnake(&SquarePosition, &dir);
            bool result = checkPlayerPositionForCollisionWall(SquarePosition);
            if (result)
            {
                currentScreen = ENDING;
            }
        }
        break;
        case ENDING:
        {
            if (IsKeyPressed(KEY_ENTER))
            {
                SquarePosition.x = (float)screenWidth / 2;
                SquarePosition.y = (float)screenHeight / 2;
                currentScreen = GAMEPLAY;
            }
        }
        break;
        }
        BeginDrawing();
        ClearBackground(RAYWHITE);
        switch (currentScreen)
        {
        case GAMEPLAY:
        {
            DrawRectangle(SquarePosition.x, SquarePosition.y, 100, 100, GREEN);
        }
        break;
        case ENDING:
        {
            DrawText("YOU HAVE LOST", 200, 375, 50, DARKBLUE);
        }
        break;
        }
        EndDrawing();
    }
    CloseWindow();

    return 0;
}
