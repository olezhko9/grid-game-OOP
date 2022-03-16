#ifndef GAME_SCENE_H
#define GAME_SCENE_H

#include "board.h"

class Scene {
private:
    Board *_board;

public:
    void init();

    void update();

    [[noreturn]] void render();
};

#endif //GAME_SCENE_H
