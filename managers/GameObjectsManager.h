#ifndef GAME_GAMEOBJECTSMANAGER_H
#define GAME_GAMEOBJECTSMANAGER_H

#include <map>
#include <SFML/Graphics.hpp>
#include "../game_object/GameObject.h"

class GameObjectsManager {
public:
    static GameObjectsManager &getInstance();

    ~GameObjectsManager();

    void addObject(const std::string &name, GameObject *gameObject);

    bool removeObject(const std::string &name);

    GameObject *getObject(const std::string &name);

    void init();

    void update(float dt);

    void render(sf::RenderWindow *window);

private:
    std::map<std::string, GameObject *> _gameObjects;

    GameObjectsManager() = default;
};

#endif //GAME_GAMEOBJECTSMANAGER_H
