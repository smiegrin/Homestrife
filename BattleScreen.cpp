#include "BattleScreen.h"
#include "Fighter.h"
#include "ResourceManager.h"

BattleScreen::BattleScreen(Fighter* p1Ptr) {
    p1 = p1Ptr;
    //initialize player 1
    p1->setPosition(400,100);
    dispList.push_back(p1);
    objList.push_back(p1);

    beep.setBuffer(ResourceManager::SimpleBeep);
    beep.setLoop(false);
    //get the status bar connected to the players here
}

int BattleScreen::open(sf::RenderWindow* window) {
    bool done = false;
    sf::Event event;

    //temporary ground
    sf::RectangleShape ground = sf::RectangleShape(sf::Vector2f(800,50));
    ground.setPosition(0,450);
    ground.setFillColor(sf::Color(83,83,83,255));

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
                    beep.play();
                    p1->input(Fighter::JUMP);
                    break;
                case sf::Keyboard::Left:
                    p1->input(Fighter::GO_LEFT);
                    break;
                case sf::Keyboard::Right:
                    p1->input(Fighter::GO_RIGHT);
                    break;
                case sf::Keyboard::Slash:
                    p1->input(Fighter::ATTACK_LOW);
                    break;
                case sf::Keyboard::Period:
                    p1->input(Fighter::ATTACK_HIGH);
                    break;
                }
            }
            if (event.type == sf::Event::KeyReleased) {
                switch (event.key.code) {
                case sf::Keyboard::Left:
                    p1->input(Fighter::STOP_LEFT);
                    break;
                case sf::Keyboard::Right:
                    p1->input(Fighter::STOP_RIGHT);
                    break;
                }
            }
        }

        for(std::list<GameObject*>::iterator it = objList.begin(); it != objList.end(); it++)
            (*it)->logic();

        window->clear(sf::Color(238,238,238,255));
        window->draw(ground);
        for(std::list<GameObject*>::iterator it = objList.begin(); it != objList.end(); it++)
            (*it)->drawSelf(window);
        for(std::list<DisplayObject*>::iterator it = dispList.begin(); it != dispList.end(); it++)
            (*it)->drawSelf(window);
        window->display();
    }

    return 0; //later, return the winner
}
