#include "Character.h"

// abstruct class

Character::Character(sf::RenderWindow & window,sf::Color color, sf::Vector2f position, char c):
	m_window(window), m_color(color ), m_position (position ), m_type(c){}

sf::Vector2f Character::get_m_position()
{
	return m_position;   // get the location of the object
}

char Character::get_m_type()
{
	return m_type;   // get the type of the character
}

sf::Color Character::getColor() const
{
	return m_color;  // get the color of the character
}


Character::~Character()
{
}
