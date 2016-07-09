#include "MainMenu.h"
#include "Button.h"
#include "ResourceManager.h"
#include "CharacterScreen.h"
#include <math.h>

MainMenu::MainMenu() {
    playButton = Button(325,400,150,50,sf::Color(59,200,73,255),"PLAY");
    title = sf::Text();
    title.setString("HOMESTRIFE");
    title.setCharacterSize(50);
    title.setFont(ResourceManager::PixelFont);
}

int MainMenu::open(sf::RenderWindow* window) {
    ResourceManager::SongTemp.play();
    int anim = 0;
    sf::RectangleShape fadeOverlay = sf::RectangleShape(sf::Vector2f(800,500));
    fadeOverlay.setFillColor(sf::Color(0,0,0,0));
    while (window->isOpen()) {
        sf::Event event;
        while(window->pollEvent(event)) {
            if(event.type == sf::Event::Closed) window->close();
            if(event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Escape) window->close();
                if (event.key.code == sf::Keyboard::Return) anim = 121;
            }
            if(event.type == sf::Event::MouseButtonPressed) {
                if(playButton.pointOnBox(event.mouseButton.x, event.mouseButton.y)) anim = 121;
            }
        }

        if(anim < 120) title.setPosition(5,pow((float)(anim - 120),3)/-1728), anim++;
        if(anim == 120) title.setPosition(5,0);
        if(anim >= 121) fadeOverlay.setFillColor(sf::Color(0,0,0,255*(anim-120)/60)), anim++;
        if(anim == 180) {
            ResourceManager::SongTemp.stop();
            CharacterScreen().open(window); //play the game.
            anim = 120;
            fadeOverlay.setFillColor(sf::Color(0,0,0,0));
            ResourceManager::SongTemp.play();
        }

        window->clear(sf::Color(0,186,255,255));
        playButton.drawSelf(window);
        window->draw(title);
        window->draw(fadeOverlay);
        window->display();
    }
    return 0;
}
