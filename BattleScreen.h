#ifndef BATTLESCREEN_H
#define BATTLESCREEN_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Screen.h"
#include "Fighter.h"
#include "FlashText.h"

class BattleScreen : public Screen {
private:
    Fighter* p1;
    Fighter* p2;
    //ground/terrain
    //health/status bar
    sf::Sound beep;
public:
    BattleScreen(Fighter*,Fighter*);
    virtual int open(sf::RenderWindow*);
};

#endif // BATTLESCREEN_H
