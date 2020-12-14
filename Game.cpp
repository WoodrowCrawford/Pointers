#include "game.h"
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
	m_player1 = Character(10, 5);
	m_player2 = Character(10, 5);

}

void game::update()
{
	m_player1.attack(m_player2);
}

void game::draw()
{
	std::cout << "Player2 health is: " << m_player2.getHealth();
}

void game::end()
{
}
