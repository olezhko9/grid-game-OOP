#ifndef GAME_BOARD_H
#define GAME_BOARD_H

#include "Tile.h"

class Board {
private:
    int _rows;
    int _cols;
    Tile **_tiles;

    Vector2d entryPosition;
    Vector2d exitPosition;
public:
    Board(int rows, int cols);

    Board(const Board &board); // конструктор копирования

    const Vector2d &getEntryPosition() const;

    const Vector2d &getExitPosition() const;

    void init();

    void render(sf::RenderWindow *);

    void update(float);

    Tile **getTiles() const;

    Tile *getTileAt(int row, int col);

    Tile *getTileAt(Vector2d &) const;

    int getRows() const;

    int getCols() const;

    bool isValidPosition(Vector2d &) const;

    Vector2d getRandomValidPosition(int minX, int maxX, int minY, int maxY) const;
};

#endif //GAME_BOARD_H