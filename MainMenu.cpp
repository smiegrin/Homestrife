#include "MainMenu.h"
#include "Button.h"
#include "ResourceManager.h"
#include "CharacterScreen.h"

MainMenu::MainMenu() {
    playButton = Button(325,400,150,50,sf::Color(59,200,73,255),"PLAY");
    title = sf::Text();
    title.setString("HOMESTRIFE");
    title.setCharacterSize(50);
    title.setFont(ResourceManager::PixelFont);
}

int MainMenu::open(sf::RenderWindow* window) {
    while (window->isOpen()) {
        sf::Event event;
        while(window->pollEvent(event)) {
            if(event.type == sf::Event::Closed) window->close();
            if(event.type == sf::Event::MouseButtonPressed) {
                if(playButton.pointOnBox(event.mouseButton.x, event.mouseButton.y)) CharacterScreen().open(window); //play the game.
            }
        }

        window->clear(sf::Color(0,186,255,255));
        playButton.drawSelf(window);
        window->draw(title);
        window->display();
    }
    return 0;
}
