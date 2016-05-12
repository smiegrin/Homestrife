#ifndef DISPLAYOBJECT_H
#define DISPLAYOBJECT_H

#include <SFML/Graphics.hpp>

class DisplayObject {
public:
    virtual void drawSelf(sf::RenderWindow*) =0;
};

#endif
