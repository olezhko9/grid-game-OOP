// https://stackoverflow.com/questions/1008019/c-singleton-design-pattern

#include "GameObjectsManager.h"

SingletonBody(GameObjectsManager)

GameObjectsManager::GameObjectsManager() = default;

GameObjectsManager::~GameObjectsManager() {
    for (const auto &gameObject: _gameObjects) {
        delete gameObject;
    }
}

void GameObjectsManager::addObject(GameObject *gameObject) {
    _gameObjects.push_back(gameObject);
}

bool GameObjectsManager::removeObject(const GameObject *gameObject) {
    for (auto it = _gameObjects.begin(); it != _gameObjects.end(); ++it) {
        if (*it == gameObject) {
            SafeDelete(*it);
            _gameObjects.erase(it);
            return true;
        }
    }

    return false;
}

GameObject *GameObjectsManager::getObject(const std::string &tag) {
    for (const auto &gameObject: _gameObjects) {
        if (gameObject->getTag() == tag) {
            return gameObject;
        }
    }

    return nullptr;
}

void GameObjectsManager::init() {
    for (auto gameObject: _gameObjects) {
        gameObject->init();
    }
}

void GameObjectsManager::update(float dt) {
    for (auto gameObject: _gameObjects) {
        gameObject->update(dt);
    }
}

void GameObjectsManager::render(sf::RenderWindow *window) {
    for (auto gameObject: _gameObjects) {
        gameObject->render(window);
    }
}

const std::vector<GameObject *> &GameObjectsManager::getGameObjects() const {
    return _gameObjects;
}

std::vector<GameObject *> GameObjectsManager::getGameObjects(const std::string &tag) const {
    std::vector<GameObject *> objects;
    std::copy_if(_gameObjects.begin(), _gameObjects.end(),
                 std::back_inserter(objects),
                 [&tag](auto el) { return el->getTag() == tag; }
    );
    return objects;
}
