#include "FighterDave.h"
#include "ResourceManager.h"

#include <iostream>

FighterDave::FighterDave(int initDirection) {
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
    moveSpeed = 8;
    spriteSheet = ResourceManager::DaveStand;
    look = sf::Sprite();
    look.setTexture(spriteSheet);
    look.setTextureRect(sf::IntRect(150,150,200,200));
    look.setOrigin(100,100);
    status = READY;
}

int FighterDave::logic() {
    yVel += 1;
    x += xVel;
    y += yVel;
    if (cooldown != 0) {
        cooldown--;
        if(cooldown == 0 && (status == LOW || status == HIGH)) status = READY;
        if(cooldown == 0 && (status == LOW_AIR || status == HIGH_AIR)) status = READY_AIR;
    }
    if (y >= 350) {
        y = 350;
        if(status == READY_AIR) status = READY;
        if(status == KO_AIR) status = KO;
        if(status == DOWN_AIR) status = DOWN;
        if(status == KO) {
            if(xVel > 0) xVel -= 1;
            else if (xVel < 0) xVel += 1;
        }
    }
    return 0;
}

void FighterDave::input(Input command) {
    switch (command) {
    case JUMP:
        if (status == READY) {
            status = READY_AIR;
            yVel = -20;
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

void FighterDave::drawSelf(sf::RenderWindow *window) {
    look.setPosition(x,y);
    look.setScale(direction,1);
    if(status == KO || status == KO_AIR) look.setRotation(90*-direction);
    window->draw(look);
}

bool FighterDave::hitAt(int hitX, int hitY, int hitPower = 0) {
    if (hitX >= x-width/2 && hitX <= x+width/2 && hitY >= y-height/2 && hitY <= y+height/2) {
        std::cout << "oof.\n";
        health -= hitPower - defense;
        if (health <= 0){
            health = 0;
            status = KO_AIR;
            yVel = -hitPower;
            xVel = hitPower*direction*-1.2;
        }
        return true;
    }
    std::cout << "funny.\n";
    return false;
}
