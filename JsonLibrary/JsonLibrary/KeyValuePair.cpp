#include "pch.h"
#include "api.h"

KeyValuePair::KeyValuePair(std::string key, Value* value)
{
	this->key = key;
	this->value = value;
}

std::string KeyValuePair::getKey() const
{
	return this->key;
}

Value* KeyValuePair::getValue() const
{
	return this->value;
}
