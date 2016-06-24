#include "ResourceManager.h"

sf::Font ResourceManager::ArialFont = sf::Font();
sf::Font ResourceManager::PixelFont = sf::Font();

sf::Texture ResourceManager::JohnStand = sf::Texture();
sf::Texture ResourceManager::JohnRun = sf::Texture();
sf::Texture ResourceManager::JohnAtt = sf::Texture();
sf::Texture ResourceManager::RoseStand = sf::Texture();
sf::Texture ResourceManager::RoseRun = sf::Texture();
sf::Texture ResourceManager::RoseAttPow = sf::Texture();
sf::Texture ResourceManager::DaveStand = sf::Texture();
sf::Texture ResourceManager::DaveRun = sf::Texture();
sf::Texture ResourceManager::DaveAtt = sf::Texture();
sf::Texture ResourceManager::JadeStand = sf::Texture();
sf::Texture ResourceManager::JadeRun = sf::Texture();
sf::Texture ResourceManager::JadeAtt = sf::Texture();
sf::Texture ResourceManager::HealthOverlay = sf::Texture();
sf::Texture ResourceManager::HealthUnderlay = sf::Texture();

Animation ResourceManager::JohnRunAnim = Animation();
Animation ResourceManager::JohnAttAnim = Animation();
Animation ResourceManager::RoseRunAnim = Animation();
Animation ResourceManager::RoseAttPowAnim = Animation();
Animation ResourceManager::DaveRunAnim = Animation();
Animation ResourceManager::DaveAttAnim = Animation();
Animation ResourceManager::JadeRunAnim = Animation();
Animation ResourceManager::JadeAttAnim = Animation();

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
    JohnRun.loadFromFile("Sprites/John_Run.png");
    JohnAtt.loadFromFile("Sprites/John_Attack.png");
    RoseStand.loadFromFile("Sprites/Rose_Stand.png");
    RoseRun.loadFromFile("Sprites/Rose_Run.png");
    RoseAttPow.loadFromFile("Sprites/Rose_Attack_Pow.png");
    DaveStand.loadFromFile("Sprites/Dave_Stand.png");
    DaveRun.loadFromFile("Sprites/Dave_Run.png");
    DaveAtt.loadFromFile("Sprites/Dave_Attack.png");
    JadeStand.loadFromFile("Sprites/Jade_Stand.png");
    JadeRun.loadFromFile("Sprites/Jade_Run.png");
    JadeAtt.loadFromFile("Sprites/Jade_Attack.png");
    HealthOverlay.loadFromFile("Sprites/Health_Overlay.png");
    HealthUnderlay.loadFromFile("Sprites/Health_Underlay.png");
//animations
    JohnRunAnim.setSpriteSheet(JohnRun);
    JohnRunAnim.addFrame(sf::IntRect(41,60,260,230));
    JohnRunAnim.addFrame(sf::IntRect(376,60,260,230));
    JohnRunAnim.addFrame(sf::IntRect(723,60,260,230));
    JohnRunAnim.addFrame(sf::IntRect(1037,60,260,230));
    JohnAttAnim.setSpriteSheet(JohnAtt);
    JohnAttAnim.addFrame(sf::IntRect(35,10,150,105));
    JohnAttAnim.addFrame(sf::IntRect(243,10,150,105));
    JohnAttAnim.addFrame(sf::IntRect(459,10,150,105));
    JohnAttAnim.addFrame(sf::IntRect(687,10,150,105));
    JohnAttAnim.addFrame(sf::IntRect(882,10,150,105));
    JohnAttAnim.addFrame(sf::IntRect(1068,10,150,105));

    RoseRunAnim.setSpriteSheet(RoseRun);
    RoseRunAnim.addFrame(sf::IntRect(40,55,160,230));
    RoseRunAnim.addFrame(sf::IntRect(205,55,160,230));
    RoseRunAnim.addFrame(sf::IntRect(365,55,160,230));
    RoseRunAnim.addFrame(sf::IntRect(205,55,160,230));
    RoseAttPowAnim.setSpriteSheet(RoseAttPow);
    RoseAttPowAnim.addFrame(sf::IntRect(109,10,160,95));
    RoseAttPowAnim.addFrame(sf::IntRect(317,10,160,95));
    RoseAttPowAnim.addFrame(sf::IntRect(506,10,160,95));
    RoseAttPowAnim.addFrame(sf::IntRect(689,10,160,95));
    RoseAttPowAnim.addFrame(sf::IntRect(855,10,160,95));
    RoseAttPowAnim.addFrame(sf::IntRect(1043,10,160,95));

    DaveRunAnim.setSpriteSheet(DaveRun);
    DaveRunAnim.addFrame(sf::IntRect(60,60,210,240));
    DaveRunAnim.addFrame(sf::IntRect(290,60,210,240));
    DaveRunAnim.addFrame(sf::IntRect(520,60,210,240));
    DaveRunAnim.addFrame(sf::IntRect(290,60,210,240));
    DaveAttAnim.setSpriteSheet(DaveAtt);
    DaveAttAnim.addFrame(sf::IntRect(40,20,175,105));
    DaveAttAnim.addFrame(sf::IntRect(255,20,175,105));
    DaveAttAnim.addFrame(sf::IntRect(430,20,175,105));
    DaveAttAnim.addFrame(sf::IntRect(620,20,175,105));
    DaveAttAnim.addFrame(sf::IntRect(805,20,175,105));
    DaveAttAnim.addFrame(sf::IntRect(1005,20,175,105));

    JadeRunAnim.setSpriteSheet(JadeRun);
    JadeRunAnim.addFrame(sf::IntRect(60,60,165,265));
    JadeRunAnim.addFrame(sf::IntRect(290,60,165,265));
    JadeRunAnim.addFrame(sf::IntRect(520,60,165,265));
    JadeRunAnim.addFrame(sf::IntRect(290,60,165,265));
    JadeAttAnim.setSpriteSheet(JadeAtt);
    JadeAttAnim.addFrame(sf::IntRect(68,25,295,150));
    JadeAttAnim.addFrame(sf::IntRect(431,25,295,150));
    JadeAttAnim.addFrame(sf::IntRect(858,25,295,150));

//sounds
    SimpleBeep.loadFromFile("Sounds/SimpleBeep.wav");
    LightWhoosh.loadFromFile("Sounds/LightWhoosh.wav");
    HeavyWhoosh.loadFromFile("Sounds/HeavyWhoosh.wav");
    Thud.loadFromFile("Sounds/HammerThud.wav");
//music
    SongTemp.openFromFile("Sounds/SongTemp.wav");
    SongTemp.setLoop(true);
}
