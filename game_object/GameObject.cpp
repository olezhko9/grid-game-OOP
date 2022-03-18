#include "GameObject.h"

const Vector2d &GameObject::getPosition() {
    return _position;
}

void GameObject::setPosition(const Vector2d &position) {
    _position = position;
}

const sf::Sprite &GameObject::getSprite() const {
    return _sprite;
}

void GameObject::setSprite(const sf::Sprite &sprite) {
    _sprite = sprite;
}
