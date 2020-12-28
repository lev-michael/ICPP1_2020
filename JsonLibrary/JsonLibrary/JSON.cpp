#include "pch.h"
#include "api.h"
#include <stdexcept>

Value* JSON::deserialize(const std::string& string)
{
	int pointer = 0;
	try{
		return deserialize(string, pointer);
	}
	catch (std::invalid_argument e) {
		std::string error = "Error while JSON deserialization. ";
		std::string position = " at " + std::to_string(pointer) + ". character";
		throw std::invalid_argument(error.append(e.what()).append(position));
	}
}

std::string JSON::serialize(const Value* value)
{
	return value->serialize();
}

Value* JSON::deserialize(const std::string& string, int& pointer)
{
	if (string.empty()) {
		throw std::invalid_argument("Empty input");
	}
	char c = string.at(pointer);
	try {
		switch (c) {
		case '{':
			return readObject(string, pointer);
		case '[':
			pointer++;
			return readArray(string, pointer);
		case '"':
			return readString(string, pointer);
		case 't':
			return readBool(string, pointer, true);
		case 'f':
			return readBool(string, pointer, false);
		case 'n':
			return readNull(string, pointer);
		default:
			if (isdigit(c) || c == '.') {
				return readNumber(string, pointer);
			}
			throw std::invalid_argument("Invalid character");
		}
	}
	catch (std::invalid_argument e) {
		throw std::invalid_argument(e.what());
	}
}

NullValue* JSON::readNull(const std::string& string, int& pointer) {
	std::string value = string.substr(pointer, 4);
	pointer += 4;
	if (value != "null") {
		throw std::invalid_argument("Invalid bool value");
	}
	return new NullValue();
}

BoolValue* JSON::readBool(const std::string& string, int& pointer, bool value) {
	std::string boolean;
	if (value) {
		boolean = string.substr(pointer, 4);
		pointer += 4;
	}
	else {
		boolean = string.substr(pointer, 5);
		pointer += 5;
	}
	if (boolean != "true" || boolean != "false") {
		throw std::invalid_argument("Invalid bool value");
	}
	return new BoolValue(value);
}


NumberValue* JSON::readNumber(const std::string& string, int& pointer) {
	std::string num;
	while (isdigit(string.at(pointer)) || string.at(pointer) == '.') {
		num += (string.at(pointer++));
	}
	return new NumberValue(stod(num));
}

StringValue* JSON::readString(const std::string& string, int& pointer)
{
	std::string str;
	skipQuotes(string, pointer);
	while (string.at(pointer) != '"') {
		str += string.at(pointer);
		if (string.at(pointer) == '\\') {
			str += string.at(++pointer);
		}
		pointer++;
	}
	skipQuotes(string, pointer);
	return new StringValue(str);
}

ArrayValue* JSON::readArray(const std::string& string, int& pointer) {
	ArrayValue* array = new ArrayValue();
	while (string.at(pointer) != ']') {
		if (string.at(pointer) == ',') {
			pointer++;
		}
		try {
			array->append(deserialize(string, pointer));
		}
		catch (std::invalid_argument e) {
			delete array;
			throw std::invalid_argument(e.what());
		}
	}
	pointer++;
	return array;
}

ObjectValue* JSON::readObject(const std::string& string, int& pointer) {
	ObjectValue* object = new ObjectValue();
	std::string key;
	skipCurlyBraces(string, pointer);
	while (string.at(pointer) != '}') {
		skipQuotes(string, pointer);
		while (string.at(pointer) != '\"') {
			key += string.at(pointer++);
		}
		skipQuotes(string, pointer);
		skipColon(string, pointer);
		Value* value;
		try {
			value = deserialize(string, pointer);
		}
		catch (std::invalid_argument e) {
			delete object;
			throw std::invalid_argument(e.what());
		}
		object->append(KeyValuePair{ key,value });
		skipComma(string, pointer);
		key.clear();
	}
	pointer++;
	return object;
}

void JSON::skipQuotes(const std::string& string, int& pointer) {
	if (string.at(pointer) != '"') {
		throw std::invalid_argument("Missing quotes");
	}
	pointer++;
}

void JSON::skipComma(const std::string& string, int& pointer) {
	if (string.at(pointer) == ',') {
		pointer++;
	}
}

void JSON::skipColon(const std::string& string, int& pointer) {
	if (string.at(pointer) != ':') {
		throw std::invalid_argument("Invalid object. Missing colon");
	}
	pointer++;
}

void JSON::skipCurlyBraces(const std::string& string, int& pointer) {
	if (string.at(pointer) != '{') {
		throw std::invalid_argument("Invalid start of object. Missing Curly brace");
	}
	pointer++;
}