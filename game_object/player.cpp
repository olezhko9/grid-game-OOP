#include <iostream>
#include "player.h"

Player::Player(const sf::Texture& texture) {
    _sprite.setTexture(texture);
}

void Player::init() {

}

void Player::render(sf::RenderWindow *window) {
    window->draw(_sprite);
}

void Player::update(float dt) {

}
