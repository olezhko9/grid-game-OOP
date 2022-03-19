#ifndef GAME_ITEM_H
#define GAME_ITEM_H

#include "../GameObject.h"

class Item : public GameObject {
public:
    void init() override {};

    void update(float dt) override;

    void render(sf::RenderWindow *window) override;
};

#endif //GAME_ITEM_H
