#pragma once
#include "Character.h"

class game
{
public:
	
	void run();
	bool getGameOver() { return m_gameOver; }
	void setGameOver(bool value) { m_gameOver = value; }
	


private:

	void start();
	void update();
	void draw();
	void end();

private:

	bool m_gameOver; 
	//Makes the characters pointers
	Character* m_player1;
	Character* m_player2;
};