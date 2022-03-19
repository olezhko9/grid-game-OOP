#include "Item.h"

void Item::update(float dt) {
    _sprite.setPosition(_position.x * TILE_SIZE, _position.y * TILE_SIZE);
}

void Item::render(sf::RenderWindow *window) {
    window->draw(_sprite);
}