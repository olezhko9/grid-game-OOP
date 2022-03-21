#ifndef GAME_PLAYER_H
#define GAME_PLAYER_H

#include "../GameObject.h"

class Player : public GameObject {
public:
    Player();

    void init() override;

    void update(float dt) override;

    void render(sf::RenderWindow *window) override;

    int addHp(int hp);

    int getHp() const;

private:
    int _hp = 10; // здоровье
};

#endif //GAME_PLAYER_H
