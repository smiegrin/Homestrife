#ifndef FIGHTER_H
#define FIGHTER_H

#include "GameObject.h"

class Fighter : public GameObject {
public: enum State {READY, READY_AIR, HIGH, HIGH_AIR, LOW, LOW_AIR, DOWN, DOWN_AIR, KO, KO_AIR};
        enum Input {JUMP, GO_LEFT, GO_RIGHT, STOP_LEFT, STOP_RIGHT, ATTACK_LOW, ATTACK_HIGH};
protected:
    sf::Sprite look;
    sf::Texture spriteSheet;
    State status;
    int x;
    int y;
    int width;
    int height;
    int xVel;
    int yVel;
    int direction;
    int anim;
    int health;
    int maxHealth;
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
    int getDefense();
    int getPower();
    int getAttackSpeed();
    int getMoveSpeed();
    bool isAlive();

    virtual int logic() = 0;
    virtual void input(Input) = 0;
    virtual bool hitAt(int,int,int) = 0;
    void setPosition(int,int);
    void setVelocity(int,int);

};

#endif // FIGHTER_H
