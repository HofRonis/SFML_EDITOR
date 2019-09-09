#pragma once
#include <SFML/Graphics.hpp>
#include "Button.h"
#include <iostream>

class Button_color: public Button
{
public:
	Button_color(sf::RenderWindow & window, sf::Vector2f position, 
		sf::Color color, Grid & grid);
	void draw();
	~Button_color();
private:
	sf::Color m_color;
};

