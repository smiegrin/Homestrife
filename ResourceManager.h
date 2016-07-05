#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Animation.hpp"

class ResourceManager {
public:
    static sf::Texture GroundTexture;
    static sf::Texture SkyTexture;
    static sf::Texture JohnStand;
    static sf::Texture JohnRun;
    static sf::Texture JohnAtt;
    static sf::Texture RoseStand;
    static sf::Texture RoseRun;
    static sf::Texture RoseAttPow;
    static sf::Texture DaveStand;
    static sf::Texture DaveRun;
    static sf::Texture DaveAtt;
    static sf::Texture JadeStand;
    static sf::Texture JadeRun;
    static sf::Texture JadeAtt;
    static sf::Texture HealthOverlay;
    static sf::Texture HealthUnderlay;

    static Animation JohnRunAnim;
    static Animation JohnAttAnim;
    static Animation RoseRunAnim;
    static Animation RoseAttPowAnim;
    static Animation DaveRunAnim;
    static Animation DaveAttAnim;
    static Animation JadeRunAnim;
    static Animation JadeAttAnim;

    static sf::Font ArialFont;
    static sf::Font PixelFont;

    static sf::SoundBuffer SimpleBeep;
    static sf::SoundBuffer LightWhoosh;
    static sf::SoundBuffer HeavyWhoosh;
    static sf::SoundBuffer Thud;
    static sf::SoundBuffer GunShot;

    static sf::Music SongTemp;

    static void initialize();
};

#endif // RESOURCEMANAGER_H
