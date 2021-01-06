#pragma once
class Character
{
public:

	Character();
	Character(float health, float damage);

	void SaveDataP1();
	void SaveDataP2();
	void LoadDataP1();
	void LoadDataP2();
	void player1turn(Character* other);
	void player2turn(Character* other);
	void player1Dead();



	void attack(Character* other);
	float takeDamage(float damageAmount);

	float getDamage() { return m_damage; }
	float getHealth() { return m_health; }
	

private:

	float m_health;
	float m_damage;

};

