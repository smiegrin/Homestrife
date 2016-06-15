#ifndef HEALTHBAR_H
#define HEALTHBAR_H

#include "GameObject.h"
#include "Fighter.h"
#include <SFML/Graphics.hpp>

class HealthBar : public GameObject {
private:
    Fighter* p1;
    Fighter* p2;
    sf::Sprite overlay;
    sf::Sprite underlay;
    sf::RectangleShape p1Health;
    sf::RectangleShape p1Energy;
    sf::RectangleShape p2Health;
    sf::RectangleShape p2Energy;
public:
    HealthBar();
    HealthBar(Fighter*,Fighter*);
    void drawSelf(sf::RenderWindow*);
    int logic();
};

#endif
