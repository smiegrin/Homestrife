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
    sf::Sprite underLay;
    sf::RectangleShape p1Health;
    sf::RectangleShape p2Health;
public:
    HealthBar();
    HealthBar(Fighter*,Fighter*);
    void drawSelf(sf::RenderWindow*);
    int logic();
};

#endif
