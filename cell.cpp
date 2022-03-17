#include "iostream"
#include "cell.h"

#define RESET   "\033[0m"
#define BOLDBLUE    "\033[1m\033[34m"

Cell::Cell(CellType cellType) : _cellType(cellType) {};

void Cell::init() {

}

void Cell::render(sf::RenderWindow *window) {
    if (_object != nullptr) {
        return _object->render(window);
    }

    char *symbol;
    switch (_cellType) {
        case GROUND:
            symbol = "  ";
            break;
        case ENTRANCE:
            symbol = "I ";
            break;
        case EXIT:
            symbol = "O ";
            break;
    }

//    std::cout << BOLDBLUE << symbol << RESET;
}

GameObject *Cell::getObject() const {
    return _object;
}

void Cell::setObject(GameObject *element) {
    _object = element;
}

void Cell::update(float) {

}

