#ifndef APPLE_H
#define APPLE_H
#include "snake.h"
#include "proj_settings.h"

int getAppleCorX();
int getAppleCorY();
void checkForCollision(Snake *snake, Rectangle appleRect, bool *appleOnBoard, int *score);

#endif