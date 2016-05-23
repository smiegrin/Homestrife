#ifndef FIGHTER_DAVE_H
#define FIGHTER_DAVE_H

#include "Fighter.h"
#include "AnimatedSprite.hpp"

class FighterDave : public Fighter {
private:
    AnimatedSprite runningSprite;
    sf::Sprite standingSprite;
    sf::Sprite jumpingSprite;
public:
    FighterDave(int);
    virtual int logic();
    virtual void input(Input);
    virtual void drawSelf(sf::RenderWindow*);
    virtual bool hitAt(int,int,int);
};

#endif // FIGHTER_ROSE_H
