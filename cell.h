
#ifndef GAME_CELL_H
#define GAME_CELL_H

#include "game_object/GameObject.h"

enum CellType {
    GROUND,
    ENTRANCE,
    EXIT
};

class Cell : public GameObject {
private:
    GameObject *_object = nullptr;
    CellType _cellType;
public:
    explicit Cell(CellType cellType = GROUND);

    void init() override;

    void render(sf::RenderWindow *) override;

    void update(float) override;

    GameObject *getObject() const;

    void setObject(GameObject *element);
};

#endif //GAME_CELL_H