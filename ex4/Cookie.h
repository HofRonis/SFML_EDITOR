#pragma once
#include "Character.h"

class Cookie:public Character
{
public:
	Cookie(sf::RenderWindow & window, sf::Color color, sf::Vector2f position);
	void draw();
	~Cookie();

private:
	sf::Texture m_picture;
	sf::Sprite m_picture_image;
};

