#pragma once
#include <SFML/Graphics.hpp>

#include"Grid.h"
#include "Menu.h"
#include "iostream"
#include <fstream>

class Controller
{
public:
	Controller();
	void run();
	void make_rectangles_array(sf::RectangleShape *rect_array, int size);
	void push_on_rec(sf::RectangleShape *rect_array, int x, int y);
	bool check_time_for_grid(sf::RectangleShape *rect_array);
	char which_character(sf::RectangleShape *rect_array);
	bool push_on_erase(sf::RectangleShape &rect_edit, int x, int y);
	void make_rect_array_black(sf::RectangleShape *rect_array);
	sf::Color which_color(sf::RectangleShape *rect_array);
	void make_character(std::ifstream &levelfile, int hight, int width);
	void insert_to_vec(char chosen, int x, int y);

	void insert_width_hight(int &width, int &hight);
	~Controller();

	

private:
	Menu m_menu;
	Grid m_grid;
	sf::RenderWindow m_window;

};

