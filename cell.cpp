#include "cell.h"

Cell::Cell() {}

Cell::Cell(int row, int col, const sf::Texture *texture, CellType cellType) {
    _row = row;
    _col = col;
    _cellType = cellType;
    _sprite = sf::Sprite(*texture);
}

void Cell::init() {
    _sprite.setPosition(_col * CELL_SIZE, _row * CELL_SIZE);
}

void Cell::update(float) {}

void Cell::render(sf::RenderWindow *window) {}

CellType Cell::getCellType() const {
    return _cellType;
}
