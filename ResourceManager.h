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
    static sf::Texture RoseStand;
    static sf::Texture DaveStand;
    static sf::Texture DaveRun;
    static sf::Texture JadeStand;

    static Animation DaveRunAnim;

    static sf::Font ArialFont;
    static sf::Font PixelFont;

    static sf::SoundBuffer SimpleBeep;
    static sf::SoundBuffer LightWhoosh;
    static sf::SoundBuffer HeavyWhoosh;
    static sf::SoundBuffer Thud;

    static sf::Music SongTemp;

    static void initialize();
};

#endif // RESOURCEMANAGER_H
