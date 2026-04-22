#include "grid.h"

bool checkPlayerPositionForCollisionWall(Vector2 PlayerPosition)
{
    float xCor = PlayerPosition.x;
    float yCor = PlayerPosition.y;

    if (xCor < 0 || xCor > 720)
    {
        return true;
    }
    if (yCor < 20 || yCor > 740)
    {
        return true;
    }
    return false;
}

