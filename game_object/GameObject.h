#ifndef GAME_GAMEOBJECT_H
#define GAME_GAMEOBJECT_H

class GameObject {
public:
    virtual char *getSymbol() = 0;

protected:
    struct position {
        int x;
        int y;
    };
};

#endif //GAME_GAMEOBJECT_H