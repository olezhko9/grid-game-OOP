#include "Hero.h"


float Hero::addHp(float hp) {
    _hp += hp;
    return _hp;
}

float Hero::getHp() const {
    return _hp;
}

float Hero::getAttack() const {
    return _attack;
}

float Hero::getArmor() const {
    return _armor;
}

void Hero::setHp(float hp) {
    _hp = hp;
}

void Hero::setAttack(float attack) {
    _attack = attack;
}

void Hero::setArmor(float armor) {
    _armor = armor;
}

void Hero::applyDamage(float damage) {
    float armorDamage = std::min(damage, _armor);
    float hpDamage = damage - armorDamage;
    _armor -= armorDamage;
    _hp -= hpDamage;
}