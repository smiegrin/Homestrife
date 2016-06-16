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
    status = READY;

    //sprites
    standingSprite = sf::Sprite();
    standingSprite.setTexture(ResourceManager::RoseStand);
    standingSprite.setOrigin(195,170);

    jumpingSprite = sf::Sprite();
    jumpingSprite.setTexture(ResourceManager::RoseRun);
    jumpingSprite.setTextureRect(sf::IntRect(40,55,160,230));
    jumpingSprite.setOrigin(100,100);

    runningSprite = AnimatedSprite();
    runningSprite.setAnimation(ResourceManager::RoseRunAnim);
    runningSprite.setOrigin(100,100);

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
        if(cooldown == 3 && (status == ATTACK || status == ATTACK_AIR)) {
            wandSound.play();
            opponent->hitAt(x+direction*75,y,3);
        }
        if(cooldown == 6 && (status == ATTACK || status == ATTACK_AIR)) {
            wandSound.play();
            opponent->hitAt(x+direction*75,y+10,3);
        }
        if(cooldown == 9 && (status == ATTACK || status == ATTACK_AIR)) {
            wandSound.play();
            opponent->hitAt(x+direction*75,y-10,3);
        }
        if(cooldown == 0 && (status == ATTACK || status == SPECIAL || status == DOWN)) status = READY, xVel = 0;
        if(cooldown == 0 && (status == ATTACK_AIR || status == SPECIAL_AIR || status == DOWN_AIR)) status = READY_AIR;
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
    case ATT_REGULAR:
        if(cooldown <= 5 && (status == ATTACK || status == ATTACK_AIR)) cooldown += 5;
        if(status == READY) {
            status = ATTACK;
            cooldown = attackSpeed;
        }
        break;
    case ATT_SPECIAL:
        break;
    }
}

void FighterRose::drawSelf(sf::RenderWindow *window) {
    if(status == DOWN || status == DOWN_AIR) {
        jumpingSprite.setRotation(direction*-30);
        jumpingSprite.setPosition(x,y);
        jumpingSprite.setScale(direction,1);
        window->draw(jumpingSprite);
    }
    else if(status == READY) {
        if(xVel == 0) {
            standingSprite.setPosition(x,y);
            standingSprite.setScale(direction,1);
            window->draw(standingSprite);
        }
        else {
            runningSprite.update(sf::seconds(0.015f));
            runningSprite.setScale(direction,1);
            runningSprite.setPosition(x,y);
            window->draw(runningSprite);
        }
    }
    else if(status == READY_AIR) {
        jumpingSprite.setRotation(0);
        jumpingSprite.setPosition(x,y);
        jumpingSprite.setScale(direction,1);
        window->draw(jumpingSprite);
    }
    else if(status == ATTACK || status == ATTACK_AIR) {
        standingSprite.setPosition(x,y);
        standingSprite.setScale(direction,1);
        window->draw(standingSprite);
    }
    else if(status == KO || status == KO_AIR) {
        standingSprite.setRotation(90*-direction);
        standingSprite.setPosition(x,y);
        window->draw(standingSprite);
    }
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
            if(status == READY || status == ATTACK || status == SPECIAL) status = DOWN;
            else if(status == READY_AIR || status == ATTACK_AIR || status == SPECIAL_AIR) status = DOWN_AIR;
        }
        return true;
    }
    return false;
}
