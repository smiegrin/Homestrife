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
    p1Health.setPosition(431,6);

    p2Health = sf::RectangleShape(sf::Vector2f(361,16));
    p2Health.setFillColor(sf::Color::Red);
    p2Health.setPosition(8,6);

    //overlay
    overlay = sf::Sprite();
    overlay.setTexture(ResourceManager::HealthOverlay);
    underlay = sf::Sprite();
    underlay.setTexture(ResourceManager::HealthUnderlay);
}

void HealthBar::drawSelf(sf::RenderWindow* window) {
    window->draw(underlay);
    window->draw(p1Health);
    window->draw(p2Health);
    window->draw(overlay);
}

int HealthBar::logic() {
    p1Health.setSize(sf::Vector2f(p1->getHealthPercent()*3.61,16));
    p1Health.setPosition(792-p1->getHealthPercent()*3.61,5);
    p2Health.setSize(sf::Vector2f(p2->getHealthPercent()*3.61,16));
    p2Health.setPosition(8,5);
}
