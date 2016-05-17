#ifndef FIGHTER_JOHN_H
#define FIGHTER_JOHN_H

#include "Fighter.h"
#include <SFML/Graphics.hpp>
class FighterJohn : public Fighter {
public:
    FighterJohn(int);
    virtual int logic();
    virtual void input(Input);
    virtual void drawSelf(sf::RenderWindow*);
};

#endif // FIGHTER_JOHN_H
