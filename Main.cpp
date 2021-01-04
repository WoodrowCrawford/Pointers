#include <iostream>
#include <fstream>	
#include "game.h"


//Used as a binary file example


int main()
{
	game Game = game();
	Game.run();

	return 0;

	std::fstream file;
	file.open("SaveData.txt", std::ios::out);
	
	if (!file.is_open())
	{
		return 1;
	}

	
	
}