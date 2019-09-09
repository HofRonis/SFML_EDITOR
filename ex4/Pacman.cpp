#include "Pacman.h"



Pacman::Pacman(sf::RenderWindow & window, sf::Color color, sf::Vector2f position)
	: Character(window, color, position, '@')
{}

void Pacman::draw()   // upload the image 
{
	sf::Texture ptr_pic;
	sf::Sprite pacman_pic;

	if (!ptr_pic.loadFromFile("pacman.png"))
		std::cout << "error cannot open picture" << std::endl;
	pacman_pic.setTexture(ptr_pic);
	pacman_pic.setPosition(m_position);
	pacman_pic.setColor(m_color);
	m_window.draw(pacman_pic);
}


Pacman::~Pacman()
{
}
