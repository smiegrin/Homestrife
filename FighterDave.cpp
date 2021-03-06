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
    energy = 50;
    maxEnergy = 100;
    power = 2;
    defense = 2;
    attackSpeed = 5;
    cooldown = 0;
    moveSpeed = 8;
    primaryColor = sf::Color(183,13,14);
    secondaryColor = sf::Color(255,33,6);
    status = READY;

    standingSprite = sf::Sprite();
    standingSprite.setTexture(ResourceManager::DaveStand);
    standingSprite.setOrigin(260,220);

    jumpingSprite = sf::Sprite();
    jumpingSprite.setTexture(ResourceManager::DaveJump);
    jumpingSprite.setTextureRect(sf::IntRect(75,145,250,250));
    jumpingSprite.setOrigin(125,125);

    runningSprite = AnimatedSprite(sf::seconds(.06f));
    runningSprite.setAnimation(ResourceManager::DaveRunAnim);
    runningSprite.setOrigin(100,100);

    attackingSprite = AnimatedSprite(sf::seconds(.045f));
    attackingSprite.setAnimation(ResourceManager::DaveAttAnim);
    attackingSprite.setOrigin(200,125);

    //initialize sounds
    whoosh.setBuffer(ResourceManager::LightWhoosh);
    whoosh.setLoop(false);
}

int FighterDave::logic() {
    yVel += 1;
    x += xVel;
    y += yVel;
    if (cooldown != 0) {
        cooldown--;
        if(cooldown == 1 && (status == ATTACK || status == ATTACK_AIR)) {
            whoosh.play();
            opponent->hitAt(x+direction*100,y,5,direction*5,-1);
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
        if(status == ATTACK_AIR) status = ATTACK;
        if(status == ATTACK && xVel != 0) xVel -= direction;
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
        if(cooldown != 0) break;
        if(status == READY) {
            status = ATTACK;
            cooldown = attackSpeed;
            xVel += direction*4;
        }
        else if (status == READY_AIR) {
            status = ATTACK_AIR;
            cooldown = attackSpeed;
        }
        break;
    case ATT_SPECIAL:
        break;
    }
}

void FighterDave::drawSelf(sf::RenderWindow *window) {
    if(status == READY) {
        if (xVel != 0) {
            runningSprite.update(sf::seconds(0.015f));
            runningSprite.setScale(direction,1);
            runningSprite.setPosition(x,y);
            window->draw(runningSprite);
        }
        else {
            standingSprite.setScale(direction,1);
            standingSprite.setPosition(x,y);
            standingSprite.setRotation(0);
            window->draw(standingSprite);
        }
    }
    if(status == READY_AIR) {
        if (yVel < 0) {
            anim = (anim > 3) ? 0 : anim+1;
            if (anim == 0) jumpingSprite.rotate(direction*90);
            jumpingSprite.setTextureRect(sf::IntRect(75,145,250,250));
        }
        else {
            anim = 0;
            jumpingSprite.setRotation(0);
            jumpingSprite.setTextureRect(sf::IntRect(345,430,250,270));
        }
        jumpingSprite.setScale(direction,1);
        jumpingSprite.setPosition(x,y);
        window->draw(jumpingSprite);
    }
    if(status == ATTACK || status == ATTACK_AIR) {
        attackingSprite.update(sf::seconds(.015f));
        attackingSprite.setScale(direction,1);
        attackingSprite.setPosition(x,y);
        window->draw(attackingSprite);
    }
    if(status == KO || status == KO_AIR) {
        standingSprite.setRotation(90*-direction);
        standingSprite.setPosition(x,y);
        window->draw(standingSprite);
    }
    if(status == DOWN || status == DOWN_AIR) {
        standingSprite.setRotation(30*-direction);
        standingSprite.setPosition(x,y);
        window->draw(standingSprite);
    }
}

