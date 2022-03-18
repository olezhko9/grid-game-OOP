#ifndef GAME_CELL_H
#define GAME_CELL_H

#include "game_object/GameObject.h"

enum CellType {
    GROUND = 0,
    ENTRANCE,
    EXIT
};

class Cell : public GameObject {
private:
    int _row;
    int _col;

    CellType _cellType;
public:
    Cell();

    explicit Cell(int row, int col, const sf::Texture *texture, CellType cellType);

    void init() override;

    void render(sf::RenderWindow *) override;

    void update(float) override;

    CellType getCellType() const;
};

#endif //GAME_CELL_H