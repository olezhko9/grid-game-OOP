#include "Vector2d.h"

Vector2d::Vector2d() {}

Vector2d::Vector2d(int x, int y) {
    this->x = x;
    this->y = y;
}

Vector2d Vector2d::getRandom(int min, int max) {
    return {
            Random::getInstance()->randomInt(min, max),
            Random::getInstance()->randomInt(min, max)
    };
}

Vector2d Vector2d::getRandom(int minX, int maxX, int minY, int maxY) {
    return {
            Random::getInstance()->randomInt(minX, maxX),
            Random::getInstance()->randomInt(minY, maxY)
    };
}

Vector2d Vector2d::toGlobal() {
    return Vector2d(
            this->x * CELL_SIZE + CELL_BOARD_WIDTH,
            this->y * CELL_SIZE + CELL_BOARD_WIDTH
    );
}
