#ifndef GAME_GAMEOBJECT_H
#define GAME_GAMEOBJECT_H

#include "SFML/Graphics.hpp"
#include "../utils/Vector2d.h"
#include <iostream>
#include <utility>

class GameObject {
public:
    GameObject() = default;

    explicit GameObject(std::string tag) : _tag(std::move(tag)) {};

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

    void setTag(const std::string &tag);

    const std::string &getTag() const;

protected:
    std::string _tag;

    Vector2d _position = {-1, -1}; // положение объекта в индексах на поле

    sf::Sprite _sprite;
    sf::Texture _texture;
};

#endif //GAME_GAMEOBJECT_H