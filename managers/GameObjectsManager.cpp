// https://stackoverflow.com/questions/1008019/c-singleton-design-pattern

#include "GameObjectsManager.h"

SingletonBody(GameObjectsManager)

GameObjectsManager::GameObjectsManager() = default;

GameObjectsManager::~GameObjectsManager() {
    for (const auto &gameObject: _gameObjects) {
        delete gameObject.second;
    }
}

void GameObjectsManager::addObject(const std::string &name, GameObject *gameObject) {
    _gameObjects.push_back(std::make_pair(name, gameObject));
}

bool GameObjectsManager::removeObject(const std::string &name) {
    for (auto it = _gameObjects.begin(); it != _gameObjects.end(); ++it) {
        if (it->first == name) {
            SafeDelete(it->second);
            _gameObjects.erase(it);
            return true;
        }
    }

    return false;
}

GameObject *GameObjectsManager::getObject(const std::string &name) {
    for (const auto &gameObject: _gameObjects) {
        if (gameObject.first == name) {
            return gameObject.second;
        }
    }

    return nullptr;
}

void GameObjectsManager::init() {
    for (auto gameObject: _gameObjects) {
        gameObject.second->init();
    }
}

void GameObjectsManager::update(float dt) {
    for (auto gameObject: _gameObjects) {
        gameObject.second->update(dt);
    }
}

void GameObjectsManager::render(sf::RenderWindow *window) {
    for (auto gameObject: _gameObjects) {
        gameObject.second->render(window);
    }
}

const std::vector<std::pair<std::string, GameObject *>> &GameObjectsManager::getGameObjects() const {
    return _gameObjects;
}
