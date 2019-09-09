#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>

#include "Character.h"
#include "Cookie.h"
#include "Wall.h"
#include "Pacman.h"
#include "Devil.h"
#include <fstream>
#include <iostream>

class Grid
{
public:
	Grid();
	void insert(sf::RenderWindow & window, sf::Vector2f location, sf::Color color,
		char object_chosen);
	void draw(sf::RenderWindow & window);
	void erase(sf::Vector2f location);
	void clear();
	
	void save_to_file(int width, int hight);
	char insert_to_char_vec(std::vector<std::vector<char>> map, sf::Color color1, char type, int x, int y);
	void write_to_file(std::vector<std::vector<char>> map, int x, int y);

	~Grid();

private:
	std::vector< std::unique_ptr <Character>> m_grid_shape;
	//Board m_board;
};

