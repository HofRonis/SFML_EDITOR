#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Character
{
public:
	Character(sf::RenderWindow & window,sf::Color color, sf::Vector2f position, char c);
	virtual void draw() = 0;
	sf::Vector2f get_m_position();
	char get_m_type();
	sf::Color getColor() const;

	~Character();

protected:	
	sf::Color m_color;
	sf::Vector2f m_position;
	char m_type;
	sf::RenderWindow & m_window;
};

