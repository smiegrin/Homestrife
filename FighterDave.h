#ifndef FIGHTER_DAVE_H
#define FIGHTER_DAVE_H

#include "Fighter.h"
#include "AnimatedSprite.hpp"
#include <SFML/Audio.hpp>

class FighterDave : public Fighter {
private:
    AnimatedSprite runningSprite;
    AnimatedSprite attackingSprite;
    sf::Sprite standingSprite;
    sf::Sprite jumpingSprite;
    sf::Sound whoosh;
public:
    FighterDave(int);
    virtual int logic();
    virtual void input(Input);
    virtual void drawSelf(sf::RenderWindow*);
};

#endif // FIGHTER_ROSE_H
