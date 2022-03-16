#include "cell.h"

Cell::Cell(CellType cellType) : _cellType(cellType) {};

char *Cell::render() const {
    if (_object != nullptr) {
        return _object->render();
    }

    char *symbol;
    switch (_cellType) {
        case GROUND:
            symbol = " ";
            break;
        case ENTRANCE:
            symbol = "I";
            break;
        case EXIT:
            symbol = "O";
            break;
    }

    return symbol;
}

GameObject *Cell::getObject() const {
    return _object;
}

void Cell::setObject(GameObject *element) {
    _object = element;
}
