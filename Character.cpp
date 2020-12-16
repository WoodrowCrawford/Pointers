#include "Character.h"
#include <iostream>

Character::Character()
{
	m_health = 100;
	m_damage = 10;
}

Character::Character(float health, float damage)
{
	m_health = health;
	m_damage = damage;
}

void Character::getPlayerName()
{
	char player1Name[15];
	char player2Name[15];
	std::cout << "Welcome to the pvp game! Please tell me your names." << std::endl;
	std::cout << "Player 1 Name: ";  std::cin >> player1Name;
	system("cls");
	std::cout << "And what is you name player 2?";
	std::cout << "Player 2 Name: ";  std::cin >> player2Name;
	system("cls");



}


//Player 1's turn
void Character::player1turn(Character* other)
{

	int choice;
	std::cout << "it is your turn" << std::endl;
	std::cout << "1.Attack" << std::endl; std::cout << "2.Pass";
	std::cin >> choice;
	
	//If the player attacks
	if (choice == 1)
	{
		other->attack(other);
		std::cout << "Player 2 has " << other->getHealth() << " Hp" << std::endl;
		system("pause");
		system("cls");

		if (other->getHealth() <= 0)
		{
			std::cout << "player 1 is dead.";
			system("pause");
			delete other;
		}
		
	}

	//If the player decides to do nothing
	else if (choice == 2)
	{
		std::cout << "Pass test";
	}
}



//Player 2's turn
void Character::player2turn(Character* other)
{
	
	int choice;
	std::cout << "Player 2 it is your turn" << std::endl;
	std::cout << "1.Attack" << std::endl; std::cout << "2.Pass";
	std::cin >> choice;

	//If the player attacks
	if (choice == 1)
	{
		other->attack(other);
		std::cout << "Player 1 has " << other->getHealth() << " Hp" << std::endl;
		system("pause");
		system("cls");

		if (other->getHealth() <= 0)
		{
			std::cout << "player 1 is dead.";
			system("pause");
			delete other;
			
		}
		
	}

	//If the player decides to do nothing
	else if (choice == 2)
	{
		std::cout << "Pass test";
	}
}


void Character::attack(Character* other)
{
	other->takeDamage(getDamage());
}

float Character::takeDamage(float damageAmount)
{
	m_health -= damageAmount;
	return damageAmount;
}


