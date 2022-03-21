#include "Tile.h"

Tile::Tile() : GameObject("tile") {}

Tile::Tile(int row, int col, const sf::Texture &texture, TileType tileType) {
    _row = row;
    _col = col;
    _tileType = tileType;
    _sprite = sf::Sprite(texture);
}

void Tile::init() {
    _sprite.setPosition(_col * TILE_SIZE, _row * TILE_SIZE);
}

void Tile::update(float) {}

void Tile::render(sf::RenderWindow *window) {}

TileType Tile::getTileType() const {
    return _tileType;
}
