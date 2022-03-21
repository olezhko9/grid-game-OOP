#include "Player.h"

Player::Player() : GameObject("player") {}

void Player::init() {}

void Player::render(sf::RenderWindow *window) {
    window->draw(_sprite);
}

void Player::update(float dt) {
    _sprite.setPosition(_position.x * TILE_SIZE, _position.y * TILE_SIZE);
}

int Player::addHp(int hp) {
    _hp += hp;
    return _hp;
}

int Player::getHp() const {
    return _hp;
}
