#include "grid.h"

bool checkPlayerPositionForCollisionWall(Vector2 PlayerPosition)
{
    float xCor = PlayerPosition.x;
    float yCor = PlayerPosition.y;

    if (xCor < 0 || xCor > 750)
        return true;
    if (yCor < 0 || yCor > 750)
        return true;

    return false;
}