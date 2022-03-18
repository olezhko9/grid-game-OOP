#ifndef GAME_BOARD_H
#define GAME_BOARD_H

#include "Tile.h"

class Board : public GameObject {
private:
    int _rows;
    int _cols;
    Tile **_tiles;

    Vector2d entryPosition;
    Vector2d exitPosition;

    sf::RectangleShape **_grid;
public:
    Board(int rows, int cols);

    Board(const Board &board); // конструктор копирования

    const Vector2d &getEntryPosition() const;

    const Vector2d &getExitPosition() const;

    void init() override;

    void render(sf::RenderWindow *) override;

    void update(float) override;

    Tile **getTiles() const;

    Tile *getTileAt(int row, int col);

    int getRows() const;

    int getCols() const;
};

#endif //GAME_BOARD_H