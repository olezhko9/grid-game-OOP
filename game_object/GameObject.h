#ifndef GAME_GAMEOBJECT_H
#define GAME_GAMEOBJECT_H

#include "SFML/Graphics.hpp"
#include "../utils/Vector2d.h"

class GameObject {
public:
    virtual void init() = 0;

    virtual void update(float) = 0;

    virtual void render(sf::RenderWindow *) = 0;

    const Vector2d &getPosition();

    void setPosition(const Vector2d &v);

    const sf::Sprite &getSprite() const;

    void setSprite(const sf::Sprite &sprite);

protected:
    Vector2d _position;

    sf::Sprite _sprite;
};

#endif //GAME_GAMEOBJECT_H