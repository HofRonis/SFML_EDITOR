#include "Eraser.h"



Eraser::Eraser(sf::RenderWindow & window, sf::Vector2f position, Grid & grid)
	: Button(window, position, grid){}

void Eraser::draw() // upload the image 
{
	sf::Texture ptr_pic;
	sf::Sprite eraser_pic;

	if (!ptr_pic.loadFromFile("eraser.png"))
		std::cout << "error cannot open picture" << std::endl;
	eraser_pic.setTexture(ptr_pic);
	eraser_pic.setPosition(m_position);
	m_window.draw(eraser_pic);
}

void Eraser::delete_character(sf::Vector2f location)
{
	m_grid.erase(location); // delete a character from the vector
}


Eraser::~Eraser()
{
}
