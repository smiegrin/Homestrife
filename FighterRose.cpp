#include "FighterRose.h"
#include "ResourceManager.h"

#include <iostream>

FighterRose::FighterRose(int initDirection) {
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
    attackSpeed = 10;
    cooldown = 0;
    moveSpeed = 8;
    spriteSheet = ResourceManager::RoseStand;
    look = sf::Sprite();
    look.setTexture(spriteSheet);
    look.setTextureRect(sf::IntRect(100,70,180,220));
    look.setOrigin(100,100);
    status = READY;

    //initialize sounds
    wandSound.setBuffer(ResourceManager::LightWhoosh);
    wandSound.setLoop(false);
}

int FighterRose::logic() {
    yVel += 1;
    x += xVel;
    y += yVel;
    if (cooldown != 0) {
        cooldown--;
        if(cooldown == 3 && (status == LOW || status == LOW_AIR)) {
            wandSound.play();
            opponent->hitAt(x+direction*75,y,3);
        }
        if(cooldown == 6 && (status == LOW || status == LOW_AIR)) {
            wandSound.play();
            opponent->hitAt(x+direction*75,y+10,3);
        }
        if(cooldown == 9 && (status == LOW || status == LOW_AIR)) {
            wandSound.play();
            opponent->hitAt(x+direction*75,y-10,3);
        }
        if(cooldown == 0 && (status == LOW || status == HIGH || status == DOWN)) status = READY, xVel = 0;
        if(cooldown == 0 && (status == LOW_AIR || status == HIGH_AIR || status == DOWN_AIR)) status = READY_AIR;
    }
    if (y >= 350) {
        y = 350;
        yVel = 0;
        if(status == READY_AIR) status = READY;
        if(status == KO_AIR) status = KO;
        if(status == DOWN_AIR) status = DOWN;
        if(status == KO || status == DOWN) {
            if(xVel > 0) xVel -= 1;
            else if (xVel < 0) xVel += 1;
        }
    }
    return 0;
}

void FighterRose::input(Input command) {
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
    case ATTACK_LOW:
        if(cooldown <= 5 && (status == LOW || status == LOW_AIR)) cooldown += 5;
        if(status == READY) {
            status = LOW;
            cooldown = attackSpeed;
        }
        break;
    case ATTACK_HIGH:
        break;
    }
}

void FighterRose::drawSelf(sf::RenderWindow *window) {
    look.setPosition(x,y);
    look.setScale(direction,1);
    if(status == KO || status == KO_AIR) look.setRotation(90*-direction);
    else if(status == DOWN || status == DOWN_AIR) look.setRotation(30*-direction);
    else look.setRotation(0);
    window->draw(look);
}

bool FighterRose::hitAt(int hitX, int hitY, int hitPower = 0) {
    if (hitX >= x-width/2 && hitX <= x+width/2 && hitY >= y-height/2 && hitY <= y+height/2) {
        if(hitPower == 0) return true;
        health -= hitPower - defense;
        if (health <= 0){
            health = 0;
            status = KO_AIR;
            yVel = -hitPower;
            xVel = hitPower*direction*-1.2;
        }
        else {
            cooldown = hitPower;
            xVel = hitPower*-direction;
            if(status == READY || status == LOW || status == HIGH) status = DOWN;
            else if(status == READY_AIR || status == LOW_AIR || status == HIGH_AIR) status = DOWN_AIR;
        }
        return true;
    }
    return false;
}
