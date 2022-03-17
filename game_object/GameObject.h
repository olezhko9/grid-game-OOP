#ifndef GAME_GAMEOBJECT_H
#define GAME_GAMEOBJECT_H

#include "SFML/Graphics.hpp"

class GameObject {
public:
    virtual void init() = 0;

    virtual void update(float) = 0;

    virtual void render(sf::RenderWindow *) = 0;
};

#endif //GAME_GAMEOBJECT_H