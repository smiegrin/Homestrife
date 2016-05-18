#ifndef FIGHTER_ROSE_H
#define FIGHTER_ROSE_H

#include "Fighter.h"

class FighterRose : public Fighter {
public:
    FighterRose(int);
    virtual int logic();
    virtual void input(Input);
    virtual void drawSelf(sf::RenderWindow*);
};

#endif // FIGHTER_ROSE_H
