#pragma once
#ifndef MOVING_OBJECT_H
#define MOVING_OBJECT_H
#include "Object.h"

class MovingObject : public Object {
	double	angleRotation;
public:
	MovingObject(int id, double angle);
	virtual ~MovingObject();
	double GetAngleRotation() const;
	void SetAngleRotation(double angle);




};



#endif