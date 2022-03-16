#ifndef GAME_RANDOM_H
#define GAME_RANDOM_H

class Random {
private:
    static Random *_instance;

public:
    static Random* getInstance();

    Random();

    int randomInt(int max);
    int randomInt(int min, int max);
};

#endif //GAME_RANDOM_H
