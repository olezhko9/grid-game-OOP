#include <iostream>
#include <SFML/Graphics.hpp>
#include <memory>

#include "Engine.h"
#include "managers/GameObjectsManager.h"
#include "managers/ResourcesManager.h"
#include "game_object/player/Player.h"
#include "Board.h"
#include "game_object/items/Item.h"

Engine::Engine(unsigned int maxFps) {
    _maxFPS = maxFps;
}

int Engine::start() {
    sf::Vector2<unsigned int> resolution;
    resolution.x = sf::VideoMode::getDesktopMode().width;
    resolution.y = sf::VideoMode::getDesktopMode().height;

    sf::RenderWindow window(sf::VideoMode(resolution.x, resolution.y), "SFML window");
    window.setFramerateLimit(_maxFPS);

    // TODO: не создавать Board как игровой объект, а создавать плитки
    auto *board = new Board(15, 28);
    GameObjectsManager::getInstance()->addObject("board", board);

    std::vector<std::string> textures = {
            "assets/img/knight.png",
            "assets/img/grass.png",
            "assets/img/light_earth.png",
            "assets/img/purple.png",
            "assets/img/stone.png",
            "assets/img/timber.png",
            "assets/img/heart.png",
            "assets/img/water.png",
    };
    for (auto &texture: textures) {
        ResourcesManager::getInstance()->loadTexture(texture);
    }

    sf::Font font;
    font.loadFromFile("assets/fonts/arial.ttf");

    auto *stone = new Item();
    stone->setTag("stone");
    stone->setTexture(ResourcesManager::getInstance()->getTexture("assets/img/stone.png"));
    stone->setPosition(Vector2d::getRandom(1, 3));
    GameObjectsManager::getInstance()->addObject("stone", stone);

    auto *timber = new Item();
    timber->setTag("timber");
    timber->setTexture(ResourcesManager::getInstance()->getTexture("assets/img/timber.png"));
    timber->setPosition(Vector2d::getRandom(4, 7));
    GameObjectsManager::getInstance()->addObject("timber", timber);

    auto *player = new Player();
    player->setTag("player");
    player->setTexture(ResourcesManager::getInstance()->getTexture("assets/img/knight.png"));
    GameObjectsManager::getInstance()->addObject("player", player);

    GameObjectsManager::getInstance()->init();
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
                Vector2d newPosition(-1, -1);
                switch (event.key.code) {
                    case sf::Keyboard::Up:
                        newPosition = {player->getPosition().x, player->getPosition().y - 1};
                        break;
                    case sf::Keyboard::Right:
                        newPosition = {player->getPosition().x + 1, player->getPosition().y};
                        break;
                    case sf::Keyboard::Down:
                        newPosition = {player->getPosition().x, player->getPosition().y + 1};
                        break;
                    case sf::Keyboard::Left:
                        newPosition = {player->getPosition().x - 1, player->getPosition().y};
                        break;
                }

                if (newPosition.x != -1 && newPosition.y != -1 &&
                    newPosition.x >= 0 &&
                    newPosition.x < board->getCols() &&
                    newPosition.y >= 0 &&
                    newPosition.y < board->getRows() &&
                    board->getTileAt(newPosition)->getTileType() != TileType::WATER
                        ) {
                    player->setPosition(newPosition);
                    std::cout << "Tile: " << board->getTileAt(newPosition)->getTileType() << std::endl;
                }
            }
        }

        // проверка коллизий
        for (auto &object1: GameObjectsManager::getInstance()->getGameObjects()) {
            for (auto &object2: GameObjectsManager::getInstance()->getGameObjects()) {
                if (object1 == object2) continue;

                Vector2d pos1 = object1.second->getPosition();
                Vector2d pos2 = object2.second->getPosition();

                if (pos1 == pos2) {
                    std::cout << "Объекты " << object1.first << " и " << object2.first << " на одной клетке\n";
                    if (object1.second->getTag() == "player") {
                        if (object2.second->getTag() == "timber") {
                            player->addHp(10);
                        } else if (object2.second->getTag() == "stone") {
                            player->addHp(-10);
                        }
                        GameObjectsManager::getInstance()->removeObject(object2.first);
                    }
                }
            }
        }

        GameObjectsManager::getInstance()->update(dtSeconds);

        // если игрок дошел до выхода
        if (board->getTileAt(player->getPosition().y, player->getPosition().x)->getTileType() == TileType::EXIT) {
            window.close();
        }

        if (player->getHp() == 0) {
            window.close();
        }

        window.clear();

        GameObjectsManager::getInstance()->render(&window);

        // выводим здоровье игрока
        sf::Text hpText("Health: " + std::to_string(player->getHp()), font);
        hpText.setCharacterSize(24);
        hpText.setFillColor(sf::Color::Red);
        hpText.setPosition(0.f, 0.f);
        window.draw(hpText);

        window.display();
    }

    return EXIT_SUCCESS;
}
