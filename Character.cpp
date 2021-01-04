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

void Character::Intro()
{
	std::cout << "Welcome to my trial. In this game, you will face many enemies and will most likely struggle." << std::endl;
	system("pause");
	system("cls");
	std::cout << "There are many floors here, which is why you will be asked to save after every battle. You're welcome." << std::
}




//Player 1's turn
void Character::player1turn(Character* other)
{

	int choice;
	std::cout << "Player 1 it is your turn" << std::endl;
	std::cout << "1.Attack" << std::endl; std::cout << "2.Pass";
	std::cin >> choice;
	
	//If the player attacks
	if (choice == 1)
	{
		other->attack(other);
		std::cout << "You  attacked and Player 2 has " << other->getHealth() << " Hp" << std::endl;
		system("pause");
		system("cls");

		if (other->getHealth() <= 0)
		{
			std::cout << "player 1 is dead.";
			system("pause");
			delete other;
			player2Dead();
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
		std::cout << "You attacked and Player 1 has " << other->getHealth() << " Hp" << std::endl;
		system("pause");
		system("cls");

		//If the other player dies this turn
		if (other->getHealth() <= 0)
		{
			std::cout << "player 1 is dead.";
			system("pause");
			delete other;
			player1Dead();
			
		}
		
	}

	//If the player decides to do nothing
	else if (choice == 2)
	{
		std::cout << "Pass test";
		
	}
}

//This is what happens if player 1 losses
void Character::player1Dead()
{
	std::cout << "Player 1 has been defeated!!!";
}


//This is what happens if player 2 losses
void Character::player2Dead()
{
	std::cout << "Player 2 has been defeated!!!";
}

void Character::faceEnemies(Character* other)
{
	int room = 1;

	switch (room)
	{
		case 1:
		{
			std::cout << "You enter room 1.";
		}
	

	
	default:
		break;
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


