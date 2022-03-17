#include "cell.h"

Cell::Cell(CellType cellType) : _cellType(cellType) {};

void Cell::init() {

}

void Cell::update(float) {

}

void Cell::render(sf::RenderWindow *window) {
    if (_object != nullptr) {
        return _object->render(window);
    }
}

GameObject *Cell::getObject() const {
    return _object;
}

void Cell::setObject(GameObject *element) {
    _object = element;
}

CellType Cell::getCellType() const {
    return _cellType;
}

