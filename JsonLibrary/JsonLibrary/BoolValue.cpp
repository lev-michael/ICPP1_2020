#include "pch.h"
#include "api.h"

BoolValue::BoolValue(bool value)
{
	this->value = value;
}

bool BoolValue::get() const
{
	return value;
}

std::string BoolValue::serialize() const
{
	if (value) {
		return "true";
	}
	return "false";
}
