#include "ResourceManager.h"

sf::Font ResourceManager::ArialFont = sf::Font();
sf::Font ResourceManager::PixelFont = sf::Font();
sf::Texture ResourceManager::JohnStand = sf::Texture();
sf::Texture ResourceManager::RoseStand = sf::Texture();
sf::Texture ResourceManager::DaveStand = sf::Texture();
sf::Texture ResourceManager::JadeStand = sf::Texture();
sf::SoundBuffer ResourceManager::SimpleBeep = sf::SoundBuffer();
sf::SoundBuffer ResourceManager::LightWhoosh = sf::SoundBuffer();
sf::SoundBuffer ResourceManager::HeavyWhoosh = sf::SoundBuffer();
sf::SoundBuffer ResourceManager::Thud = sf::SoundBuffer();
sf::Music ResourceManager::SongTemp;

void ResourceManager::initialize(){
//fonts
    ArialFont.loadFromFile("arial.ttf");
    PixelFont.loadFromFile("TYPOSTUCK.ttf");
//sprites
    JohnStand.loadFromFile("Sprites/John_Stand.gif");
    RoseStand.loadFromFile("Sprites/Rose_Stand.gif");
    DaveStand.loadFromFile("Sprites/Dave_Stand.gif");
    JadeStand.loadFromFile("Sprites/Jade_Stand.gif");
//sounds
    SimpleBeep.loadFromFile("Sounds/SimpleBeep.wav");
    LightWhoosh.loadFromFile("Sounds/LightWhoosh.wav");
    HeavyWhoosh.loadFromFile("Sounds/HeavyWhoosh.wav");
    Thud.loadFromFile("Sounds/HammerThud.wav");
//music
    SongTemp.openFromFile("Sounds/SongTemp.wav");
    SongTemp.setLoop(true);
}
