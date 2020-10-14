#include "Game.h"
#include <exception>
#include <cmath>
#include <iostream>


Game::Game(int kapacita)
{
	this->capacity = kapacita;
	this->objects = new Object * [kapacita];
	for (int i = 0; i < kapacita; i++)
		objects[i] = new Object(i);
	this->counter = 0;
}

Game::~Game()
{
	for (size_t i = 0; i < this->counter; i++)
	{
		delete objects[i];
	}
	delete objects;
}

void Game::insertObject(Object* o)
{
	if (counter >= capacity) {
		throw new std::exception("array is full");
	}
	objects[counter++] = o;
}

int* Game::findIdOfStaticObjects(double xmin, double xmax, double ymin, double ymax)
{
	int x, y, howMuchStatic = 0;
	StaticObject* so;
		for (size_t i = 0; i < counter; i++)
		{
			so = dynamic_cast<StaticObject*>(objects[i]);
			if (so != NULL) {
				x = so->GetX();
				y = so->GetY();
				if (x >= xmin && x <= xmax && y <= ymax && y >= ymin) {
					howMuchStatic++;
				}
			}
		}
	if (howMuchStatic == 0)
		return nullptr;

	int* staticObjects = new int[howMuchStatic];
	howMuchStatic = 0;
	
	for (size_t i = 0; i < counter; i++)
	{
		so = dynamic_cast<StaticObject*>(objects[i]);
		if (so != NULL) {
			x = so->GetX();
			y = so->GetY();
			if (x >= xmin && x <= xmax && y <= ymax && y >= ymin) {
				staticObjects[howMuchStatic] = objects[i]->GetId();
				std::cout << so->GetId() << ", ";
				howMuchStatic++;
			}
		}
	}
	std::cout << std::endl;
	return staticObjects;
}

MovingObject** Game::findMovingObjectsInArea(double xCenter, double yCenter, double r)
{
	int x, y, howMuchMoving = 0;
	MovingObject* mo;
	for (size_t i = 0; i < counter; i++)
	{
		mo = dynamic_cast<MovingObject*>(objects[i]);
		if (mo != nullptr) {
			x = mo->GetX();
			y = mo->GetY();
			if (sqrt(pow(x - xCenter, 2) + pow(y - yCenter, 2)) <= r) {
				howMuchMoving++;
			}
		}
	}
	if (howMuchMoving == 0)
		return nullptr;

	MovingObject** movingObjects = new MovingObject * [howMuchMoving];
	howMuchMoving = 0;
	for (size_t i = 0; i < counter; i++)
	{
		mo = dynamic_cast<MovingObject*>(objects[i]);
		if (mo != nullptr) {
			x = mo->GetX();
			y = mo->GetY();
			if (sqrt(pow(x - xCenter, 2) + pow(y - yCenter, 2)) <= r) {
				movingObjects[howMuchMoving] = mo;
				howMuchMoving++;
			}
		}
	}
	return movingObjects;
}

MovingObject** Game::findMovingObjectsInArea(double xCenter, double yCenter, double r, double angleMin, double angleMax)
{
	int x, y, howMuchMoving = 0;
	double angle;
	MovingObject* mo;
	for (size_t i = 0; i < counter; i++)
	{
		mo = dynamic_cast<MovingObject*>(objects[i]);
		if (mo != nullptr) {
			x = mo->GetX();
			y = mo->GetY();
			angle = mo->GetAngleRotation();
				if (sqrt(pow(x - xCenter, 2) + pow(y - yCenter, 2)) <= r && angle>=angleMin && angle<=angleMax) {
					howMuchMoving++;
				}
		}
	}
	if (howMuchMoving == 0)
		return nullptr;

	MovingObject** movingObjects = new MovingObject * [howMuchMoving];
	howMuchMoving = 0;

	for (size_t i = 0; i < counter; i++)
	{
		mo = dynamic_cast<MovingObject*>(objects[i]);
		if (mo != nullptr) {
			x = mo->GetX();
			y = mo->GetY();
			angle = mo->GetAngleRotation();
			if (sqrt(pow(x - xCenter, 2) + pow(y - yCenter, 2)) <= r && angle >= angleMin && angle <= angleMax) {
				movingObjects[howMuchMoving] = mo;
				howMuchMoving++;
			}
		}
	}
	return movingObjects;
}

int Game::GetCount() const
{
	return this->counter;
}
