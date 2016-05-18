#include "Fighter.h"

int Fighter::getXPos() { return x; }

int Fighter::getYPos() { return y; }

int Fighter::getWidth() { return width; }

int Fighter::getHeight() { return height; }

int Fighter::getXVel() { return xVel; }

int Fighter::getYVel() { return yVel; }

int Fighter::getDirection() { return direction; }

int Fighter::getAnim() { return anim; }

int Fighter::getHealthNum() { return health; }

int Fighter::getMaxHealth() { return maxHealth; }

int Fighter::getHealthPercent() { return 100*health/maxHealth; }

int Fighter::getDefense() { return defense; }

int Fighter::getPower() { return power; }

int Fighter::getAttackSpeed() { return attackSpeed; }

int Fighter::getMoveSpeed() { return moveSpeed; }

bool Fighter::hitAt(int hitX, int hitY, int hitPower = 0) {
    if (hitX >= x-width/2 && hitX <= x+width/2 && hitY >= y-height/2 && hitY <= y+height/2) {
        health -= hitPower - defense;
        if (health < 0) health = 0;
        return true;
    }
    return false;
}

void Fighter::setPosition(int xP, int yP) {
    x = xP;
    y = yP;
}

void Fighter::setVelocity(int xV, int yV) {
    xVel = xV;
    yVel = yV;
}
