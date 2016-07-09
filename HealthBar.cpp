#include "HealthBar.h"
#include "ResourceManager.h"

HealthBar::HealthBar() {
    //don't use this one yet.
}

HealthBar::HealthBar(Fighter* p1ptr, Fighter* p2ptr) {
    //pointers to fighters
    p1 = p1ptr;
    p2 = p2ptr;

    //health indicators
    p1Health = sf::RectangleShape(sf::Vector2f(361,16));
    p1Health.setFillColor(sf::Color::Blue);
    p1Health.setPosition(431,5);

    p2Health = sf::RectangleShape(sf::Vector2f(361,16));
    p2Health.setFillColor(sf::Color::Red);
    p2Health.setPosition(8,5);

    //energy indicators
    p1Energy = sf::RectangleShape(sf::Vector2f(400,34));
    p1Energy.setFillColor(sf::Color::Blue);
    p1Energy.setPosition(400,21);

    p2Energy = sf::RectangleShape(sf::Vector2f(400,34));
    p2Energy.setFillColor(sf::Color::Red);
    p2Energy.setPosition(0,21);

    //overlay
    overlay = sf::Sprite();
    overlay.setTexture(ResourceManager::HealthOverlay);
    underlay = sf::Sprite();
    underlay.setTexture(ResourceManager::HealthUnderlay);
}

void HealthBar::drawSelf(sf::RenderWindow* window) {
    window->draw(p1Energy);
    window->draw(p2Energy);
    window->draw(underlay);
    window->draw(p1Health);
    window->draw(p2Health);
    window->draw(overlay);
}

int HealthBar::logic() {
    p1Health.setSize(sf::Vector2f(p1->getHealthPercent()*3.61,16));
    p1Health.setPosition(792-p1->getHealthPercent()*3.61,5);
    if(p1->getHealthPercent() < 15) p1Health.setFillColor((p1Health.getFillColor() == sf::Color::Blue) ? sf::Color(220,220,255,255) : sf::Color::Blue);
    p2Health.setSize(sf::Vector2f(p2->getHealthPercent()*3.61,16));
    p2Health.setPosition(8,5);
    if(p2->getHealthPercent() < 15) p2Health.setFillColor((p2Health.getFillColor() == sf::Color::Red) ? sf::Color(255,220,220,255) : sf::Color::Red);
    p1Energy.setSize(sf::Vector2f(p1->getEnergyPercent()*4,29));
    p1Energy.setPosition(800-p1->getEnergyPercent()*4,21);
    p2Energy.setSize(sf::Vector2f(p2->getEnergyPercent()*4,29));
    p2Energy.setPosition(0,21);
	return 0;
}
