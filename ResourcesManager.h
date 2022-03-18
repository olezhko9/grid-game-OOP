#ifndef GAME_RESOURCESMANAGER_H
#define GAME_RESOURCESMANAGER_H

#include <unordered_map>
#include "SFML/Graphics.hpp"

class ResourcesManager {
public:
    ResourcesManager(ResourcesManager &) = delete;

    void operator=(const ResourcesManager &) = delete;

    static ResourcesManager *getInstance();

    ResourcesManager *loadTexture(std::string &filepath);

    const sf::Texture &getTexture(const std::string &filepath) const;

private:
    ResourcesManager() = default;

    static ResourcesManager *_instance;

    std::unordered_map<std::string, std::unique_ptr<sf::Texture>> resources;
};

#endif //GAME_RESOURCESMANAGER_H
