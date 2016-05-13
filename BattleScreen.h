#ifndef BATTLESCREEN_H
#define BATTLESCREEN_H

#include <SFML/Graphics.hpp>
#include "Screen.h"

class BattleScreen : public Screen {
    //player objects
    //ground/terrain
    //health/status bar
public:
    BattleScreen(); //players needed here
    virtual int open(sf::RenderWindow*);
};

#endif // BATTLESCREEN_H
