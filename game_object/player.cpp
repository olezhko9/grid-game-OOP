#include <iostream>
#include "player.h"

#define RESET   "\033[0m"
#define YELLOW  "\033[33m"

Player::Player(char *name) {
    _name = name;
}

void Player::init() {

}

void Player::render() {
    char *symbol = "P ";
    std::cout << YELLOW << symbol << RESET;
}
