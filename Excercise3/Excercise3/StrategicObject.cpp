#include "StrategicObject.h"

StrategicObject::StrategicObject(int id, BarrierType type)
	:Object(id)
{	
	this->barrierType = type;
}

 BarrierType StrategicObject::GetBarrierType()
{
	return this->barrierType;
}
