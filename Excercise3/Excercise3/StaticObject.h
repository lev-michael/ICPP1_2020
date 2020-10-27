#pragma once
#ifndef STATIC_OBJECT_H
#define STATIC_OBJECT_H
#include "Object.h"
#include "EnumBarrier.h"

class StaticObject : public Object {
	BarrierType barrierType;
public:
	StaticObject(int id, BarrierType type);
	virtual ~StaticObject();
	BarrierType GetBarrierType();

};


#endif