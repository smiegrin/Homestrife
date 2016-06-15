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

int Fighter::getEnergyNum() { return energy; }

int Fighter::getMaxEnergy() { return maxEnergy; }

int Fighter::getEnergyPercent() { return 100*energy/maxEnergy; }

int Fighter::getDefense() { return defense; }

int Fighter::getPower() { return power; }

int Fighter::getAttackSpeed() { return attackSpeed; }

int Fighter::getMoveSpeed() { return moveSpeed; }


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
