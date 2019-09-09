#include "Button_clear.h"



Button_clear::Button_clear(sf::RenderWindow & window, sf::Vector2f position, Grid & grid)
	: Button(window, position, grid) {}

void Button_clear::draw() // upload the image to the menu
{
	sf::Texture ptr_pic;
	sf::Sprite clear_pic;

	if (!ptr_pic.loadFromFile("clear.png"))
		std::cout << "error cannot open picture" << std::endl;
	clear_pic.setTexture(ptr_pic);
	clear_pic.setPosition(m_position);
	m_window.draw(clear_pic);
}



Button_clear::~Button_clear()
{
}
