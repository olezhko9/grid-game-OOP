#ifndef GAME_BOARD_H
#define GAME_BOARD_H

#include "cell.h"

class Board {
private:
    int rows;
    int cols;
    Cell **cells;

    int entrancePos[2];
    int exitPos[2];

    int* getRandomPos(int min, int max);
public:
    Board(int r, int c);

    Board(const Board &board); // конструктор копирования

    Cell** getCells() const;

    int getRows() const;

    int getCols() const;
};

#endif //GAME_BOARD_H