#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>
#include <string>
#include "DisplayObject.h"

class Button : public DisplayObject {
	int x, y, width, height;
	sf::RectangleShape shape;
	sf::Text label;
public:
	Button();
	Button(int,int,int,int,sf::Color, std::string);

	sf::Shape* getShape();

	bool pointOnBox(int,int);

	//inherited from DisplayObject
	virtual void drawSelf(sf::RenderWindow* window);
};



#endif
