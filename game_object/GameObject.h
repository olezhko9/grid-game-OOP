#ifndef GAME_GAMEOBJECT_H
#define GAME_GAMEOBJECT_H

class GameObject {
public:
    virtual void init() = 0;

    virtual void render() = 0;

protected:
    struct position {
        int x;
        int y;
    };
};

#endif //GAME_GAMEOBJECT_H