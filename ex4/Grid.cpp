#include "Grid.h"



Grid::Grid()
{
}

void Grid::erase(sf::Vector2f location) // erase one character
{
	for (int i = 0; i<m_grid_shape.size(); i++)
		if (location == m_grid_shape[i]->get_m_position())
		{
			m_grid_shape.erase(m_grid_shape.begin() + i);
		}
}

void Grid::clear()  // delete all the objects in the vector
{
	int origion_size = m_grid_shape.size();
	for (int i = 0; i < origion_size; i++)
	{
		m_grid_shape.erase(m_grid_shape.begin());
	}
}

// insert an new charcter to the vector
void Grid::insert(sf::RenderWindow & window, sf::Vector2f location, sf::Color color,
	char object_chosen)
{
	bool exist = false;
	// check if the location exist already
	for (int i = 0; i < m_grid_shape.size(); i++)
		if (m_grid_shape[i]->get_m_position().x == location.x
			&& m_grid_shape[i]->get_m_position().y == location.y)
			exist = true;
	if (!exist)
	{
		bool find = false;
		switch (object_chosen) // all the options of object and color
		{
		case 'P':
			for (int i = 0; i < m_grid_shape.size(); i++)
				if (m_grid_shape[i]->get_m_type() == '@')
				{
					m_grid_shape[i].operator= (std::make_unique<Pacman>(window, color, location));
					find = true;
				}	
			if(!find)
				m_grid_shape.push_back(std::make_unique<Pacman>(window, color, location));
			break;

		case 'D':
			m_grid_shape.push_back(std::make_unique<Devil>(window, color, location));
			break;
		case 'C':
			m_grid_shape.push_back(std::make_unique<Cookie>(window, color, location));
			break;
		case 'W':
			m_grid_shape.push_back(std::make_unique<Wall>(window, color, location));
			break;
		}
	}

}



void Grid::draw(sf::RenderWindow & window) // draw all the characters
{
	for(int i=0; i< m_grid_shape.size(); i++)
		m_grid_shape[i]->draw();
}

// save the vector to the text file

void Grid::save_to_file(int width, int hight)
{
	std::vector<std::vector<char>> map;
	map.assign(hight, std::vector<char>(width, ' '));

	int x, y; // need to find real x and y
	int lines, columns;

	for (int i = 0; i < m_grid_shape.size(); i++)
	{
		sf::Color color1 = m_grid_shape[i]->getColor();
		char type = m_grid_shape[i]->get_m_type();
		columns = m_grid_shape[i]->get_m_position().x;
		lines = m_grid_shape[i]->get_m_position().y;

		x = (35 * (columns / 35) - 105) / 35,
			y = (35 * (lines / 35) - 35) / 35; // need to find real x and y

		map[y][x] = insert_to_char_vec(map ,color1, type, x, y);
	}
	if(m_grid_shape.size() != 0)
		write_to_file(map, x, y);

}

// first insert to cector char
char Grid::insert_to_char_vec(std::vector<std::vector<char>> map, sf::Color color1, char type, int x, int y)
{
	char to_insert;

	// red color
	if (color1 == sf::Color::Red && type == '@')
		to_insert = '@';
	if (color1 == sf::Color::Red && type == '%')
		to_insert = '%';
	if (color1 == sf::Color::Red && type == '*')
		to_insert = '*';
	if (color1 == sf::Color::Red && type == '#')
		to_insert = '#';

	//green color
	if (color1 == sf::Color::Green && type == '@')
		to_insert = 'W';
	if (color1 == sf::Color::Green && type == '%')
		to_insert = 'T';
	if (color1 == sf::Color::Green && type == '*')
		to_insert = 'I';
	if (color1 == sf::Color::Green && type == '#')
		to_insert = 'E';

	//blue color
	if (color1 == sf::Color::Blue && type == '@')
		to_insert = 'S';
	if (color1 == sf::Color::Blue && type == '%')
		to_insert = 'G';
	if (color1 == sf::Color::Blue && type == '*')
		to_insert = 'K';
	if (color1 == sf::Color::Blue && type == '#')
		to_insert = 'D';

	return to_insert;
}

// write to the file
void Grid::write_to_file(std::vector<std::vector<char>> map, int x, int y)
{
	std::ofstream levelfile;

	levelfile.open("level.txt");
	if(!levelfile.is_open())
	{
		std::cout << "cannot open file" << std::endl;
	}

	levelfile << map.size()<< " " << map[0].size()  << std::endl;

	for (int i = 0; i < map.size(); i++)
	{
		for (int j = 0; j < map[i].size(); j++)
		{
			levelfile << map[i][j];
		}
		levelfile << std::endl;
	}

}

Grid::~Grid()
{
}