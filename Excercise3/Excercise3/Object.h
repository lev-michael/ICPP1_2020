#pragma once
#ifndef OBJECT_H
#define OBJECT_H

class Object {
	int id;
	double x;
	double y;
public:
	Object(int id);
	virtual ~Object();
	double GetX() const;
	double GetY() const;
	int GetId() const;
	void SetX(double x);
	void SetY(double y);
};



#endif 

