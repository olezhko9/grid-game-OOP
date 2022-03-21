#include "Item.h"

Item::Item() : GameObject("item") {}

void Item::init() {
    _sprite.setPosition(_position.x * TILE_SIZE, _position.y * TILE_SIZE);
}

void Item::update(float dt) {}

void Item::render(sf::RenderWindow *window) {
    window->draw(_sprite);
}
