#include <cstring>
#include <iostream>
#include "board.h"
#include "utils/random.h"

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

int *Board::getRandomPos(int min, int max) {
    int *pos = new int[2];
    pos[0] = Random::getInstance()->randomInt(min, max);
    pos[1] = Random::getInstance()->randomInt(min, max);

    return pos;
}

Cell *Board::getCellAt(int row, int col) {
    return &_cells[row][col];
}

void Board::init() {
    int *entrancePos = getRandomPos(_rows - 2, _rows);
    int *exitPos = getRandomPos(0, 2);

    for (int i = 0; i < _rows; ++i) {
        _cells[i] = new Cell[_cols];
        for (int j = 0; j < _cols; ++j) {
            CellType cellType = CellType::GROUND;
            if (i == entrancePos[0] && j == entrancePos[1]) {
                cellType = CellType::ENTRANCE;
            } else if (i == exitPos[0] && j == exitPos[1]) {
                cellType = CellType::EXIT;
            }
            _cells[i][j] = Cell(cellType);
        }
    }
}

void printLines(int columns) {
    for (int i = 0; i < columns; i++) {
        std::cout << "+----";
    }
    std::cout << "+" << std::endl;
}

void Board::render() {
    printLines(this->getCols());
    for (int i = 0; i < this->getRows(); ++i) {
        for (int j = 0; j < this->getCols(); ++j) {
            std::cout << "| ";
            // отображаем содержимое ячейки
            this->getCellAt(i, j)->render();
            std::cout << " ";
        }
        std::cout << "|" << std::endl;
        printLines(this->getCols());
    }
}
