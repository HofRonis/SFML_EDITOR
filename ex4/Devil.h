#pragma once
#include "Character.h"
class Devil:public Character
{
public:
	Devil(sf::RenderWindow & window, sf::Color color, sf::Vector2f position);
	void draw();

	~Devil();

private:
	sf::Texture m_picture;
	sf::Sprite m_picture_image;
};

