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

const sf::Texture &GameObject::getTexture() const {
    return _texture;
}

void GameObject::setTexture(const sf::Texture &texture) {
    _texture = texture;
    _sprite = sf::Sprite(_texture);
}

bool GameObject::isAlive() const {
    return _isAlive;
}