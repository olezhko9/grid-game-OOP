
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
    GameObject *_element = nullptr;
    CellType _cellType;
public:
    explicit Cell(CellType cellType = GROUND);

    GameObject *getElement() const;

    void setElement(GameObject *element);

    char* getSymbol() const;
};

#endif //GAME_CELL_H