#pragma once
#ifndef MONSTER_H
#define MONSTER_H
#include "MovingObject.h"

class Monster : public MovingObject {
	int hp;
	int maxHp;
public:
	Monster(int id, double angle,int hp, int maxHp);
	virtual ~Monster();
	int GetHp() const;
	int GetMaxHp() const;
	void SetHp(int hp);
	void SetMaxHp(int maxHp);
};



#endif