#include "GameObject.h"

Vector2d GameObject::getPosition() {
    return _position;
}

void GameObject::setPosition(Vector2d position) {
    _position = position;
}
