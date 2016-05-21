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
    attackSpeed = 40;
    cooldown = 0;
    moveSpeed = 8;
    spriteSheet = ResourceManager::JohnStand;
    look = sf::Sprite();
    look.setTexture(spriteSheet);
    look.setTextureRect(sf::IntRect(80,80,200,200));
    look.setOrigin(100,100);
    status = READY;
}

int FighterJohn::logic() {
    yVel += 1;
    x += xVel;
    y += yVel;
    if (cooldown != 0) {
        if((status == LOW || status == LOW_AIR) && cooldown == 1) opponent->hitAt(x+direction*100, y,10);
        cooldown--;
        if(cooldown == 0 && (status == LOW || status == HIGH)) status = READY;
        if(cooldown == 0 && (status == LOW_AIR || status == HIGH_AIR)) status = READY_AIR;
    }
    if (y >= 350) {
        y = 350;
        yVel = 0;
        if(status == READY_AIR) status = READY;
        if(status == KO_AIR) status = KO;
        if(status == DOWN_AIR) status = DOWN;
        if(status == KO || status == HIGH || status == LOW) {
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
        if(cooldown != 0 || health == 0) break;
        if(status == READY) {
            status = LOW;
            cooldown = attackSpeed;
        }
        else if (status == READY_AIR) {
            status = LOW_AIR;
            cooldown = attackSpeed;
        }
        break;
    case ATTACK_HIGH:
        break;
    }
}

void FighterJohn::drawSelf(sf::RenderWindow *window) {
    //update frame for animation
    look.setPosition(x,y);
    look.setScale(direction,1);
    if((status == LOW || status == LOW_AIR) && cooldown == 1) {
        sf::RectangleShape temp = sf::RectangleShape(sf::Vector2f(5,5));
        temp.setFillColor(sf::Color::Blue);
        temp.setPosition(x+direction*100, y);
        window->draw(temp);
    }
    if(status == KO || status == KO_AIR) look.setRotation(90*-direction);
    window->draw(look);
}

bool FighterJohn::hitAt(int hitX, int hitY, int hitPower = 0) {
    if (hitX >= x-width/2 && hitX <= x+width/2 && hitY >= y-height/2 && hitY <= y+height/2) {
        health -= hitPower - defense;
        if (health <= 0){
            health = 0;
            status = KO_AIR;
            yVel = -hitPower;
            xVel = hitPower*direction*-1.2;
        }
        return true;
    }
    return false;
}
