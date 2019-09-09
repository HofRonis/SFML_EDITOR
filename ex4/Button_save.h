#pragma once
#include "Button.h"
#include <iostream>
class Button_save :public Button
{

public:
	Button_save(sf::RenderWindow & window, sf::Vector2f position, Grid & grid);
	void draw();
	~Button_save();


};

