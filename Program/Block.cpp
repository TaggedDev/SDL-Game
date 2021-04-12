#include "Block.h"

bool Block::ColliderEnterBlock(int x, int y)
{
    if (x >= x1 && x <= x2)
        if (y >= y1 && y <= y2)
            return true;
    return false;
}
