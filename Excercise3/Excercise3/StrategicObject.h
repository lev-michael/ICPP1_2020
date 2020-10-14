#pragma once
#ifndef STRATEGIC_OBJECT_H
#define STRATEGIC_OBJECT_H
#include "Object.h"

enum class BarrierType {Rock, smallPlant,bigPlant};

class StrategicObject : public Object {
	BarrierType barrierType;
public: 
	StrategicObject(int id, BarrierType type);
	BarrierType GetBarrierType();

};


#endif