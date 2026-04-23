#ifndef SNAKE_H
#define SNAKE_H
#define MAX_SNAKE_LENGTH 256

#include "proj_settings.h"

typedef enum
{
    DIR_UP,
    DIR_DOWN,
    DIR_LEFT,
    DIR_RIGHT
} SnakeDirection;

typedef struct
{
    Vector2 parts[MAX_SNAKE_LENGTH];
    int length;
} Snake;

void checkDirection(SnakeDirection *dir);
void moveSnake(Vector2 *pos, SnakeDirection *dir);
bool snakeCollisionParts(Snake snake);

#endif
