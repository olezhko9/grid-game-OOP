#ifndef GAME_GAMEOBJECTSMANAGER_H
#define GAME_GAMEOBJECTSMANAGER_H

#include <map>
#include <SFML/Graphics.hpp>
#include "../game_object/GameObject.h"

class GameObjectsManager {
public:
SingletonHeader(GameObjectsManager)

public:
    void addObject(const std::string &name, GameObject *gameObject);

    bool removeObject(const std::string &name);

    GameObject *getObject(const std::string &name);

    const std::vector<std::pair<std::string, GameObject *>> &getGameObjects() const;

    void init();

    void update(float dt);

    void render(sf::RenderWindow *window);

private:
    std::vector<std::pair<std::string, GameObject *>> _gameObjects;
};

#endif //GAME_GAMEOBJECTSMANAGER_H
