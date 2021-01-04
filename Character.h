#pragma once
class Character
{
public:

	Character();
	Character(float health, float damage);



	void player1turn(Character* other);
	void player2turn(Character* other);
	void player1Dead();
	void player2Dead();

	void faceEnemies(Character* other);

	void attack(Character* other);
	float takeDamage(float damageAmount);

	float getDamage() { return m_damage; }
	float getHealth() { return m_health; }

	float SetHealth() { m_health; }
	float SetDamage() { m_health; }
	

private:

	float m_health;
	float m_damage;

};

