#ifndef GAME_ENEMY_H
#define GAME_ENEMY_H

#include "./Hero.h"

class Enemy : public Hero {
public:
    Enemy();

    void init() override;

    void update(float dt) override;

    void render(sf::RenderWindow *window) override;
};

#endif //GAME_ENEMY_H
