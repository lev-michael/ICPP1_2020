#include "StaticObject.h"

StaticObject::StaticObject(int id, BarrierType type)
	:Object(id)
{
	this->barrierType = type;
}

StaticObject::~StaticObject()
{
}

BarrierType StaticObject::GetBarrierType()
{
	return this->barrierType;
}
