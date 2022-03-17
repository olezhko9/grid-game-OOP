#ifndef GAME_VECTOR2D_H
#define GAME_VECTOR2D_H

#include "random.h"

class Vector2d {
public:
    int x;
    int y;

    Vector2d();

    Vector2d(int x, int y);

    static Vector2d getRandom(int min, int max);

    static Vector2d getRandom(int minX, int maxX, int minY, int maxY);
};

#endif //GAME_VECTOR2D_H
