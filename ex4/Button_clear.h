#pragma once
#include "Button.h"
#include <iostream>
class Button_clear :public Button
{

public:
	Button_clear(sf::RenderWindow & window, sf::Vector2f position, Grid & grid);
	void draw();
	~Button_clear();


};

