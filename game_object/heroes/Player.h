#ifndef GAME_PLAYER_H
#define GAME_PLAYER_H

#include "./Hero.h"

class Player : public Hero {
public:
    Player();

    void init() override;

    void update(float dt) override;

    void render(sf::RenderWindow *window) override;
};

#endif //GAME_PLAYER_H
