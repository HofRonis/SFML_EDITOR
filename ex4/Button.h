#pragma once
#include <SFML/Graphics.hpp>
#include "Grid.h"

//#include <iostream>
class Button
{
public:
	Button(sf::RenderWindow & window, sf::Vector2f position, Grid & grid);
	virtual void draw() = 0;
	
	~Button();

protected:
	sf::Vector2f m_position;
	sf::RenderWindow & m_window;
	Grid & m_grid;
};

