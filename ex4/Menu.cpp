#include "Menu.h"



Menu::Menu()
{
}

void Menu::draw(sf::RenderWindow & window, Grid & grid)
{
	// make all the characters using unique ptr vector and polimorfizem
	m_menu_shape.push_back(std::make_unique<Pacman>
		(window, sf::Color::Yellow, sf::Vector2f(3,20)));
	m_menu_shape.push_back(std::make_unique<Devil>
		(window, sf::Color::Yellow, sf::Vector2f(3,50)));
	m_menu_shape.push_back(std::make_unique<Cookie>
		(window, sf::Color::Yellow, sf::Vector2f(3,80)));
	m_menu_shape.push_back(std::make_unique<Wall>
		(window, sf::Color::Yellow, sf::Vector2f(3,110)));

	for (int i = 0; i < 4; i++) // draw
		m_menu_shape[i]->draw();
	
	m_button.push_back(std::make_unique<Button_color>
		(window, sf::Vector2f(3, 160), sf::Color::Red, grid));
	m_button.push_back(std::make_unique<Button_color>
		(window, sf::Vector2f(3, 190), sf::Color::Green, grid));
	m_button.push_back(std::make_unique<Button_color>
		(window, sf::Vector2f(3, 220), sf::Color::Blue, grid));
	m_button.push_back(std::make_unique<Eraser>
		(window, sf::Vector2f(3, 270), grid));
	m_button.push_back(std::make_unique<Button_clear>
		(window, sf::Vector2f(3, 300), grid));
	m_button.push_back(std::make_unique<Button_save>
		(window, sf::Vector2f(3, 330), grid));
	

	for (int i = 0; i < 6; i++)  // draw
		m_button[i]->draw();
}


Menu::~Menu()
{
}
