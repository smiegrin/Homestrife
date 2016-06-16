#include "BattleScreen.h"
#include "Fighter.h"
#include "ResourceManager.h"
#include <string>
#include <iostream>

BattleScreen::BattleScreen(Fighter* p1Ptr, Fighter* p2Ptr) {
    p1 = p1Ptr;
    p2 = p2Ptr;
    //initialize players position and connect to display and engine
    p1->setPosition(600,100);
    dispList.push_back(p1);
    objList.push_back(p1);
    p2->setPosition(200,100);
    dispList.push_back(p2);
    objList.push_back(p2);

    //status bar
    healthBar = HealthBar(p1,p2);
    dispList.push_back(&healthBar);
    objList.push_back(&healthBar);

    beep.setBuffer(ResourceManager::SimpleBeep);
    beep.setLoop(false);
}

int BattleScreen::open(sf::RenderWindow* window) {
    bool done = false;
    bool paused = true;
    sf::Event event;
    int anim = -240;

    //countdown, TODO: move to constructor
    FlashText countdown = FlashText("3",sf::Color::Red, sf::Color::Blue);
    countdown.setFont(&ResourceManager::PixelFont);
    countdown.setSize(30);
    countdown.setPosition(400-countdown.getWidth()/2, 60);
    dispList.push_front(&countdown);

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
            if (event.type == sf::Event::MouseButtonPressed) {
                p1->hitAt(event.mouseButton.x, event.mouseButton.y, 10);
                p2->hitAt(event.mouseButton.x, event.mouseButton.y, 10);
            }
            if (!paused && event.type == sf::Event::KeyPressed) {//do the gaming things
                switch (event.key.code) {
                case sf::Keyboard::Escape:
                    done = true; //might become a pause menu later
                    break;
                //player 1 controlls
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
                    p1->input(Fighter::ATT_REGULAR);
                    break;
                case sf::Keyboard::Period:
                    p1->input(Fighter::ATT_SPECIAL);
                    break;
                //player 2 controlls
                case sf::Keyboard::W:
                    beep.play();
                    p2->input(Fighter::JUMP);
                    break;
                case sf::Keyboard::A:
                    p2->input(Fighter::GO_LEFT);
                    break;
                case sf::Keyboard::D:
                    p2->input(Fighter::GO_RIGHT);
                    break;
                case sf::Keyboard::LShift:
                    p2->input(Fighter::ATT_REGULAR);
                    break;
                case sf::Keyboard::Z:
                    p2->input(Fighter::ATT_SPECIAL);
                    break;
                }
            }
            if (!paused && event.type == sf::Event::KeyReleased) {
                switch (event.key.code) {
                case sf::Keyboard::Left:
                    p1->input(Fighter::STOP_LEFT);
                    break;
                case sf::Keyboard::Right:
                    p1->input(Fighter::STOP_RIGHT);
                    break;
                case sf::Keyboard::A:
                    p2->input(Fighter::STOP_LEFT);
                    break;
                case sf::Keyboard::D:
                    p2->input(Fighter::STOP_RIGHT);
                    break;
                }
            }
        }

        for(std::list<GameObject*>::iterator it = objList.begin(); it != objList.end(); it++)
            (*it)->logic();

        if(anim < 0) {
            anim++;
            if (anim == -180) {
                countdown.setString("2");
                countdown.setPosition(400-countdown.getWidth()/2, 60);
                beep.play();
            }
            if (anim == -120) {
                countdown.setString("1");
                countdown.setPosition(400-countdown.getWidth()/2, 60);
                beep.play();
            }
            if (anim == -60) {
                countdown.setString("STRIFE!");
                countdown.setSize(90);
                countdown.setPosition(400-countdown.getWidth()/2, 30);
                beep.play();
                paused = false;
            }
            if (anim >= -30) {
                countdown.setPosition(400-countdown.getWidth()/2, 30-(anim+30)*(anim+30));
            }
        }

        if(p1->getHealthNum() == 0 || p2->getHealthNum() == 0) {//check if someone has won
            if (anim == 0) {
                //some kind of victory song should play
                FlashText* winText;
                if(p2->getHealthNum() == 0) winText = new FlashText("PLAYER 1 WINS", sf::Color::Blue,sf::Color::Black);
                else winText = new FlashText("PLAYER 2 WINS", sf::Color::Red, sf::Color::White);
                winText->setSize(50);
                winText->setOffset(5);
                winText->setFont(&ResourceManager::PixelFont);
                winText->setPosition(400-winText->getWidth()/2, 20);
                dispList.push_front(winText);
            }
            anim++;
            if (anim == 180) done = true;
        }

        window->clear(sf::Color(238,238,238,255));
        window->draw(ground);
        for(std::list<GameObject*>::iterator it = objList.begin(); it != objList.end(); it++)
            (*it)->drawSelf(window);
        for(std::list<DisplayObject*>::iterator it = dispList.begin(); it != dispList.end(); it++)
            (*it)->drawSelf(window);
        window->display();
    }

    //possibly some kind of after-battle screen should be called here.

    return 0; //later, return the winner
}
