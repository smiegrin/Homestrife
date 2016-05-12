#ifndef SCREEN_H
#define SCREEN_H

#include <SFML/Graphics.hpp>
#include <list>
#include "DisplayObject.h"
#include "GameObject.h"

class Screen {
protected:
    std::list<DisplayObject*> dispList;
    std::list<GameObject*> objList;
public:
    virtual int open(sf::RenderWindow*) = 0;
};

#endif // SCREEN_H
