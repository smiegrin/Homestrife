#ifndef FIGHTER_H
#define FIGHTER_H

#include "GameObject.h"

class Fighter : public GameObject {
public: enum State {READY, READY_AIR, SPECIAL, SPECIAL_AIR, ATTACK, ATTACK_AIR, DOWN, DOWN_AIR, KO, KO_AIR};
        enum Input {JUMP, GO_LEFT, GO_RIGHT, STOP_LEFT, STOP_RIGHT, ATT_REGULAR, ATT_SPECIAL};
protected:
    sf::Sprite look;
    sf::Texture spriteSheet;
    State status;
    Fighter* opponent;
    int x;
    int y;
    int width;
    int height;
    int xVel = 0;
    int yVel = 0;
    int direction;
    int anim;
    int health;
    int maxHealth;
    int energy;
    int maxEnergy;
    int defense;
    int power;
    int attackSpeed;
    int cooldown;
    int moveSpeed;
public:
    int getXPos();
    int getYPos();
    int getWidth();
    int getHeight();
    int getXVel();
    int getYVel();
    int getDirection();
    int getAnim();
    int getHealthNum();
    int getMaxHealth();
    int getHealthPercent();
    int getEnergyNum();
    int getMaxEnergy();
    int getEnergyPercent();
    int getDefense();
    int getPower();
    int getAttackSpeed();
    int getMoveSpeed();
    bool isAlive();

    virtual int logic() = 0;
    virtual void input(Input) = 0;
    virtual bool hitAt(int,int,int,int,int);
    void setPosition(int,int);
    void setVelocity(int,int);
    void setOpponent(Fighter*);

};

#endif // FIGHTER_H
