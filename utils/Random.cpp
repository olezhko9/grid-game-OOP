#include <ctime>
#include <cstdlib>
#include "Random.h"

SingletonBody(Random)

Random::Random() {
    srand(time(NULL));
}

int Random::randomInt(int max) {
    return rand() % max;
}

int Random::randomInt(int min, int max) {
    return rand() % (max - min) + min;
}
