#ifndef MAINMENU_H
#define MAINMENU_H

#include <SFML/Graphics.hpp>
#include "Button.h"

class MainMenu {
private:
    Button playButton;
    sf::Text title;
public:
    MainMenu();
    void open(sf::RenderWindow* window);
};

#endif
