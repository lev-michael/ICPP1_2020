#pragma once
#ifndef GAME_H
#define GAME_H
#include "Object.h"
#include "MovingObject.h"
#include "StaticObject.h"
#include "Monster.h"
#include "EnumBarrier.h"

class Game {
	Object** objects;
	int counter;
	int capacity;
public:
	Game(int capacity);
	~Game();
	void insertObject(Object* o);
	int* findIdOfStaticObjects(double xmin, double xmax, double ymin, double ymax);
	MovingObject** findMovingObjectsInArea(double x, double y, double r);
	MovingObject** findMovingObjectsInArea(double x, double y, double r, double angleMin, double angleMax);
	int GetCount() const;



};

#endif // !GAME_H
