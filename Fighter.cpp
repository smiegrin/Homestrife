#include "Fighter.h"
#include <iostream>

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

int Fighter::getEnergyNum() { return energy; }

int Fighter::getMaxEnergy() { return maxEnergy; }

int Fighter::getEnergyPercent() { return 100*energy/maxEnergy; }

int Fighter::getDefense() { return defense; }

int Fighter::getPower() { return power; }

int Fighter::getAttackSpeed() { return attackSpeed; }

int Fighter::getMoveSpeed() { return moveSpeed; }


bool Fighter::hitAt(int hitX, int hitY, int hitPower, int forceX, int forceY) {
    if (hitX >= x-width/2 && hitX <= x+width/2 && hitY >= y-height/2 && hitY <= y+height/2) {
        xVel += forceX;
        yVel += forceY;
        if(hitPower > 0) {
            health -= hitPower - defense;
            cooldown = hitPower;
            if (yVel < 0) status = DOWN_AIR;
            else if(status == READY || status == ATTACK || status == SPECIAL) status = DOWN;
            else if(status == READY_AIR || status == ATTACK_AIR || status == SPECIAL_AIR) status = DOWN_AIR;
        }
        if (health <= 0){
            health = 0;
            status = KO_AIR;
            yVel += forceY * 1.8;
            xVel += forceX * 1.2;
        }
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

void Fighter::setOpponent(Fighter* opp) {
    opponent = opp;
}
