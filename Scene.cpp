#include <iostream>
#include <thread>
#include "Scene.h"

#include "board.h"
#include "game_object/player.h"

#define FPS 15
#define GRID_SIZE 20


void Scene::init() {
    _board = new Board(GRID_SIZE, GRID_SIZE);
    _board->init();

    GameObject *player = new Player("Oleg");
    _board->getCellAt(0, 0)->setObject(player);

    this->render();
}

void Scene::update() {

}

[[noreturn]] void Scene::render() {
    int i = 0;
    while (true) {
        system("clear"); // cls in Windows
        _board->render();

        std::cout << i++ << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000 / FPS));
    }
}
