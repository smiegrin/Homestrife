#include "BattleScreen.h"

BattleScreen::BattleScreen() {
    //get the status bar connected to the players here
}

int BattleScreen::open(sf::RenderWindow* window) {
    bool done = false;
    sf::Event event;
    while(!done) {
        while(window->pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window->close();
                return 0;
            }
            if (event.type == sf::Event::KeyPressed) {//do the gaming things
                if(event.key.code == sf::Keyboard::Escape) done = true; //might become a pause menu later
            }
        }

        for(std::list<GameObject*>::iterator it = objList.begin(); it != objList.end(); it++)
            (*it)->logic();

        window->clear(sf::Color::Black);
        for(std::list<GameObject*>::iterator it = objList.begin(); it != objList.end(); it++)
            (*it)->drawSelf(window);
        for(std::list<DisplayObject*>::iterator it = dispList.begin(); it != dispList.end(); it++)
            (*it)->drawSelf(window);
        window->display();
    }

    return 0; //later, return the winner
}
