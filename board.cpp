#include <iostream>
#include "board.h"
#include "utils/Vector2d.h"

Board::Board(int r, int c) {
    _rows = r;
    _cols = c;
    _cells = new Cell *[_rows];
}

int Board::getRows() const {
    return _rows;
}

int Board::getCols() const {
    return _cols;
}

Cell **Board::getCells() const {
    return _cells;
}

Cell *Board::getCellAt(int row, int col) {
    return &_cells[row][col];
}

void Board::init() {
    this->entryPosition = Vector2d::getRandom(0, _cols / 2, 0, _rows / 2);
    this->exitPosition = Vector2d::getRandom(_cols / 2, _cols, _rows / 2, _rows);

    // TODO: правильнее получать ссылку на текстуру извне
    auto *textureGrass = new sf::Texture;
    if (!textureGrass->loadFromFile("/home/olezhko/CLionProjects/game/assets/img/grass.png")) return;

    auto *textureLightEarth = new sf::Texture;
    if (!textureLightEarth->loadFromFile("/home/olezhko/CLionProjects/game/assets/img/light_earth.png")) return;

    auto *texturePurple = new sf::Texture;
    if (!texturePurple->loadFromFile("/home/olezhko/CLionProjects/game/assets/img/purple.png")) return;

    for (int i = 0; i < _rows; i++) {
        _cells[i] = new Cell[_cols];
        for (int j = 0; j < _cols; j++) {
            if (j == entryPosition.x && i == entryPosition.y) {
                _cells[i][j] = Cell(i, j, textureLightEarth, CellType::ENTRANCE);
            } else if (j == exitPosition.x && i == exitPosition.y) {
                _cells[i][j] = Cell(i, j, texturePurple, CellType::EXIT);
            } else {
                _cells[i][j] = Cell(i, j, textureGrass, CellType::GROUND);
            }

            _cells[i][j].init();
        }
    }
}

void Board::render(sf::RenderWindow *window) {
    for (int i = 0; i < _rows; i++) {
        for (int j = 0; j < _cols; j++) {
            window->draw(_cells[i][j].getSprite());
        }
    }
}

void Board::update(float) {

}

const Vector2d &Board::getEntryPosition() const {
    return entryPosition;
}

const Vector2d &Board::getExitPosition() const {
    return exitPosition;
}
