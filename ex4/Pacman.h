#pragma once
#include "Character.h"


class Pacman:public Character
{
public:
	Pacman(sf::RenderWindow & window, sf::Color color, sf::Vector2f position);
	void draw();
	

	~Pacman();

};

