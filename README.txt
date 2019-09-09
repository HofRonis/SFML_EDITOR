================================================================================

SFML Editor, C++
========
by: Hof Ronis 

================================================================================
Description
===========
I developed a stage editor to Pacman game using "SFML". 

Important instructions:

The user need to choose(to press) two buttons before he can put a character on the grid:
choose color- red/blue/green,
choose charcter- pacman/enemy(ghost)/wall/food(bug),
that put your choice on the grid.

================================================================================
Included files
==============

1)main.cpp - run the main object function.
2)controller.cpp- make all the game managment.
3)menu.cpp - print the menu.
4)grid.cpp - print the grid and manage it using a vector of characters.
5)character.cpp- abstruct,  heritance to 6)wall.cpp 7)pacman.cpp 8)devil.cpp 9)cookie.cpp.
10)button.cpp- abstruct,  heritance to 11)button_save.cpp 12)button_color.cpp 13)button_clear.cpp,
and 14)eraser.cpp- which delete a charcter.

Also every '.cpp' file has a header file.
14 source + 13 header = 27 files in total.
================================================================================

Algorithms worth mention:
==========================
used modulus to find the corner of a square in the grid

================================================================================

Known bugs
=========
when CLEAR button is pushed, the window is not responding until the user make his 
new choice in the console (of the grid size).

================================================================================

