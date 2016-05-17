#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "DisplayObject.h"
class GameObject : public DisplayObject {
public:
    virtual int logic() = 0;
};

#endif
