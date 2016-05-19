#include "FlashText.h"
#include "ResourceManager.h"

FlashText::FlashText(std::string newText, sf::Color pColor, sf::Color sColor) {
    pText = sf::Text();
    pText.setString(newText);
    pText.setCharacterSize(20);
    pText.setColor(pColor);
    pText.setPosition(0,0);
    sText = sf::Text();
    sText.setString(newText);
    sText.setCharacterSize(20);
    sText.setColor(sColor);
    sText.setPosition(2,2);
    primaryColor = pColor;
    secondaryColor = sColor;
    x = 0;
    y = 0;
    offset = 2;
    flashSpeed = 5;
    anim = flashSpeed;
}

int FlashText::getX() { return x; }

int FlashText::getY() { return y; }

int FlashText::getOffset() { return offset; }

int FlashText::getFlashSpeed() { return flashSpeed; }

sf::Color FlashText::getPrimaryColor() { return primaryColor; }

sf::Color FlashText::getSecondaryColor() { return secondaryColor; }

std::string FlashText::getString() { return pText.getString(); }


void FlashText::setPosition(int xPos, int yPos) {
    x = xPos;
    y = yPos;
    pText.setPosition(x,y);
    sText.setPosition(x+offset,y+offset);
}

void FlashText::setOffset(int newOffset) { offset = newOffset; }

void FlashText::setFlashSpeed(int newSpeed) { flashSpeed = newSpeed; }

void FlashText::setString(std::string newString) {
    pText.setString(newString);
    sText.setString(newString);
}

void FlashText::setPrimaryColor(sf::Color newColor) { primaryColor = newColor; }

void FlashText::setSecondaryColor(sf::Color newColor) { secondaryColor = newColor; }

void FlashText::setFont(sf::Font* font) {
    pText.setFont(*font);
    sText.setFont(*font);
}

void FlashText::setSize(int newSize) {
    pText.setCharacterSize(newSize);
    sText.setCharacterSize(newSize);
}


void FlashText::drawSelf(sf::RenderWindow* window) {
    anim--;
    if (anim == 0) {
        if (pText.getColor() == primaryColor) pText.setColor(secondaryColor), sText.setColor(primaryColor);
        else pText.setColor(primaryColor), sText.setColor(secondaryColor);
        anim = flashSpeed;
    }
    window->draw(sText);
    window->draw(pText);
}
