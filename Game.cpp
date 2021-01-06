#include "game.h"
#include "Character.h"
#include <iostream>

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
	m_player1 = new Character(15, 5);
	m_player2 = new Character(15, 5);
	m_player1->LoadSaveDataP1();


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
