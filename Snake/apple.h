#ifndef APPLE_H
#define APPLE_H
#include "snake.h"
#include "proj_settings.h"

int getAppleCorX();
int getAppleCorY();
bool checkForCollision(Snake *snake, Rectangle appleRect, bool *onBoard, int *score);

#endif