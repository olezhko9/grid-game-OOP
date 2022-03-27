#include "Enemy.h"

Enemy::Enemy() : GameObject("enemy") {}

void Enemy::init() {
    _sprite.setPosition(_position.x * TILE_SIZE, _position.y * TILE_SIZE);
}

void Enemy::update(float dt) {
    _sprite.setPosition(_position.x * TILE_SIZE, _position.y * TILE_SIZE);
}

void Enemy::render(sf::RenderWindow *window) {
    window->draw(_sprite);
}

