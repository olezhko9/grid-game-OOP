#ifndef GAME_TILE_H
#define GAME_TILE_H

#include "game_object/GameObject.h"

enum TileType {
    GROUND = 0,
    WATER,
    ENTRANCE,
    EXIT
};

class Tile : public GameObject {
private:
    int _row;
    int _col;

    TileType _type;
public:
    Tile();

    explicit Tile(int row, int col, const sf::Texture &texture, TileType tileType);

    void init() override;

    void render(sf::RenderWindow *) override;

    void update(float) override;

    TileType getType() const;
};

#endif //GAME_TILE_H