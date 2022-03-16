#include "cell.h"

Cell::Cell(CellType cellType) : _cellType(cellType) {};

char* Cell::getSymbol() const {
    char* symbol;
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

GameObject *Cell::getElement() const {
    return _element;
}

void Cell::setElement(GameObject *element) {
    _element = element;
}

