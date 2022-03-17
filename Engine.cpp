#include <iostream>
#include <SFML/Graphics.hpp>

#include "Engine.h"
#include "game_object/GameObjectsManager.h"
#include "game_object/player.h"
#include "board.h"

Engine::Engine(unsigned int maxFps) {
    _maxFPS = maxFps;
}

int Engine::start() {
    sf::Vector2<unsigned int> resolution;
    resolution.x = sf::VideoMode::getDesktopMode().width;
    resolution.y = sf::VideoMode::getDesktopMode().height;

    sf::RenderWindow window(sf::VideoMode(resolution.x, resolution.y), "SFML window");
    window.setFramerateLimit(1.0f / _maxFPS);

    auto *board = new Board(15, 30);

    sf::Texture playerTexture;
    if (!playerTexture.loadFromFile("/home/olezhko/CLionProjects/game/assets/img/dragon.png")) return EXIT_FAILURE;
    auto *player = new Player(playerTexture);

    GameObjectsManager::getInstance().addObject("board", board);
    GameObjectsManager::getInstance().addObject("player", player);

    GameObjectsManager::getInstance().init();
    board->getCellAt(0, 0)->setObject(player);

    sf::Clock clock;

    while (window.isOpen()) {
        sf::Time dt = clock.restart();
        float dtSeconds = dt.asSeconds();

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        GameObjectsManager::getInstance().update(dtSeconds);

        window.clear();

        GameObjectsManager::getInstance().render(&window);

        window.display();
    }

    return EXIT_SUCCESS;
}
