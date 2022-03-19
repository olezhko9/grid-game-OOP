#ifndef GAME_GAMEOBJECT_H
#define GAME_GAMEOBJECT_H

#include "SFML/Graphics.hpp"
#include "../utils/Vector2d.h"
#include <iostream>

class GameObject {
public:
    GameObject() = default;

    GameObject(std::string &name) : _name(name) {};

    virtual ~GameObject() = default;

    virtual void init() = 0;

    virtual void update(float) = 0;

    virtual void render(sf::RenderWindow *) = 0;

    const Vector2d &getPosition();

    void setPosition(const Vector2d &v);

    const sf::Sprite &getSprite() const;

    void setSprite(const sf::Sprite &sprite);

    const sf::Texture &getTexture() const;

    void setTexture(const sf::Texture &texture);

    bool isAlive() const;

protected:
    std::string _name;

    Vector2d _position = {-1, -1}; // положение объекта в индексах на поле

    sf::Sprite _sprite;
    sf::Texture _texture;

    bool _isAlive = true;
};

#endif //GAME_GAMEOBJECT_H