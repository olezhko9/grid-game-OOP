#include <iostream>
#include "board.h"
#include "utils/random.h"

Board::Board(int r, int c) {
    rows = r;
    cols = c;
    cells = new Cell *[rows];

    int* entrancePos = getRandomPos(0, rows);
    int* exitPos = getRandomPos(0, rows);

    for (int i = 0; i < rows; ++i) {
        cells[i] = new Cell[cols];
        for (int j = 0; j < cols; ++j) {
            CellType cellType = CellType::GROUND;
            if (i == entrancePos[0] && j == entrancePos[1]) {
                cellType = CellType::ENTRANCE;
            } else if (i == exitPos[0] && j == exitPos[1]) {
                cellType = CellType::EXIT;
            }
            cells[i][j] = Cell(cellType);
        }
    }
}

int Board::getRows() const {
    return rows;
}

int Board::getCols() const {
    return cols;
}

Cell **Board::getCells() const {
    return cells;
}

int* Board::getRandomPos(int min, int max) {
    int* pos = new int[2];
    pos[0] = Random::getInstance()->randomInt(min, max);
    pos[1] = Random::getInstance()->randomInt(min, max);
    std::cout << pos[0] << ", " << pos[1] << std::endl;
    return pos;
}
