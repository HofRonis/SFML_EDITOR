#include "Wall.h"



Wall::Wall(sf::RenderWindow & window, sf::Color color, sf::Vector2f position)
	: Character(window, color, position, '#'){}

void Wall::draw()   // upload the image 
{
	sf::Texture ptr_pic;
	sf::Sprite wall_pic;

	if (!ptr_pic.loadFromFile("wall.png"))
		std::cout << "error cannot open picture" << std::endl;
	wall_pic.setTexture(ptr_pic);
	wall_pic.setPosition(m_position);
	wall_pic.setColor(m_color);
	m_window.draw(wall_pic);
}


Wall::~Wall()
{
}
