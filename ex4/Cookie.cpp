#include "Cookie.h"



Cookie::Cookie(sf::RenderWindow & window, sf::Color color, sf::Vector2f position)
	: Character(window, color, position, '*'){}

void Cookie::draw()	// upload the image 
{
	sf::Texture ptr_pic;
	sf::Sprite cookie_pic;

	if (!ptr_pic.loadFromFile("cookie.png"))
		std::cout << "error cannot open picture" << std::endl;

	cookie_pic.setTexture(ptr_pic);
	cookie_pic.setPosition(m_position);
	cookie_pic.setColor(m_color);
	m_window.draw(cookie_pic);
}


Cookie::~Cookie()
{
}
