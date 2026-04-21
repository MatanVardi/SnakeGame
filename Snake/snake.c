#include "snake.h"

void checkDirection(SnakeDirection *dir)
{
    if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D))
        *dir = DIR_RIGHT;
    if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A))
        *dir = DIR_LEFT;
    if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S))
        *dir = DIR_DOWN;
    if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W))
        *dir = DIR_UP;
}

void moveSnake(Vector2 *position, SnakeDirection *dir)
{
    switch (*dir)
    {
    case DIR_RIGHT:
        position->x += 5.0f;
        break;
    case DIR_LEFT:
        position->x -= 5.0f;
        break;
    case DIR_UP:
        position->y -= 5.0f;
        break;
    case DIR_DOWN:
        position->y += 5.0f;
        break;
    }
}