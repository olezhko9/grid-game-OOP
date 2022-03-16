
#ifndef GAME_CELL_H
#define GAME_CELL_H

#include "game_object/GameObject.h"

enum CellType {
    GROUND,
    ENTRANCE,
    EXIT
};

class Cell {
private:
    GameObject *_object = nullptr;
    CellType _cellType;
public:
    explicit Cell(CellType cellType = GROUND);

    GameObject *getObject() const;

    void setObject(GameObject *element);

    char *render() const;
};

#endif //GAME_CELL_H