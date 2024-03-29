#include <iostream>
#include <algorithm>
#include <random>
#include <SFML/Graphics.hpp>
#include <filesystem>

#include "Engine.h"
#include "Board.h"
#include "managers/GameObjectsManager.h"
#include "managers/ResourcesManager.h"
#include "game_object/heroes/Player.h"
#include "game_object/heroes/Enemy.h"
#include "game_object/items/Item.h"

#define ENEMIES_COUNT 3

auto rng = std::default_random_engine{};

Engine::Engine(unsigned int maxFps) {
    _maxFPS = maxFps;
}

int Engine::start() const {
    sf::Vector2<unsigned int> resolution;
    resolution.x = sf::VideoMode::getDesktopMode().width;
    resolution.y = sf::VideoMode::getDesktopMode().height;

    sf::RenderWindow window(sf::VideoMode(resolution.x, resolution.y), "SFML window");
    window.setFramerateLimit(_maxFPS);

    std::string path = "assets/img";
    for (const auto &asset: std::filesystem::directory_iterator(path)) {
        ResourcesManager::getInstance()->loadTexture(asset.path().string());
    }

    sf::Font font;
    font.loadFromFile("assets/fonts/arial.ttf");

    auto *board = new Board(15, 28);
    board->init();

    std::vector<GameObject *> movesQueue;

    auto *stone = new Item();
    stone->setTexture(ResourcesManager::getInstance()->getTexture("assets/img/stone.png"));
    stone->setPosition(board->getRandomValidPosition(1, 3, 1, 3));
    GameObjectsManager::getInstance()->addObject(stone);

    for (int i = 0; i < 3; ++i) {
        auto *timber = new Item();
        timber->setTexture(ResourcesManager::getInstance()->getTexture("assets/img/timber.png"));
        timber->setPosition(board->getRandomValidPosition(0, board->getCols(), 0, board->getRows()));
        GameObjectsManager::getInstance()->addObject(timber);
    }

    auto *player = new Player();
    player->setTag("player");
    player->setTexture(ResourcesManager::getInstance()->getTexture("assets/img/knight.png"));
    player->setPosition(board->getEntryPosition());
    player->setHp(100.f);
    player->setArmor(0.f);
    player->setAttack(10.f);
    GameObjectsManager::getInstance()->addObject(player);
    movesQueue.push_back(player);

    for (int i = 0; i < ENEMIES_COUNT; i++) {
        auto *enemy = new Enemy();
        enemy->setTexture(ResourcesManager::getInstance()->getTexture("assets/img/skeleton_warrior.png"));
        enemy->setPosition(
                board->getRandomValidPosition(board->getCols() / 2, board->getCols(), board->getRows() / 2,
                                              board->getRows())
        );
        enemy->setTag("enemy");
        GameObjectsManager::getInstance()->addObject(enemy);
        movesQueue.push_back(enemy);
    }

    GameObjectsManager::getInstance()->init();
    int currentMove = 0;

    sf::Clock clock;
    sf::Clock pcMoveClock;
    bool playerMoved = false;
    float aiMoveDelay = 0.1f;

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
                        newPosition = player->getPosition() + Vector2d::Up();
                        break;
                    case sf::Keyboard::Right:
                        newPosition = player->getPosition() + Vector2d::Right();
                        break;
                    case sf::Keyboard::Down:
                        newPosition = player->getPosition() + Vector2d::Down();
                        break;
                    case sf::Keyboard::Left:
                        newPosition = player->getPosition() + Vector2d::Left();
                        break;
                }

                if (board->isValidPosition(newPosition) && !playerMoved) {
                    playerMoved = true;
                    currentMove++;
                    player->setPosition(newPosition);
                    pcMoveClock.restart();
                }
            }
        }

        if (playerMoved && pcMoveClock.getElapsedTime().asSeconds() > aiMoveDelay) {
            // ходы противников

            for (auto &enemy: GameObjectsManager::getInstance()->getGameObjects("enemy")) {
                if (movesQueue.at(currentMove % movesQueue.size()) != enemy) continue;
                Vector2d enemyPosition = enemy->getPosition();
                Vector2d diff = player->getPosition() - enemyPosition;
                int moveX = diff.x / std::abs(diff.x);
                int moveY = diff.y / std::abs(diff.y);
                std::vector<Vector2d> possibleNewPositions = {
                        {enemyPosition.x + moveX, enemyPosition.y},
                        {enemyPosition.x,         enemyPosition.y + moveY},
                };
                std::shuffle(std::begin(possibleNewPositions), std::end(possibleNewPositions), rng);

                Vector2d newEnemyPosition;
                for (auto possiblePosition: possibleNewPositions) {
                    if (!board->isValidPosition(possiblePosition)) continue;
                    else newEnemyPosition = possiblePosition;
                }

                // если на пути встретили непроходимую клетку, то совершаем случайный ход
                while (!board->isValidPosition(newEnemyPosition)) {
                    std::vector<Vector2d> directions = {
                            Vector2d::Up(),
                            Vector2d::Right(),
                            Vector2d::Down(),
                            Vector2d::Left()
                    };
                    Vector2d randomDirection = directions[Random::getInstance()->randomInt(0, 4)];
                    newEnemyPosition = enemyPosition + randomDirection;
                }

                std::cout << enemyPosition.x << ", " << enemyPosition.y << " --> " << newEnemyPosition.x << ", "
                          << newEnemyPosition.y << ";  " << diff.x << ", " << diff.y << std::endl;
                enemy->setPosition(newEnemyPosition);
            }
            std::cout << "-------------------------" << std::endl;
            currentMove++;
            pcMoveClock.restart();
            if (currentMove % movesQueue.size() == 0) {
                playerMoved = false;
            }
        }

        // проверка коллизий
        for (auto &object1: GameObjectsManager::getInstance()->getGameObjects()) {
            for (auto &object2: GameObjectsManager::getInstance()->getGameObjects()) {
                if (object1 == object2 || object1 == nullptr || object2 == nullptr) continue;

                Vector2d pos1 = object1->getPosition();
                Vector2d pos2 = object2->getPosition();

                if (pos1 == pos2) {
                    std::cout << "Объекты " << object1->getTag() << " и " << object2->getTag() << " на одной клетке\n";
                    if (object1->getTag() == "player") {
                        if (object2->getTag() == "item") {
                            player->addHp(10);
                        } else if (object2->getTag() == "enemy") {
                            player->applyDamage(dynamic_cast<Hero *>(object2)->getAttack());
                        }
                        GameObjectsManager::getInstance()->removeObject(object2);
                    }
                }
            }
        }

        GameObjectsManager::getInstance()->update(dtSeconds);

        // если игрок дошел до выхода
        if (board->getTileAt(player->getPosition().y, player->getPosition().x)->getType() == TileType::EXIT) {
            std::cout << "Игрок победил" << std::endl;
            window.close();
        }

        if (player->getHp() <= 0) {
            std::cout << "Игрок умер" << std::endl;
            window.close();
        }

        window.clear();

        board->render(&window);
        GameObjectsManager::getInstance()->render(&window);

        // выводим параметры игрока
        std::stringstream ss;
        ss << "Health: " << player->getHp() << "\n"
           << "Armor: " << player->getArmor() << "\n"
           << "Attack: " << player->getAttack() << "\n"
           << "Enemies: " << GameObjectsManager::getInstance()->getGameObjects("enemy").size() << "\n"
           << "Items: " << GameObjectsManager::getInstance()->getGameObjects("item").size();
        sf::Text hpText(ss.str(), font);
        hpText.setCharacterSize(24);
        hpText.setFillColor(sf::Color::Red);
        hpText.setPosition(0.f, 0.f);
        window.draw(hpText);

        window.display();
    }

    return EXIT_SUCCESS;
}
