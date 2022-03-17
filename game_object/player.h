#ifndef GAME_PLAYER_H
#define GAME_PLAYER_H

#include "GameObject.h"

class Player : public GameObject {
public:
    Player(const sf::Texture&);

    void init() override;

    void update(float dt);

    void render(sf::RenderWindow *window) override;

private:
    sf::Sprite _sprite;
};

#endif //GAME_PLAYER_H
