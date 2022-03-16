#ifndef GAME_PLAYER_H
#define GAME_PLAYER_H

#include "GameObject.h"

class Player : public GameObject {
public:
    Player(char* name);
    char * getSymbol() override;

private:
    char *_name;
};

#endif //GAME_PLAYER_H
