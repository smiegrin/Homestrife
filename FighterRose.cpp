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
    primaryColor = sf::Color(255,136,0);
    secondaryColor = sf::Color(181,54,218);
    status = READY;

    //sprites
    standingSprite = sf::Sprite();
    standingSprite.setTexture(ResourceManager::RoseStand);
    standingSprite.setOrigin(195,170);

    jumpingSprite = sf::Sprite();
    jumpingSprite.setTexture(ResourceManager::RoseRun);
    jumpingSprite.setTextureRect(sf::IntRect(40,55,160,230));
    jumpingSprite.setOrigin(100,100);

    runningSprite = AnimatedSprite(sf::seconds(.06f));
    runningSprite.setAnimation(ResourceManager::RoseRunAnim);
    runningSprite.setOrigin(100,100);

    attPowSprite = AnimatedSprite(sf::seconds(.045f));
    attPowSprite.setAnimation(ResourceManager::RoseAttPowAnim);
    attPowSprite.setOrigin(60,110);

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
        //check for regular attack
        if(cooldown == 3 && (status == ATTACK || status == ATTACK_AIR)) {
            wandSound.play();
            if (opponent->hitAt(x+direction*75,y,3,rand()%7-3,rand()%7-3)) energy += 3;
            if (getHealthPercent() < 25 && opponent->hitAt(x+direction*75,y,5,rand()%7-3,rand()%7-3)) {
                energy += 5;
                //zap sound goes here
            }
        }
        if(cooldown == 6 && (status == ATTACK || status == ATTACK_AIR)) {
            wandSound.play();
            if (opponent->hitAt(x+direction*75,y+10,3,rand()%7-3,rand()%7-3)) energy += 3;
            if (getHealthPercent() < 25 && opponent->hitAt(x+direction*75,y+10,5,rand()%7-3,rand()%7-3)) {
                energy += 5;
                //zap sound goes here
            }
        }
        if(cooldown == 9 && (status == ATTACK || status == ATTACK_AIR)) {
            wandSound.play();
            if (opponent->hitAt(x+direction*75,y-10,3,rand()%7-3,rand()%7-3)) energy += 3;
            if (getHealthPercent() < 25 && opponent->hitAt(x+direction*75,y-10,5,rand()%7-3,rand()%7-3)) {
                energy += 5;
                //zap sound goes here
            }
        }
        //check for special attack
        if(cooldown == 15 && (status == SPECIAL || status == SPECIAL_AIR)) {
            //play awesome zap sound
            bool success = false;
            for (int i = x; i > 0 && i < 800 && !success; i += direction) if (opponent->hitAt(i,y,20,direction*20,-3)) success = true;
            energy = (success) ? 15 : 0;
        }
        if(cooldown == 0 && (status == ATTACK || status == SPECIAL || status == DOWN)) status = READY, xVel = 0;
        if(cooldown == 0 && (status == ATTACK_AIR || status == SPECIAL_AIR || status == DOWN_AIR)) status = READY_AIR;
    }
    if (y >= 350) {
        y = 350;
        yVel = 0;
        if(status == READY_AIR) status = READY;
        if(status == SPECIAL_AIR) status = SPECIAL;
        if(status == KO_AIR) status = KO;
        if(status == DOWN_AIR) status = DOWN;
        if(status == KO || status == DOWN) {
            if(xVel > 0) xVel -= 1;
            else if (xVel < 0) xVel += 1;
        }
    }
    if (getHealthPercent() < 10) energy += 1;
    if (energy > maxEnergy) energy = maxEnergy;
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
        else if(status == READY_AIR) {
            status = ATTACK_AIR;
            cooldown = attackSpeed;
        }
        break;
    case ATT_SPECIAL:
        if(status == READY && getEnergyPercent() == 100) {
            status = SPECIAL;
            cooldown = 60;
        }
        if(status == READY_AIR && getEnergyPercent() == 100) {
            status = SPECIAL_AIR;
            cooldown = 60;
        }
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
    else if(status == SPECIAL || status == SPECIAL_AIR) {
        standingSprite.setColor((cooldown % 10 < 5) ? sf::Color::White : sf::Color(255,255,255,128));
        standingSprite.setPosition(x,y);
        standingSprite.setScale(direction,1);
        window->draw(standingSprite);
        //lightning effect
        if(cooldown < 15) {
            sf::RectangleShape temp = sf::RectangleShape(sf::Vector2f(800*direction, 5));
            temp.setPosition(x,y-2);
            temp.setFillColor(sf::Color(255,128,0,255));
            window ->draw(temp);
        }
    }
    else if(status == ATTACK || status == ATTACK_AIR) {
        attPowSprite.setPosition(x,y);
        attPowSprite.setScale(direction,1);
        attPowSprite.update(sf::seconds(.015f));
        window->draw(attPowSprite);
    }
    else if(status == KO || status == KO_AIR) {
        standingSprite.setRotation(90*-direction);
        standingSprite.setPosition(x,y);
        window->draw(standingSprite);
    }
}
