#include <ctime>
#include <cstdlib>
#include "random.h"

Random* Random::_instance = nullptr;

Random::Random() {
    srand(time(NULL));
}

Random *Random::getInstance() {
    if (_instance == nullptr) {
        _instance = new Random();
    }
    return _instance;
}

int Random::randomInt(int max) {
    return rand() % max;
}

int Random::randomInt(int min, int max) {
    return rand() % max + min;
}
