#pragma once
#include "Button.h"
#include <iostream>
class Eraser:public Button
{

public:
	Eraser(sf::RenderWindow & window, sf::Vector2f position, Grid & grid);
	void draw();
	void delete_character(sf::Vector2f location);
	~Eraser();

	
};

