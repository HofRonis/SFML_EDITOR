#include "Button.h"



Button::Button(sf::RenderWindow & window, sf::Vector2f position, Grid & grid)
	: m_window(window),m_position(position), m_grid(grid){}

// abstruct class

Button::~Button()
{
}
