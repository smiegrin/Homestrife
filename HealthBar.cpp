#include "HealthBar.h"

HealthBar::HealthBar() {
    //don't use this one yet.
}

HealthBar::HealthBar(Fighter* p1ptr, Fighter* p2ptr) {
    //pointers to fighters
    p1 = p1ptr;
    p2 = p2ptr;

    //health indicators
    p1Health = sf::RectangleShape(sf::Vector2f(400,20));
    p1Health.setFillColor(sf::Color::Blue);
    p1Health.setPosition(400,0);

    p2Health = sf::RectangleShape(sf::Vector2f(400,20));
    p2Health.setFillColor(sf::Color::Red);
    p2Health.setPosition(0,0);

    //TODO: overlay
}

void HealthBar::drawSelf(sf::RenderWindow* window) {
    window->draw(p1Health);
    window->draw(p2Health);
    //window->draw(overlay);
}

int HealthBar::logic() {
    p1Health.setSize(sf::Vector2f(p1->getHealthPercent()*4,20));
    p1Health.setPosition(800-p1->getHealthPercent()*4,0);
    p2Health.setSize(sf::Vector2f(p2->getHealthPercent()*4,20));
    p2Health.setPosition(0,0);
}
