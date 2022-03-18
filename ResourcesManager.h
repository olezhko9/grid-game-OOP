#ifndef GAME_RESOURCESMANAGER_H
#define GAME_RESOURCESMANAGER_H

#include <unordered_map>
#include "SFML/Graphics.hpp"
#include "definitions.h"

class ResourcesManager {
public:
SingletonHeader(ResourcesManager)

public:
    void loadTexture(std::string &filepath);

    const sf::Texture &getTexture(const std::string &filepath) const;

private:
    std::unordered_map<std::string, std::unique_ptr<sf::Texture>> resources;
};

#endif //GAME_RESOURCESMANAGER_H
