#ifndef FIGHTER_JADE_H
#define FIGHTER_JADE_H

#include "Fighter.h"
#include "AnimatedSprite.hpp"
#include <SFML/Audio.hpp>

class FighterJade : public Fighter {
private:
    AnimatedSprite runningSprite;
    sf::Sprite standingSprite;
    sf::Sprite jumpingSprite;
    sf::Sound gunSound;
public:
    FighterJade(int);
    virtual int logic();
    virtual void input(Input);
    virtual void drawSelf(sf::RenderWindow*);
    virtual bool hitAt(int,int,int,int,int);
};

#endif // FIGHTER_ROSE_H
