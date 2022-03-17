#include <iostream>
#include "board.h"
#include "utils/Vector2d.h"

#define CELL_SIZE 50

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
    Vector2d entrancePos = Vector2d::getRandom(_rows - 2, _rows);
    Vector2d exitPos = Vector2d::getRandom(0, 2);

    _grid = new sf::RectangleShape *[_rows];
    for (int i = 0; i < _rows; i++) {
        _cells[i] = new Cell[_cols];
        _grid[i] = new sf::RectangleShape[_cols];
        for (int j = 0; j < _cols; j++) {
            CellType cellType = CellType::GROUND;
            if (i == entrancePos.x && j == entrancePos.y) {
                cellType = CellType::ENTRANCE;
            } else if (i == exitPos.x && j == exitPos.y) {
                cellType = CellType::EXIT;
            }
            _cells[i][j] = Cell(cellType);

            _grid[i][j] = sf::RectangleShape();
            _grid[i][j].setSize(sf::Vector2f{CELL_SIZE, CELL_SIZE});
            if (cellType == CellType::ENTRANCE) {
                _grid[i][j].setFillColor(sf::Color::Cyan);
            } else if (cellType == CellType::EXIT) {
                _grid[i][j].setFillColor(sf::Color::Magenta);
            } else {
                _grid[i][j].setOutlineColor(sf::Color::Blue);
            }
            _grid[i][j].setOutlineThickness(2.0f);
            _grid[i][j].setPosition(j * CELL_SIZE + 5.0f, i * CELL_SIZE + 5.0f);
        }
    }
}

void Board::render(sf::RenderWindow *window) {
    for (int i = 0; i < _rows; i++) {
        for (int j = 0; j < _cols; j++) {
            window->draw(_grid[i][j]);
        }
    }
}

void Board::update(float) {

}
