#include "ResourcesManager.h"

SingletonBody(ResourcesManager)

ResourcesManager::ResourcesManager() = default;

void ResourcesManager::loadTexture(std::string filepath) {
    std::unique_ptr<sf::Texture> texture = std::make_unique<sf::Texture>();

    if (!texture->loadFromFile(filepath)) {
        throw std::runtime_error("Unable to load " + filepath);
    }

    resources[filepath] = std::move(texture);
}

const sf::Texture &ResourcesManager::getTexture(const std::string &filepath) const {
    return *resources.at(filepath);
}