#include "snake.h"

void checkDirection(SnakeDirection *dir)
{
    if ((IsKeyPressed(KEY_RIGHT) || IsKeyPressed(KEY_D)) && *dir != DIR_LEFT)
        *dir = DIR_RIGHT;
    if ((IsKeyPressed(KEY_LEFT) || IsKeyPressed(KEY_A)) && *dir != DIR_RIGHT)
        *dir = DIR_LEFT;
    if ((IsKeyPressed(KEY_DOWN) || IsKeyPressed(KEY_S)) && *dir != DIR_UP)
        *dir = DIR_DOWN;
    if ((IsKeyPressed(KEY_UP) || IsKeyPressed(KEY_W)) && *dir != DIR_DOWN)
        *dir = DIR_UP;
}

void moveSnake(Vector2 *position, SnakeDirection *dir)
{
    switch (*dir)
    {
    case DIR_RIGHT:
        position->x += 50.0f;
        break;
    case DIR_LEFT:
        position->x -= 50.0f;
        break;
    case DIR_UP:
        position->y -= 50.0f;
        break;
    case DIR_DOWN:
        position->y += 50.0f;
        break;
    }
}

bool snakeCollisionParts(Snake snake)
{
    for (int i = snake.length - 1; i > 0; i--)
    {
        if (snake.parts[0].x == snake.parts[i].x && snake.parts[0].y == snake.parts[i].y)
        {
            return true;
        }
    }
    return false;
}