#include "apple.h"

int getAppleCorX()
{
    int cell = rand() % 16;
    return cell * 50;
}

int getAppleCorY()
{
    int cell = rand() % 16;
    return cell * 50;
}

bool checkForCollision(Snake *snake, Rectangle appleRect, bool *onBoard, int *score)
{
    if (snake->parts[0].x == appleRect.x && snake->parts[0].y == appleRect.y)
    {
        snake->parts[snake->length] = snake->parts[snake->length - 1];
        snake->length++;
        *onBoard = false;
        (*score)++;
        return true;
    }
    return false;
}