#include "Monster.h"

Monster::Monster(int id, double angle, int hp, int maxHp)
	:MovingObject(id,angle)
{
	this->hp = hp;
	this->maxHp = maxHp;
}

Monster::~Monster()
{
}

int Monster::GetHp() const
{
	return this->hp;
}

int Monster::GetMaxHp() const
{
	return this->maxHp; 
}

void Monster::SetHp(int hp)
{
	this->hp = hp;
}

void Monster::SetMaxHp(int maxHp)
{
	this->maxHp = maxHp;
}
	