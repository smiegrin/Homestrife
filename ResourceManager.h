#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class ResourceManager {
public:
    static sf::Texture GroundTexture;
    static sf::Texture SkyTexture;
    static sf::Texture JohnStand;
    static sf::Texture RoseStand;
    static sf::Texture DaveStand;
    static sf::Texture JadeStand;

    static sf::Font ArialFont;
    static sf::Font PixelFont;

    static sf::SoundBuffer SimpleBeep;

    static sf::Music SongTemp;

    static void initialize();
};

#endif // RESOURCEMANAGER_H
