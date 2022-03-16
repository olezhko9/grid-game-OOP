#include "player.h"

Player::Player(char *name) {
    _name = name;
}

char *Player::render() {
    return "P";
}