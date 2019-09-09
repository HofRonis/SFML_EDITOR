#include "Button_save.h"



Button_save::Button_save(sf::RenderWindow & window, sf::Vector2f position, Grid & grid)
	: Button(window, position, grid) {}

void Button_save::draw() // upload the image to the menu
{
	sf::Texture ptr_pic;
	sf::Sprite save_pic;

	if (!ptr_pic.loadFromFile("save.png"))
		std::cout << "error cannot open picture" << std::endl;
	save_pic.setTexture(ptr_pic);
	save_pic.setPosition(m_position);
	m_window.draw(save_pic);
}



Button_save::~Button_save()
{
}
