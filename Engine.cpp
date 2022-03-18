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
    window.setFramerateLimit(_maxFPS);

    auto *board = new Board(15, 30);

    sf::Texture playerTexture;
    if (!playerTexture.loadFromFile("/home/olezhko/CLionProjects/game/assets/img/knight.png")) return EXIT_FAILURE;
    auto *player = new Player(playerTexture);

    GameObjectsManager::getInstance().addObject("board", board);
    GameObjectsManager::getInstance().addObject("player", player);

    GameObjectsManager::getInstance().init();
    player->setPosition(board->getEntryPosition());

    sf::Clock clock;

    while (window.isOpen()) {
        sf::Time dt = clock.restart();
        float dtSeconds = dt.asSeconds();

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::KeyPressed) {
                switch (event.key.code) {
                    case sf::Keyboard::Up:
                        player->setPosition(Vector2d{player->getPosition().x, player->getPosition().y - 1});
                        break;
                    case sf::Keyboard::Right:
                        player->setPosition(Vector2d{player->getPosition().x + 1, player->getPosition().y});
                        break;
                    case sf::Keyboard::Down:
                        player->setPosition(Vector2d{player->getPosition().x, player->getPosition().y + 1});
                        break;
                    case sf::Keyboard::Left:
                        player->setPosition(Vector2d{player->getPosition().x - 1, player->getPosition().y});
                        break;
                }
            }
        }

//        std::cout << player->getPosition().x << ", " << player->getPosition().y << std::endl;
        GameObjectsManager::getInstance().update(dtSeconds);

        if (board->getCellAt(player->getPosition().y, player->getPosition().x)->getCellType() == CellType::EXIT) {
            window.close();
        }

        window.clear();

        GameObjectsManager::getInstance().render(&window);

        window.display();
    }

    return EXIT_SUCCESS;
}
