#include <iostream>
#include <fstream>
#include "game.h"

void SaveData()
{
	std::fstream file;
	file.open("SaveData.txt", std::ios::in | std::ios::binary);

}


int main()
{
	game Game = game();
	Game.run();
	return 0;
}