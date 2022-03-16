#include "player.h"

char *Player::getSymbol() {
    return "P";
}

Player::Player(char *name) {
    _name = name;
}
