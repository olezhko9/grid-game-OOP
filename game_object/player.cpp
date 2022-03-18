#include "player.h"

Player::Player(const sf::Texture &texture) {
    _sprite.setTexture(texture);
}

void Player::init() {
    sf::Vector2f scale(
            TILE_SIZE / (float) _sprite.getTexture()->getSize().x,
            TILE_SIZE / (float) _sprite.getTexture()->getSize().y
    );
    _sprite.setScale(scale);
}

void Player::render(sf::RenderWindow *window) {
    window->draw(_sprite);
}

void Player::update(float dt) {
    _sprite.setPosition(_position.x * TILE_SIZE, _position.y * TILE_SIZE);
}
