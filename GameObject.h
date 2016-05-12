#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "DisplayObject.h"
class GameObject : public DisplayObject {
public:
    virtual int logic();
    virtual sf::Vector2f getSize();
    virtual sf::Vector2f getPosition();
    virtual sf::Vector2f getVelocity();

    virtual bool pointOn(float,float);
    virtual bool pointOn(sf::Vector2f);
};

#endif
