#include "CharacterScreen.h"

int CharacterScreen::open(sf::RenderWindow* window) {
    readyB = Button(325,400,150,50,sf::Color(0,0,0,255),"READY");
    johnB = Button(5,5,100,100,sf::Color(0,0,255,255),"JOHN");
    roseB = Button(5,395,100,100,sf::Color(128,0,128,255),"ROSE");
    daveB = Button(695,5,100,100,sf::Color(255,0,0,255),"DAVE");
    jadeB = Button(695,395,100,100,sf::Color(0,255,0,255),"JADE");

    dispList.push_back(&readyB);
    dispList.push_back(&johnB);
    dispList.push_back(&roseB);
    dispList.push_back(&daveB);
    dispList.push_back(&jadeB);

    bool done = false;

    while(!done) {
        sf::Event event;
        while(window->pollEvent(event)) {
            if(event.type == sf::Event::Closed) window->close(), done = true;
            if(event.type == sf::Event::MouseButtonPressed) {
                if(readyB.pointOnBox(event.mouseButton.x,event.mouseButton.y)) done = true; //open the battle screen
                //other buttons for selecting a character go here.
            }
        }

        window->clear(sf::Color::Black);
        for(std::list<DisplayObject*>::iterator it = dispList.begin(); it != dispList.end(); it++)
            (*it)->drawSelf(window);
        window->display();
    }
    return 0;
}
