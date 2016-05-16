#include "ResourceManager.h"

sf::Font ResourceManager::ArialFont = sf::Font();
sf::Font ResourceManager::PixelFont = sf::Font();
sf::Texture ResourceManager::JohnStand = sf::Texture();
sf::Texture ResourceManager::RoseStand = sf::Texture();
sf::Texture ResourceManager::DaveStand = sf::Texture();
sf::Texture ResourceManager::JadeStand = sf::Texture();

void ResourceManager::initialize(){
    ArialFont.loadFromFile("arial.ttf");
    PixelFont.loadFromFile("TYPOSTUCK.ttf");

    JohnStand.loadFromFile("Sprites/John_Stand.gif");
    RoseStand.loadFromFile("Sprites/Rose_Stand.gif");
    DaveStand.loadFromFile("Sprites/Dave_Stand.gif");
    JadeStand.loadFromFile("Sprites/Jade_Stand.gif");
}
