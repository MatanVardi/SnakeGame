#include "apple.h"

int getAppleCorX()
{
    int min = 50;
    int max = 700;
    int randomNumX = (rand() % (max - min + 1)) + min;
    return randomNumX;
}
int getAppleCorY()
{
    int min = 50;
    int max = 700;
    int randomNumY = (rand() % (max - min + 1)) + min;
    return randomNumY;
}

bool checkForCollision(Snake *snake, Rectangle appleRect, bool *onBoard, int *score)
{
    if (CheckCollisionRecs((Rectangle){snake->parts[0].x, snake->parts[0].y, 50, 50}, appleRect))
    {
        snake->parts[snake->length] = snake->parts[snake->length - 1];
        snake->length++;
        *onBoard = false;
        (*score)++;
        return true;
    }
    return false;
}