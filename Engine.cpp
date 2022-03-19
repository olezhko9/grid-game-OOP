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
    auto *board = new Board(15, 30);
    GameObjectsManager::getInstance()->addObject("board", board);

    std::vector<std::string> textures = {
        "assets/img/knight.png",
        "assets/img/grass.png",
        "assets/img/light_earth.png",
        "assets/img/purple.png",
        "assets/img/stone.png",
        "assets/img/timber.png",
        "assets/img/heart.png",
    };
    for (auto texture : textures) {
        ResourcesManager::getInstance()->loadTexture(texture);
    }

    sf::Font font;
    font.loadFromFile("assets/fonts/arial.ttf");

    auto *stone = new Item();
    stone->setTexture(ResourcesManager::getInstance()->getTexture("assets/img/stone.png"));
    stone->setPosition(Vector2d::getRandom(1, 3));
    GameObjectsManager::getInstance()->addObject("stone", stone);

    auto *timber = new Item();
    timber->setTexture(ResourcesManager::getInstance()->getTexture("assets/img/heart.png"));
    timber->setPosition(Vector2d::getRandom(4, 7));
    GameObjectsManager::getInstance()->addObject("timber", timber);

    auto player = new Player();
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


        // проверка коллизий
        for (auto &object1 : GameObjectsManager::getInstance()->getGameObjects()) {
            for (auto &object2 : GameObjectsManager::getInstance()->getGameObjects()) {
                if (object1 == object2) continue;

                Vector2d pos1 = object1.second->getPosition();
                Vector2d pos2 = object2.second->getPosition();

                if (pos1.x == pos2.x && pos1.y == pos2.y) {
                    std::cout << "Объекты " << object1.first << " и " << object2.first << " на одной клетке" << std::endl;
                    if (object1.second == player && object2.second == timber) {
                        player->addHp(10);
                        GameObjectsManager::getInstance()->removeObject("player");
                    }
                }
            }
        }

        std::cout << player->getHp() << std::endl;
        GameObjectsManager::getInstance()->update(dtSeconds);

        if (board->getTileAt(player->getPosition().y, player->getPosition().x)->getTileType() == TileType::EXIT) {
            window.close();
        }

        window.clear();

        GameObjectsManager::getInstance()->render(&window);

        if (player->isAlive()) {
            sf::Text hpText("Health: " + std::to_string(player->getHp()), font);
            hpText.setCharacterSize(24);
            hpText.setFillColor(sf::Color::Red);
            hpText.setPosition(0.f, 0.f);
            window.draw(hpText);
        }

        window.display();
    }

    return EXIT_SUCCESS;
}
