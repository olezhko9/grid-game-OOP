// https://stackoverflow.com/questions/1008019/c-singleton-design-pattern

#include "GameObjectsManager.h"

SingletonBody(GameObjectsManager)

GameObjectsManager::GameObjectsManager() = default;

GameObjectsManager::~GameObjectsManager() {
    auto itr = _gameObjects.begin();
    while (itr != _gameObjects.end()) {
        delete itr->second;
        itr++;
    }
}


void GameObjectsManager::addObject(const std::string &name, GameObject *gameObject) {
    _gameObjects.insert(std::pair<std::string, GameObject *>(name, gameObject));
}

bool GameObjectsManager::removeObject(const std::string &name) {
    auto object = _gameObjects.find(name);
    if (object != _gameObjects.end()) {
        delete object->second;
        _gameObjects.erase(object);
        return true;
    }

    return false;
}

GameObject *GameObjectsManager::getObject(const std::string &name) {
    auto object = _gameObjects.find(name);
    if (object == _gameObjects.end()) return NULL;
    return object->second;
}

void GameObjectsManager::init() {
    auto itr = _gameObjects.begin();
    while (itr != _gameObjects.end()) {
        itr->second->init();
        itr++;
    }
}

void GameObjectsManager::update(float dt) {
    auto itr = _gameObjects.begin();
    while (itr != _gameObjects.end()) {
        itr->second->update(dt);
        itr++;
    }
}

void GameObjectsManager::render(sf::RenderWindow *window) {
    auto itr = _gameObjects.begin();
    while (itr != _gameObjects.end()) {
        itr->second->render(window);
        itr++;
    }
}
