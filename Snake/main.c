#include "snake.h"
#include "grid.h"
#include "apple.h"

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 800;
    InitAudioDevice();
    InitWindow(screenWidth, screenHeight, "Snake ultra game");
    GameScreen currentScreen = GAMEPLAY;
    SnakeDirection dir = DIR_RIGHT;
    SetTargetFPS(60);
    Texture2D background = LoadTexture("assets/bggame.png");
    Texture2D apple = LoadTexture("assets/apple.png");
    bool appleOnBoard = false;
    int appleX = 0;
    int appleY = 0;
    int score = 0;
    int moveTimer = 0;
    int moveDelay = 7;

    Snake snake;
    snake.length = 3;
    snake.parts[0] = (Vector2){400, 400};
    snake.parts[1] = (Vector2){350, 400};
    snake.parts[2] = (Vector2){300, 400};

    Music music = LoadMusicStream("assets/music.mp3");
    PlayMusicStream(music);
    Sound appleEating = LoadSound("assets/eating3.wav");
    Sound deadSound = LoadSound("assets/dead.mp3");

    while (!WindowShouldClose())
    {
        switch (currentScreen)
        {
        case GAMEPLAY:
        {
            UpdateMusicStream(music);
            checkDirection(&dir);

            moveTimer++;
            if (moveTimer >= moveDelay)
            {
                moveTimer = 0;

                for (int i = snake.length - 1; i > 0; i--)
                    snake.parts[i] = snake.parts[i - 1];

                moveSnake(&snake.parts[0], &dir);

                Rectangle appleRect = {appleX, appleY, 50, 50};
                if (checkForCollision(&snake, appleRect, &appleOnBoard, &score))
                    PlaySound(appleEating);

                if (!appleOnBoard)
                {
                    appleX = getAppleCorX();
                    appleY = getAppleCorY();
                    appleOnBoard = true;
                }

                if (snakeCollisionParts(snake))
                {
                    PlaySound(deadSound);
                    currentScreen = ENDING;
                    score = 0;
                    StopMusicStream(music);
                }

                if (checkPlayerPositionForCollisionWall(snake.parts[0]))
                {
                    PlaySound(deadSound);
                    currentScreen = ENDING;
                    score = 0;
                    StopMusicStream(music);
                }
            }
        }
        break;
        case ENDING:
        {
            if (IsKeyPressed(KEY_ENTER))
            {
                snake.length = 3;
                snake.parts[0] = (Vector2){400, 400};
                snake.parts[1] = (Vector2){350, 400};
                snake.parts[2] = (Vector2){300, 400};
                dir = DIR_RIGHT;
                appleOnBoard = false;
                moveTimer = 0;
                currentScreen = GAMEPLAY;
                PlayMusicStream(music);
            }
        }
        break;
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawTexture(background, 0, 0, WHITE);
        switch (currentScreen)
        {
        case GAMEPLAY:
        {
            if (appleOnBoard)
                DrawTexture(apple, appleX, appleY, WHITE);

            for (int i = 0; i < snake.length; i++)
            {
                Color c = (i == 0) ? DARKGREEN : GREEN;
                DrawRectangle(snake.parts[i].x, snake.parts[i].y, 50, 50, c);
            }
            DrawText(TextFormat("Score: %d", score), 5, 5, 25, WHITE);
        }
        break;
        case ENDING:
        {
            DrawText("YOU HAVE LOST", 200, 330, 50, DARKBLUE);
            DrawText("PRESS ENTER TO RESTART", 115, 470, 40, DARKBLUE);
        }
        break;
        }
        EndDrawing();
    }
    CloseWindow();
    return 0;
}