#pragma once
#include "Character.h"

class Wall:public Character
{
public:
	Wall(sf::RenderWindow & window, sf::Color color, sf::Vector2f position);
	void draw();
	~Wall();

private:
	sf::Texture m_picture;
	sf::Sprite m_picture_image;

};

