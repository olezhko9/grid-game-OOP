#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H

class Engine {
private:
    unsigned int _maxFPS;

public:
    Engine(unsigned int maxFps);

    int start() const;
};

#endif //GAME_ENGINE_H
