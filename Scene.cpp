#include <cstring>
#include <iostream>
#include <thread>
#include "Scene.h"

#include "board.h"
#include "game_object/player.h"

#define FPS 15
#define GRID_SIZE 20

#define RESET   "\033[0m"
#define YELLOW  "\033[33m"

void printLines(int columns) {
    for (int i = 0; i < columns; i++) {
        std::cout << "+----";
    }
    std::cout << "+" << std::endl;
}

void Scene::init() {
    _board = new Board(GRID_SIZE, GRID_SIZE);

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

        printLines(_board->getCols());
        for (int i = 0; i < _board->getRows(); ++i) {
            for (int j = 0; j < _board->getCols(); ++j) {
                char *symbol = _board->getCellAt(i, j)->render();
                std::cout << "| " << YELLOW << symbol << RESET;
                if (strlen(symbol) == 1) {
                    std::cout << "  ";
                } else {
                    std::cout << " ";
                }
            }
            std::cout << "|" << std::endl;
            printLines(_board->getCols());
        }
        std::cout << i++ << std::endl;

        std::this_thread::sleep_for(std::chrono::milliseconds(1000 / FPS));
    }
}
