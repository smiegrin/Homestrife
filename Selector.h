#ifndef SELECTOR_H
#define SELECTOR_H

#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "SelectorGrid.h"

template <class T> class Selector : public DisplayObject{
public: enum direction {UP,DOWN,RIGHT,LEFT};
public: enum pattern {PLAIN,FASTBLINK,SLOWBLINK};

private:
    SelectorGrid<T>* gridSpot;
    sf::Color primaryColor;
    sf::Color secondaryColor;
    sf::RectangleShape shape;
    pattern currentPattern;
    int anim;
public:
    Selector(SelectorGrid<T>*); //starting grid spot goes here

    T* getSelected();
    sf::RectangleShape getShape();

    void setSelected(SelectorGrid<T>*);//put onto specific grid spot
    void setPrimaryColor(sf::Color);
    void setSecondaryColor(sf::Color);

    void move(direction);

    //from Display Object

    void drawSelf(sf::RenderWindow*);
};

template <class T> Selector<T>::Selector(SelectorGrid<T>* initGrid) {
    anim = 0;
    gridSpot = initGrid;
    primaryColor = sf::Color::White;
    secondaryColor = sf::Color::Red;
    shape = sf::RectangleShape(sf::Vector2f(gridSpot->getWidth(),gridSpot->getHeight()));
    shape.setPosition(sf::Vector2f(gridSpot->getXPos(),gridSpot->getYPos()));
    shape.setFillColor(sf::Color(0,0,0,0));
    shape.setOutlineColor(primaryColor);
    shape.setOutlineThickness(5);

    currentPattern = FASTBLINK;
}

template <class T> T* Selector<T>::getSelected() { return gridSpot->getSubject(); }

template <class T> void Selector<T>::setSelected(SelectorGrid<T>* newGrid) { gridSpot = newGrid; }

template <class T> void Selector<T>::setPrimaryColor(sf::Color newColor) { primaryColor = newColor; }

template <class T> void Selector<T>::setSecondaryColor(sf::Color newColor) { secondaryColor = newColor; }

template <class T> void Selector<T>::move(direction dir) {
    SelectorGrid<T>* oldGrid = gridSpot;
    switch (dir) {
    case UP:
        gridSpot = gridSpot->getUpward();
        break;
    case DOWN:
        gridSpot = gridSpot->getDownward();
        break;
    case LEFT:
        gridSpot = gridSpot->getLeftward();
        break;
    case RIGHT:
        gridSpot = gridSpot->getRightward();
        break;
    }
    if(gridSpot == NULL) gridSpot = oldGrid;

    shape.setPosition(gridSpot->getXPos(),gridSpot->getYPos());
    shape.setSize(sf::Vector2f(gridSpot->getWidth(),gridSpot->getHeight()));

}

template <class T> void Selector<T>::drawSelf(sf::RenderWindow* window) {
    switch (currentPattern) {
    case FASTBLINK:
        shape.setOutlineColor((shape.getOutlineColor() == primaryColor) ? secondaryColor : primaryColor);
        break;
    case SLOWBLINK:
        if (anim == 0) {
            shape.setOutlineColor((shape.getOutlineColor() == primaryColor) ? secondaryColor : primaryColor);
            anim = 10;
        }
        anim--;
        break;
    }
    window->draw(shape);
}

#endif
