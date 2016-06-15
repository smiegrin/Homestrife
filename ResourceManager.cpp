#include "ResourceManager.h"

sf::Font ResourceManager::ArialFont = sf::Font();
sf::Font ResourceManager::PixelFont = sf::Font();
sf::Texture ResourceManager::JohnStand = sf::Texture();
sf::Texture ResourceManager::RoseStand = sf::Texture();
sf::Texture ResourceManager::DaveStand = sf::Texture();
sf::Texture ResourceManager::DaveRun = sf::Texture();
sf::Texture ResourceManager::JadeStand = sf::Texture();
sf::Texture ResourceManager::JadeRun = sf::Texture();
sf::Texture ResourceManager::HealthOverlay = sf::Texture();
sf::Texture ResourceManager::HealthUnderlay = sf::Texture();
Animation ResourceManager::DaveRunAnim = Animation();
Animation ResourceManager::JadeRunAnim = Animation();
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
    JohnStand.loadFromFile("Sprites/John_Stand.png");
    RoseStand.loadFromFile("Sprites/Rose_Stand.png");
    DaveStand.loadFromFile("Sprites/Dave_Stand.png");
    DaveRun.loadFromFile("Sprites/Dave_Run.png");
    JadeStand.loadFromFile("Sprites/Jade_Stand.png");
    JadeRun.loadFromFile("Sprites/Jade_Run.png");
    HealthOverlay.loadFromFile("Sprites/Health_Overlay.png");
    HealthUnderlay.loadFromFile("Sprites/Health_Underlay.png");
//animations
    DaveRunAnim.setSpriteSheet(DaveRun);
    DaveRunAnim.addFrame(sf::IntRect(60,60,210,240));
    DaveRunAnim.addFrame(sf::IntRect(290,60,210,240));
    DaveRunAnim.addFrame(sf::IntRect(520,60,210,240));
    DaveRunAnim.addFrame(sf::IntRect(290,60,210,240));
    JadeRunAnim.setSpriteSheet(JadeRun);
    JadeRunAnim.addFrame(sf::IntRect(60,60,165,265));
    JadeRunAnim.addFrame(sf::IntRect(290,60,165,265));
    JadeRunAnim.addFrame(sf::IntRect(520,60,165,265));
    JadeRunAnim.addFrame(sf::IntRect(290,60,165,265));
//sounds
    SimpleBeep.loadFromFile("Sounds/SimpleBeep.wav");
    LightWhoosh.loadFromFile("Sounds/LightWhoosh.wav");
    HeavyWhoosh.loadFromFile("Sounds/HeavyWhoosh.wav");
    Thud.loadFromFile("Sounds/HammerThud.wav");
//music
    SongTemp.openFromFile("Sounds/SongTemp.wav");
    SongTemp.setLoop(true);
}
