#include <SFML/Graphics.hpp>
#include "MainMenu.h"
#include "ResourceManager.h"

int main()
{
    ResourceManager::initialize();

    sf::RenderWindow window(sf::VideoMode(800, 500), "Homestrife", sf::Style::Titlebar | sf::Style::Close);
    MainMenu().open(&window);

    return 0;
}
