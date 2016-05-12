#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <SFML/Graphics.hpp>

class ResourceManager {
public:
    static sf::Texture GroundTexture;
    static sf::Texture SkyTexture;

    static sf::Font ArialFont;

    static void initialize();
};

#endif // RESOURCEMANAGER_H
