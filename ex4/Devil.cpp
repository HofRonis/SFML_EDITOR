#include "Devil.h"



Devil::Devil(sf::RenderWindow & window, sf::Color color, sf::Vector2f position)
	: Character(window, color, position, '%')
{
}

void Devil::draw()   // upload the image 
{
	sf::Texture ptr_pic;
	sf::Sprite devil_pic;

	if (!ptr_pic.loadFromFile("devil.png"))
		std::cout << "error cannot open picture" << std::endl;
	devil_pic.setTexture(ptr_pic);
	devil_pic.setPosition(m_position);
	devil_pic.setColor(m_color);
	m_window.draw(devil_pic);
}

Devil::~Devil()
{
}
