#ifndef FIGHTER_JADE_H
#define FIGHTER_JADE_H

#include "Fighter.h"

class FighterJade : public Fighter {
public:
    FighterJade(int);
    virtual int logic();
    virtual void input(Input);
    virtual void drawSelf(sf::RenderWindow*);
};

#endif // FIGHTER_ROSE_H
