#include "Board.h"
#include "utils/Vector2d.h"
#include "managers/ResourcesManager.h"

Board::Board(int r, int c) {
    _rows = r;
    _cols = c;
    _tiles = new Tile *[_rows];
}

int Board::getRows() const {
    return _rows;
}

int Board::getCols() const {
    return _cols;
}

Tile **Board::getTiles() const {
    return _tiles;
}

Tile *Board::getTileAt(int row, int col) {
    return &_tiles[row][col];
}

void Board::init() {
    this->entryPosition = Vector2d::getRandom(0, _cols / 2, 0, _rows / 2);
    this->exitPosition = Vector2d::getRandom(_cols / 2, _cols, _rows / 2, _rows);

    for (int i = 0; i < _rows; i++) {
        _tiles[i] = new Tile[_cols];
        for (int j = 0; j < _cols; j++) {
            if (j == entryPosition.x && i == entryPosition.y) {
                _tiles[i][j] = Tile(i, j, ResourcesManager::getInstance()->getTexture("assets/img/light_earth.png"), TileType::ENTRANCE);
            } else if (j == exitPosition.x && i == exitPosition.y) {
                _tiles[i][j] = Tile(i, j, ResourcesManager::getInstance()->getTexture("assets/img/purple.png"), TileType::EXIT);
            } else {
                // с вероятность 15% плитка будет непроходимой (вода)
                if (Random::getInstance()->random() < 0.15) {
                    _tiles[i][j] = Tile(i, j, ResourcesManager::getInstance()->getTexture("assets/img/water.png"), TileType::WATER);
                } else {
                    _tiles[i][j] = Tile(i, j, ResourcesManager::getInstance()->getTexture("assets/img/grass.png"), TileType::GROUND);
                }
            }

            _tiles[i][j].init();
        }
    }
}

void Board::render(sf::RenderWindow *window) {
    for (int i = 0; i < _rows; i++) {
        for (int j = 0; j < _cols; j++) {
            window->draw(_tiles[i][j].getSprite());
        }
    }
}

void Board::update(float) {

}

const Vector2d &Board::getEntryPosition() const {
    return entryPosition;
}

const Vector2d &Board::getExitPosition() const {
    return exitPosition;
}

Tile *Board::getTileAt(Vector2d &vector) {
    return &_tiles[vector.y][vector.x];
}
