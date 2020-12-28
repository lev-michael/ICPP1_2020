#include "pch.h"
#include "api.h"
#include <sstream>


NumberValue::NumberValue(double value)
{
	this->value = value;
}

double NumberValue::get() const
{
	return value;
}

std::string NumberValue::serialize() const
{
	std::stringstream ss;
	ss << value;
	return ss.str();
}
