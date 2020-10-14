#include "MovingObject.h"

MovingObject::MovingObject(int id, double angle)
	:Object(id)
{
	this->angleRotation = angle;
}

MovingObject::~MovingObject()
{
}

double MovingObject::GetAngleRotation() const
{
	return this->angleRotation;
}

void MovingObject::SetAngleRotation(double angle)
{
	this->angleRotation = angle;
}
