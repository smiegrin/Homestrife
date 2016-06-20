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
    energy = 50;
    maxEnergy = 100;
    power = 2;
    defense = 2;
    attackSpeed = 20;
    cooldown = 0;
    moveSpeed = 8;
    standingSprite = sf::Sprite();
    standingSprite.setTexture(ResourceManager::JohnStand);
    standingSprite.setTextureRect(sf::IntRect(15,70,265,230));
    standingSprite.setOrigin(180,100);
    status = READY;

    //initialize sounds
    whoosh.setBuffer(ResourceManager::HeavyWhoosh);
    whoosh.setLoop(false);
    thud.setBuffer(ResourceManager::Thud);
    thud.setLoop(false);
}

int FighterJohn::logic() {
    yVel += 1;
    x += xVel;
    y += yVel;
    if (cooldown != 0) {
        if((status == ATTACK || status == ATTACK_AIR) && cooldown == 1)  {
            opponent->hitAt(x+direction*100, y,10,direction*5,-15);
            thud.play();
        }
        else if ((status == SPECIAL || status == SPECIAL_AIR) && cooldown == 1) {
            opponent->hitAt(opponent->getXPos(), opponent->getYPos(), 0, direction*20,0);
            //play the windy thing.
        }
        cooldown--;
        if(cooldown == 0 && (status == ATTACK || status == SPECIAL || status == DOWN)) status = READY, xVel = 0;
        if(cooldown == 0 && (status == ATTACK_AIR || status == SPECIAL_AIR || status == DOWN_AIR)) status = READY_AIR;
    }
    if (y >= 350) {
        y = 350;
        yVel = 0;
        if(status == READY_AIR) status = READY;
        if(status == KO_AIR) status = KO;
        if(status == DOWN_AIR) status = DOWN;
        if(status == SPECIAL_AIR) status = SPECIAL;
        if(status == KO || status == SPECIAL || status == ATTACK || status == DOWN) {
            if(xVel > 0) xVel -= 1;
            else if (xVel < 0) xVel += 1;
        }
    }
    return 0;
}

void FighterJohn::input(Input command) {
    switch (command) {
    case JUMP:
        if (status == READY) {
            status = READY_AIR;
            yVel = -20;
        }
        if (status == READY_AIR && yVel >= 0) {
            yVel = -5;
        }
        if (status == DOWN && cooldown == 0) {
            status = READY_AIR;
            yVel = -5;
        }
        break;
    case GO_LEFT:
        if(cooldown != 0 || health == 0) break;
        direction = -1;
        xVel = direction*moveSpeed;
        break;
    case GO_RIGHT:
        if(cooldown != 0 || health == 0) break;
        direction = 1;
        xVel = direction*moveSpeed;
        break;
    case STOP_LEFT:
        if(cooldown != 0 || health == 0) break;
        if(xVel > 0) break;
        xVel = 0;
        break;
    case STOP_RIGHT:
        if(cooldown != 0 || health == 0) break;
        if(xVel < 0) break;
        xVel = 0;
        break;
    case ATT_REGULAR:
        if(cooldown != 0 || health == 0) break;
        if(status == READY) {
            status = ATTACK;
            whoosh.play();
            cooldown = attackSpeed;
        }
        else if (status == READY_AIR) {
            status = ATTACK_AIR;
            whoosh.play();
            cooldown = attackSpeed;
        }
        break;
    case ATT_SPECIAL:
        if(cooldown != 0 || health == 0 || energy < 10) break;
        energy -= 10;
        if(status == READY) {
            status = SPECIAL;
            cooldown = attackSpeed;
        }
        else if (status == READY_AIR) {
            status = SPECIAL_AIR;
            cooldown = attackSpeed;
        }
        break;
    }
}

void FighterJohn::drawSelf(sf::RenderWindow *window) {
    //update frame for animation
    standingSprite.setPosition(x,y);
    standingSprite.setScale(direction,1);
    if(status == KO || status == KO_AIR) standingSprite.setRotation(90*-direction);
    else if(status == DOWN || status == DOWN_AIR) standingSprite.setRotation(30*-direction);
    else standingSprite.setRotation(0);
    window->draw(standingSprite);
}

bool FighterJohn::hitAt(int hitX, int hitY, int hitPower, int forceX, int forceY) {
    if(Fighter::hitAt(hitX,hitY,hitPower,forceX,forceY)) {
        energy += hitPower;
        if(energy >= maxEnergy) energy = maxEnergy;
        return true;
    }
    else return false;
}
