#include "Player.h"

Player::Player() {}

void Player::init() {}

void Player::render(sf::RenderWindow *window) {
    window->draw(_sprite);
}

void Player::update(float dt) {
    _sprite.setPosition(_position.x * TILE_SIZE, _position.y * TILE_SIZE);
}
