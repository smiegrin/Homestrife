#include "ResourceManager.h"

sf::Font ResourceManager::ArialFont = sf::Font();
sf::Font ResourceManager::PixelFont = sf::Font();

void ResourceManager::initialize(){
    ArialFont.loadFromFile("arial.ttf");
    PixelFont.loadFromFile("TYPOSTUCK.ttf");
}
