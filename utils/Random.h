#ifndef GAME_RANDOM_H
#define GAME_RANDOM_H

#include "../definitions.h"

class Random {
public:
SingletonHeader(Random)

public:
    int randomInt(int max);

    int randomInt(int min, int max);
};

#endif //GAME_RANDOM_H
