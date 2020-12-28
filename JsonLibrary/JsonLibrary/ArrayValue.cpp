#include "pch.h"
#include "api.h"

ArrayValue::ArrayValue()
{
	this->size = 0;
	this->array = new DynamicArray<Value*>();
}

ArrayValue::~ArrayValue()
{
	for (int i = 0; i < size; i++)
	{
		delete array->getElementAt(i);
	}
	delete array;
}

void ArrayValue::append(Value* element) {
	this->array->append(element);
	this->size++;
}

std::string ArrayValue::serialize() const
{
	std::string output = "[";
	for (int i = 0; i < size; i++)
	{
		output.append(this->array->getElementAt(i)->serialize());
		if (i != size-1)
			output.append(",");
	}
	output.append("]");
	return output;
}

int ArrayValue::getSize() const
{
	return this->size;
}
