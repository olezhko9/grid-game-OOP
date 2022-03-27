#ifndef GAME_ENEMY_H
#define GAME_ENEMY_H

#include "GameObject.h"

class Enemy : public GameObject {
public:
    Enemy();

    void init() override;

    void update(float dt) override;

    void render(sf::RenderWindow *window) override;
};

#endif //GAME_ENEMY_H
