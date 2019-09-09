#include "Button_color.h"



Button_color::Button_color(sf::RenderWindow & window, sf::Vector2f position,
	sf::Color color, Grid & grid)
	: Button(window, position, grid) , m_color(color) {}


void Button_color::draw() // upload the image to the menu
{
	sf::Texture ptr_pic;
	sf::Sprite color_pic;

	if (!ptr_pic.loadFromFile("color.png"))
		std::cout << "error cannot open picture" << std::endl;
	color_pic.setTexture(ptr_pic);
	color_pic.setPosition(m_position);
	color_pic.setColor(m_color);
	m_window.draw(color_pic);
}

Button_color::~Button_color()
{
}
