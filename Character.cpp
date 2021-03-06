#include "Character.h"
#include <iostream>
#include <fstream>

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


//Save data for player 1.
void Character::SaveDataP1()
{
	Character* P1;
	std::ofstream file;
	file.open("SaveDataP1.txt", std::ios::out | std::ios::binary);
	std::cout << "PLAYER 1:" << std::endl;
	file.write((char*)&m_health, sizeof(P1));
	file.close();

}

//Save data for player 2.
void Character::SaveDataP2()
{
	Character* P2;
	std::ofstream file;
	file.open("SaveDataP2.txt", std::ios::out | std::ios::binary);
	std::cout << "PLAYER 2:" << std::endl;
	file.write((char*)&m_health, sizeof(P2));
	file.close();

}



//Player 1's turn
void Character::player1turn(Character* other)
{

	int choice;
	std::cout << "Player 1 it is your turn" << std::endl;
	std::cout << "1.Attack" << std::endl; std::cout << "2.Pass" << std::endl; std::cout << "3.Save";
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
		}
		
	}

	//If the player decides to do nothing
	else if (choice == 2)
	{
		std::cout << "Pass test ";
	}

	//If the player wants to save
	else if (choice == 3)
	{
		SaveDataP1();
		std::cout << "Player 1 is saving...";
		system("pause");
		system("cls");
	}
}



//Player 2's turn
void Character::player2turn(Character* other)
{
	
	int choice;
	std::cout << "Player 2 it is your turn" << std::endl;
	std::cout << "1.Attack" << std::endl; std::cout << "2.Pass" << std::endl; std::cout << "3.Save";
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
		std::cout << "Pass test ";
		
	}

	//If the player wants to save
	else if (choice == 3)
	{
		SaveDataP2();
		std::cout << "Player 2 is saving...";
		system("pause");
		system("cls");
	}
}

//This is what happens if player 1 losses
void Character::player1Dead()
{
	std::cout << "Player 1 has been defeated!!!";
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


