#ifndef GAME_PLAYER_H
#define GAME_PLAYER_H

#include "../GameObject.h"

class Player : public GameObject {
public:
    void init() override;

    void update(float dt) override;

    void render(sf::RenderWindow *window) override;

    int addHp(int hp) {
        _hp += hp;
        return _hp;
    }

    int getHp() const;

private:
    int _hp = 10; // здоровье
};

#endif //GAME_PLAYER_H
