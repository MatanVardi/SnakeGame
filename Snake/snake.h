#ifndef SNAKE_H
#define SNAKE_H
#include "proj_settings.h"

typedef enum
{
    DIR_UP,
    DIR_DOWN,
    DIR_LEFT,
    DIR_RIGHT
} SnakeDirection;

void checkDirection(SnakeDirection *dir);
void moveSnake(Vector2 *pos, SnakeDirection *dir);

#endif
