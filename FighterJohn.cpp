#include "FighterJohn.h"
#include "ResourceManager.h"

#include <iostream>

FighterJohn::FighterJohn(int initDirection) {
    direction = initDirection;
    width = 100;
    height = 100;
    anim = 0;
    health = 100;
    maxHealth = 100;
    power = 2;
    defense = 2;
    attackSpeed = 10;
    cooldown = 0;
    moveSpeed = 5;
    spriteSheet = ResourceManager::JohnStand;
    look = sf::Sprite();
    look.setTexture(spriteSheet);
    look.setTextureRect(sf::IntRect(0,0,200,200));
    status = READY;
}

int FighterJohn::logic() {
    yVel += 1;
    x += xVel;
    y += yVel;
    if (y >= 250) {
        y = 250;
        if(status == READY_AIR) status = READY;
        if(status == KO_AIR) status = KO;
        if(status == DOWN_AIR) status = DOWN;
    }
    return 0;
}

void FighterJohn::input(Input command) {
    switch (command) {
    case JUMP:
        std::cout << "JUNMP! " << x << " " << y << "\n";
        if (status == READY) {
            status = READY_AIR;
            yVel = -10;
        }
        if (status == READY_AIR) {
            yVel -= 1;
        }
        if (status == DOWN && cooldown == 0) {
            status = READY_AIR;
            yVel = -5;
        }
        break;
    case GO_LEFT:
        if(status == (KO | DOWN | KO_AIR | DOWN_AIR)) break;
        direction = -1;
        xVel = direction*moveSpeed;
        break;
    case GO_RIGHT:
        if(status == (KO | DOWN | KO_AIR | DOWN_AIR)) break;
        direction = 1;
        xVel = direction*moveSpeed;
        break;
    case STOP_LEFT:
        if(status == (KO | DOWN | KO_AIR | DOWN_AIR)) break;
        if(xVel > 0) break;
        xVel = 0;
        break;
    case STOP_RIGHT:
        if(status == (KO | DOWN | KO_AIR | DOWN_AIR)) break;
        if(xVel < 0) break;
        xVel = 0;
        break;
    case ATTACK_LOW:
        break;
    case ATTACK_HIGH:
        break;
    }
}

void FighterJohn::drawSelf(sf::RenderWindow *window) {
    look.setPosition(x,y);
    look.setScale(direction,1);
    window->draw(look);
}