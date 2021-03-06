#ifndef FIGHTER_ROSE_H
#define FIGHTER_ROSE_H

#include "Fighter.h"
#include "AnimatedSprite.hpp"
#include <SFML/Audio.hpp>

class FighterRose : public Fighter {
private:
    AnimatedSprite runningSprite;
    AnimatedSprite attPowSprite;
    sf::Sprite standingSprite;
    sf::Sprite jumpingSprite;
    sf::Sound wandSound;
public:
    FighterRose(int);
    virtual int logic();
    virtual void input(Input);
    virtual void drawSelf(sf::RenderWindow*);
};

#endif // FIGHTER_ROSE_H
