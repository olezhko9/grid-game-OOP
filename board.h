#ifndef GAME_BOARD_H
#define GAME_BOARD_H

#include "cell.h"

class Board : public GameObject {
private:
    int _rows;
    int _cols;
    Cell **_cells;

    int *getRandomPos(int min, int max);

public:
    Board(int rows, int cols);

    Board(const Board &board); // конструктор копирования

    void init() override;

    void render() override;

    Cell **getCells() const;

    Cell *getCellAt(int row, int col);

    int getRows() const;

    int getCols() const;
};

#endif //GAME_BOARD_H