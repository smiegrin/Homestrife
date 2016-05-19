#ifndef FLASHTEXT_H
#define FLASHTEXT_H

#include "DisplayObject.h"
#include <SFML/Graphics.hpp>
#include <string>

class FlashText : public DisplayObject {
private:
    sf::Color primaryColor;
    sf::Color secondaryColor;
    sf::Text pText;
    sf::Text sText;
    int offset;
    int flashSpeed;
    int anim;
    int x;
    int y;
public:
    FlashText(std::string, sf::Color, sf::Color);
    int getX();
    int getY();
    int getOffset();
    int getFlashSpeed();
    sf::Color getPrimaryColor();
    sf::Color getSecondaryColor();
    std::string getString();

    void setPosition(int,int);
    void setOffset(int);
    void setFlashSpeed(int);
    void setString(std::string);
    void setPrimaryColor(sf::Color);
    void setSecondaryColor(sf::Color);
    void setFont(sf::Font*);
    void setSize(int);

    virtual void drawSelf(sf::RenderWindow*);
};

#endif // FLASHTEXT_H
