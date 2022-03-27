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
            this->x * TILE_SIZE,
            this->y * TILE_SIZE
    );
}

bool Vector2d::operator==(Vector2d &other) const {
    return this->x == other.x && this->y == other.y;
}

Vector2d Vector2d::operator+(const Vector2d &other) const {
    return {this->x + other.x, this->y + other.y};
}

Vector2d Vector2d::operator-(const Vector2d &other) const {
    return {this->x - other.x, this->y - other.y};
}

Vector2d Vector2d::Up() {
    return {0, -1};
}

Vector2d Vector2d::Right() {
    return {1, 0};
}

Vector2d Vector2d::Down() {
    return {0, 1};
}

Vector2d Vector2d::Left() {
    return {-1, 0};
}
