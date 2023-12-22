#ifndef GAME_HERO_H
#define GAME_HERO_H

#include "../GameObject.h"

class Hero : public GameObject {
public:
    float addHp(float hp);

    float getHp() const;

    void setHp(float hp);

    void setAttack(float attack);

    void setArmor(float armor);

    float getAttack() const;

    float getArmor() const;

    void applyDamage(float);

private:
    float _hp = 100.f; // здоровье
    float _attack = 50.f;
    float _armor = 50.f;
};


#endif //GAME_HERO_H
