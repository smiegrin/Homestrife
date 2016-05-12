#include "MainMenu.h"
#include "Button.h"
#include "ResourceManager.h"

MainMenu::MainMenu() {
    playButton = Button(325,400,150,50,sf::Color::Green,"PLAY");
    title = sf::Text();
    title.setString("HOMESTRIFE");
    title.setCharacterSize(50);
    title.setFont(ResourceManager::ArialFont);
}

void MainMenu::open(sf::RenderWindow* window) {
    while (window->isOpen()) {
        sf::Event event;
        while(window->pollEvent(event)) {
            if(event.type == sf::Event::Closed) window->close();
            if(event.type == sf::Event::MouseButtonPressed) {
                if(playButton.pointOnBox(event.mouseButton.x, event.mouseButton.y)); //play the game.
            }
        }

        window->clear(sf::Color::Cyan);
        playButton.drawSelf(window);
        window->draw(title);
        window->display();
    }
}
