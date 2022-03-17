#ifndef GAME_GAMEOBJECT_H
#define GAME_GAMEOBJECT_H

#include "SFML/Graphics.hpp"
#include "../utils/Vector2d.h"

class GameObject {
public:
    virtual void init() = 0;

    virtual void update(float) = 0;

    virtual void render(sf::RenderWindow *) = 0;

    Vector2d getPosition();

    void setPosition(Vector2d);

protected:
    Vector2d _position;
};

#endif //GAME_GAMEOBJECT_H