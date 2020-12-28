#include "pch.h"
#include "api.h"

StringValue::StringValue(std::string value)
{
	this->value = value;
}

std::string StringValue::get() const
{
	return value;
}

std::string StringValue::processEscapeChars(std::string value) const
{
	std::string output;
	for (size_t i = 0; i < value.length(); i++)
	{
		switch (value.at(i)) {
			case '\\':
				output.append("\\\\");
				break;
			case '\"':
				output.append("\\\"");
				break;
			default:
				output += value.at(i);
		}
	}
	return output;
}



std::string StringValue::serialize() const
{
	return "\"" + processEscapeChars(value) + "\"";
}
