#include "Controller.h"

Controller::Controller()
{
}
// make rectangles for the buttons
void Controller::make_rectangles_array(sf::RectangleShape *rect_array, int size)
{
	for (int i = 0; i < size; i++)
	{
		rect_array[i].setSize(sf::Vector2f(30.f, 30.f));
		rect_array[i].setFillColor(sf::Color::Transparent);
		rect_array[i].setOutlineThickness(2.0f);
		rect_array[i].setOutlineColor(sf::Color::Black);
		if (i<4)  // for objects locations
			rect_array[i].setPosition(3, 20 + (30 * i));
		else  // for colors locations
			rect_array[i].setPosition(3, 40 + (30 * i));
	}
}
// get from user the size og the grid
void Controller::insert_width_hight(int &width, int &hight)
{
	while (width < 5 || width>25)
	{
		std::cout << "enter num of column size (between 5 to 25)" << std::endl;
		std::cin >> width;
	}
	while (hight < 5 || hight>16)
	{
		std::cout << "enter num of row size (between 5 to 16)" << std::endl;
		std::cin >> hight;
	}
}
// load the vector from the map
void Controller::make_character(std::ifstream &levelfile, int hight, int width)
{
	char chosen;
	
	for (int i = 0; i < hight; i++)
	{
		for (int j = 0; j < width; j++)
		{
			levelfile.get(chosen);
			if (chosen != ' ' && chosen != '\n')
				insert_to_vec(chosen, j, i);
		}
		levelfile.get(chosen);
	}
	

	
}
// insert new character to the vector
void Controller::insert_to_vec(char chosen, int x, int y)
{
	char type;
	sf::Color color;
	
	// red color
	if (chosen == '@')
	{
		color = sf::Color::Red;
		type = 'P';
	}
	if (chosen == '%')
	{
		color = sf::Color::Red;
		type = 'D';
	}
	if (chosen == '*')
	{
		color = sf::Color::Red;
		type = 'C';
	}
	if (chosen == '#')
	{
		color = sf::Color::Red;
		type = 'W';
	}
	
	//green color
	if (chosen == 'W')
	{
		color = sf::Color::Green;
		type = 'P';
	}
	if (chosen == 'T')
	{
		color = sf::Color::Green;
		type = 'D';
	}
	if (chosen == 'I')
	{
		color = sf::Color::Green;
		type = 'C';
	}
	if (chosen == 'E')
	{
		color = sf::Color::Green;
		type = 'W';
	}
	
	//blue color
	if (chosen == 'S')
	{
		color = sf::Color::Blue;
		type = 'P';
	}
	if (chosen == 'G')
	{
		color = sf::Color::Blue;
		type = 'D';
	}
	if (chosen == 'K')
	{
		color = sf::Color::Blue;
		type = 'C';
	}
	if (chosen == 'D')
	{
		color = sf::Color::Blue;
		type = 'W';
	}
	sf::Vector2f fixed_location((105 + x * 35) + 4, (35 + y * 35) + 4);
	
	// insert to vector
	m_grid.insert(m_window, fixed_location, color, type);
}
// main game function
void Controller::run()
{      // window size:
	m_window.create(sf::VideoMode::VideoMode(1000, 600), "Stage Editor");

	sf::RectangleShape rect_array[7]; // most of menu buttons
	make_rectangles_array(rect_array, 7);

	sf::RectangleShape rect_edit;     // make new grid button
	rect_edit.setSize(sf::Vector2f(30.f, 30.f));
	rect_edit.setFillColor(sf::Color::Transparent);
	rect_edit.setOutlineThickness(2.0f);
	rect_edit.setOutlineColor(sf::Color::Black);
	rect_edit.setPosition(3, 270 );

	sf::RectangleShape rect_save;   // save button
	rect_save.setSize(sf::Vector2f(30.f, 30.f));
	rect_save.setFillColor(sf::Color::Transparent);
	rect_save.setOutlineThickness(2.0f);
	rect_save.setOutlineColor(sf::Color::Black);
	rect_save.setPosition(3, 330);
	
	bool grid_time = false;

	int width=0, hight=0;
	
	std::ifstream levelfile;

	levelfile.open("level.txt");
	if (levelfile.is_open())
	{
		char c;
		levelfile >> hight >> width;
		levelfile.get(c); // for the first \n
		make_character(levelfile, hight, width);
	}
	else
		insert_width_hight(width, hight);

	sf::Texture ppicture;
	sf::Sprite grid;

	if (!ppicture.loadFromFile("grid.png"))
		std::cout << "error cannot open picture" << std::endl;
	grid.setTexture(ppicture);

	
	while (m_window.isOpen()) // main loop
	{
		m_window.clear();
		m_menu.draw(m_window, m_grid);

		for (int i = 3; i<width + 3; i++)   // print the grid
			for (int j = 1; j < hight + 1; j++)
			{
				grid.setPosition(i * 35, j * 35);
				m_window.draw(grid);
			}
		for (int i = 0; i<7; i++)
			m_window.draw(rect_array[i]);

		m_window.draw(rect_edit);

		rect_save.setOutlineColor(sf::Color::Black);
		m_window.draw(rect_save);

		m_grid.draw(m_window); // print vector of characters

		sf::Event Event;
		while (m_window.pollEvent(Event))
		{

			switch (Event.type)
			{
			case sf::Event::MouseButtonPressed:
				if (Event.mouseButton.button == sf::Mouse::Left)
				{
					int x = Event.mouseButton.x,
						y = Event.mouseButton.y;
					push_on_rec(rect_array, x, y);
					bool erase_pressed = false;
					if (push_on_erase(rect_edit, x, y))
					{
						erase_pressed = true;
						make_rect_array_black(rect_array);
					}
					for (int i = 0; i < 7; i++)
						if (rect_array[i].getOutlineColor() == (sf::Color::Blue))
							rect_edit.setOutlineColor(sf::Color::Black);

					if (x > 105 && y > 35 && x < 35 * (width + 3) && y < 35 * (hight + 1)) // if in grid limit
					{
						if (check_time_for_grid(rect_array)) // check if two buttons were pressed
						{										// color and charcter
							rect_edit.setOutlineColor(sf::Color::Black);// black the erase

							char character_chosen = which_character(rect_array);
							sf::Color color_chosen = which_color(rect_array);
							sf::Vector2f fixed_location(35 * (x / 35) + 4, 35 * (y / 35) + 4);

							m_grid.insert(m_window, fixed_location, color_chosen, character_chosen);
						}
						else//if erase pressed
						{
							sf::Vector2f fixed_location(35 * (x / 35) + 4, 35 * (y / 35) + 4);
							m_grid.erase(fixed_location);
						}
						
					}	
					//if clear pressed
					if (3 < x && x < 33 & 300<y && y < 330)
					{
						for (int i = 0; i < 7; i++)
							if (rect_array[i].getOutlineColor() == (sf::Color::Blue))
								rect_array[i].setOutlineColor(sf::Color::Black);
						m_grid.clear();
						width = 0, hight = 0;
						insert_width_hight(width, hight);
					}
					if (3 < x && x < 33 & 330 < y && y < 360) // if save pressed
					{
						for (int i = 0; i < 7; i++)
							if (rect_array[i].getOutlineColor() == (sf::Color::Blue))
								rect_array[i].setOutlineColor(sf::Color::Black);
						rect_save.setOutlineColor(sf::Color::Blue);
						m_window.draw(rect_save);
						m_grid.save_to_file(width, hight);
					}
					
				}

			}	
			if (Event.type == sf::Event::Closed)
				m_window.close();
		}	
		m_window.display();
	}
}

// make buttons black
void Controller::make_rect_array_black(sf::RectangleShape *rect_array)
{
	for (int i = 0; i < 7; i++)
		rect_array[i].setOutlineColor(sf::Color::Black);
}
// erase button pressed
bool Controller::push_on_erase(sf::RectangleShape &rect_edit, int x, int y)
{
	if (x > 3 && x < 33 && y>270 && y < 300)
	{
		
		if (rect_edit.getOutlineColor() == (sf::Color::Black))
			rect_edit.setOutlineColor(sf::Color::Blue);
	
		else
			rect_edit.setOutlineColor(sf::Color::Black);
		return true;
	}
	return false;
}
// check type of character
char Controller::which_character(sf::RectangleShape *rect_array)
{
	char chosen;
	int i;
	for ( i = 0; i < 4; i++)
		if (rect_array[i].getOutlineColor() == (sf::Color::Blue))
			break;
	switch (i)
	{
	case 0:
		chosen= 'P';
		break;
	case 1:
		chosen = 'D';
		break;
	case 2:
		chosen = 'C';
		break;
	case 3:
		chosen = 'W';
		break;
	}
	return chosen;
}
// get the color of a charcter
sf::Color Controller::which_color(sf::RectangleShape *rect_array)
{
	sf::Color chosen;
	int i;
	for (i = 4; i < 7; i++)
		if (rect_array[i].getOutlineColor() == (sf::Color::Blue))
			break;
	switch (i)
	{
	case 4:
		chosen = sf::Color::Red;
		break;
	case 5:
		chosen = sf::Color::Green;
		break;
	case 6:
		chosen = sf::Color::Blue;
		break;
	}
	return chosen;
}
// if pushed a button
void Controller::push_on_rec(sf::RectangleShape *rect_array, int x, int y)
{
	int chosen_i = -1;
	if (x > 3 && x < 33 && y>20 && y < 50)
		chosen_i = 0;
	if (x > 3 && x < 33 && y>50 && y < 80)
		chosen_i = 1;
	if (x > 3 && x < 33 && y>80 && y < 110)
		chosen_i = 2;
	if (x > 3 && x < 33 && y>110 && y < 140)
		chosen_i = 3;
	if (x > 3 && x < 33 && y>160 && y < 190)
		chosen_i = 4;
	if (x > 3 && x < 33 && y>190 && y < 220)
		chosen_i = 5;
	if (x > 3 && x < 33 && y>220 && y < 250)
		chosen_i = 6;

	if (chosen_i != -1)
	{
		if (rect_array[chosen_i].getOutlineColor() == (sf::Color::Black))
			rect_array[chosen_i].setOutlineColor(sf::Color::Blue);
		else
			rect_array[chosen_i].setOutlineColor(sf::Color::Black);

		if (0 <= chosen_i && chosen_i < 4)
		{
			for (int i = 0; i < 4; i++)
				if (i != chosen_i) // make other buttons black
					rect_array[i].setOutlineColor(sf::Color::Black);
		}
		else
		{
			for (int i = 4; i < 7; i++)
				if (i != chosen_i) // make other buttons black
					rect_array[i].setOutlineColor(sf::Color::Black);
		}
	}
}
// check if both color and charcter were pressed: then we can press on grid
bool Controller::check_time_for_grid(sf::RectangleShape *rect_array)
{
	int object_counter = 0,
		color_counter = 0;
	for (int i = 0; i < 4; i++)
		if (rect_array[i].getOutlineColor() == (sf::Color::Blue))
			object_counter++;
	for (int i = 4; i < 7; i++)
		if (rect_array[i].getOutlineColor() == (sf::Color::Blue))
			color_counter++;
	if (color_counter == 1 && object_counter == 1)
		return true;
	else
		return false;
}


Controller::~Controller()
{
}
