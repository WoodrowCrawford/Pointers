#include "game.h"
#include "Character.h"
#include <iostream>
#include <fstream>

void game::run()
{
	start();

	while (!getGameOver())
	{
		update();
		draw();

		system("pause");
	}

	end();
}

void game::start()
{

	//Player 1 Loading section
	std::cout << "Welcome! Would you like to load from a previous save?" << std::endl;
	std::cout << "1.Yes" << std::endl;
	std::cout << "2.No" << std::endl;

	int input;
	std::cin >> input;

	//if Player 1 wants to start a game with previous stats
	if (input == 1)
	{
		std::ifstream file;
		file.open("SaveDataP1.txt", std::ios::in | std::ios::binary);
		std::cout << "PLAYER 1:" << std::endl;
		std::cout << "Save data loaded." << std::endl;
		file.close();
	}

	else if (input == 2)
	{
		std::cout << "You chose to play without a save file";
		system("pause");
		system("cls");
	}


	//Player 2 loading section
	std::cout << "Welcome! Would you like to load from a previous save?" << std::endl;
	std::cout << "1.Yes" << std::endl;
	std::cout << "2.No" << std::endl;

	int input2;
	std::cin >> input2;

	//if Player 2 wants to start a game with previous stats
	if (input2 == 1)
	{
		std::ifstream file;
		file.open("SaveDataP2.txt", std::ios::in | std::ios::binary);
		std::cout << "PLAYER 2:" << std::endl;
		std::cout << "Save data loaded." << std::endl;
		file.close();
	}

	else if (input2 == 2)
	{
		std::cout << "You chose to play without a save file";
		system("pause");
		system("cls");
	}

	m_player1 = new Character(15, 5);
	m_player2 = new Character(15, 5);
	

}

void game::update()
{
	m_player1->player1turn(m_player2);
	m_player2->player2turn(m_player1);
	
}

void game::draw()
{
	//std::cout << "Player2 health is: " << m_player2->getHealth();
}

void game::end()
{
	delete m_player1;
	delete m_player2;

}
