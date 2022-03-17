#include <iostream>
#include "player.h"

Player::Player(const sf::Texture &texture) {
    _sprite.setTexture(texture);
}

void Player::init() {
    std::cout << _sprite.getTexture()->getSize().x << ", " << _sprite.getTexture()->getSize().y;
    sf::Vector2f scale(50.f / _sprite.getTexture()->getSize().x, 50.f / _sprite.getTexture()->getSize().y);
    _sprite.setScale(scale);
}

void Player::render(sf::RenderWindow *window) {
    window->draw(_sprite);
}

void Player::update(float dt) {
    _sprite.setPosition(_position.x * 50, _position.y * 50);
}
