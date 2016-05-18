#ifndef CHARACTERSCREEN_H
#define CHARACTERSCREEN_H

#include <SFML/Audio.hpp>
#include "Screen.h"
#include "Button.h"

class CharacterScreen : public Screen {
private:
    Button readyB;
    Button johnB;
    Button roseB;
    Button daveB;
    Button jadeB;

    sf::Sound beep;
public:
    int open(sf::RenderWindow*);
};

#endif // CHARACTERSCREEN_H
