#include "ResourceManager.h"

sf::Font ResourceManager::ArialFont = sf::Font();

void ResourceManager::initialize(){
    ArialFont.loadFromFile("arial.ttf");
}
