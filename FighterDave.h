#ifndef FIGHTER_DAVE_H
#define FIGHTER_DAVE_H

#include "Fighter.h"

class FighterDave : public Fighter {
public:
    FighterDave(int);
    virtual int logic();
    virtual void input(Input);
    virtual void drawSelf(sf::RenderWindow*);
};

#endif // FIGHTER_ROSE_H
