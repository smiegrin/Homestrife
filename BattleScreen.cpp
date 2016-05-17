#include "BattleScreen.h"
#include "FighterJohn.h"

BattleScreen::BattleScreen() {
    //get the status bar connected to the players here
}

int BattleScreen::open(sf::RenderWindow* window) {
    bool done = false;
    sf::Event event;

    //temporary test player
    FighterJohn testP = FighterJohn(1);
    testP.setPosition(400,100);
    dispList.push_back(&testP);
    objList.push_back(&testP);

    while(!done) {
        while(window->pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window->close();
                return 0;
            }
            if (event.type == sf::Event::KeyPressed) {//do the gaming things
                switch (event.key.code) {
                case sf::Keyboard::Escape:
                    done = true; //might become a pause menu later
                    break;
                case sf::Keyboard::Up:
                    testP.input(Fighter::JUMP);
                    break;
                case sf::Keyboard::Left:
                    testP.input(Fighter::GO_LEFT);
                    break;
                case sf::Keyboard::Right:
                    testP.input(Fighter::GO_RIGHT);
                    break;
                }
            }
            if (event.type == sf::Event::KeyReleased) {
                switch (event.key.code) {
                case sf::Keyboard::Left:
                    testP.input(Fighter::STOP_LEFT);
                    break;
                case sf::Keyboard::Right:
                    testP.input(Fighter::STOP_RIGHT);
                    break;
                }
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
