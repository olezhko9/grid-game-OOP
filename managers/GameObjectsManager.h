#ifndef GAME_GAMEOBJECTSMANAGER_H
#define GAME_GAMEOBJECTSMANAGER_H

#include <map>
#include <SFML/Graphics.hpp>
#include "../game_object/GameObject.h"

class GameObjectsManager {
public:
SingletonHeader(GameObjectsManager)

public:
    void addObject(GameObject *gameObject);

    bool removeObject(const GameObject *);

    GameObject *getObject(const std::string &tag);

    const std::vector<GameObject *> &getGameObjects() const;

    std::vector<GameObject *> getGameObjects(const std::string &tag) const;

    void init();

    void update(float dt);

    void render(sf::RenderWindow *window);

private:
    std::vector<GameObject *> _gameObjects;
};

#endif //GAME_GAMEOBJECTSMANAGER_H
