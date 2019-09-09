#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>

#include "Button.h"
#include "Button_color.h"
#include "Button_clear.h"
#include "Button_save.h"
#include "Eraser.h"

#include "Character.h"
#include "Cookie.h"
#include "Wall.h"
#include "Pacman.h"
#include "Devil.h"




class Menu
{
	public:
	Menu();
	void draw(sf::RenderWindow & window, Grid & grid);

	~Menu();


private:
	std::vector< std::unique_ptr <Character>> m_menu_shape;
	std::vector< std::unique_ptr <Button>> m_button;
	//std::vector <Button*>  m_button;
};

