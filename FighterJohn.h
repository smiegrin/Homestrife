#ifndef FIGHTER_JOHN_H
#define FIGHTER_JOHN_H

#include "Fighter.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class FighterJohn : public Fighter {
private:
    sf::Sound whoosh;
    sf::Sound thud;
public:
    FighterJohn(int);
    virtual int logic();
    virtual void input(Input);
    virtual void drawSelf(sf::RenderWindow*);
    virtual bool hitAt(int,int,int);
};

#endif // FIGHTER_JOHN_H
