#include "Person.h"
#include <iostream>

Entity::Person::Person(int id, std::string firstName, std::string phone)
{
	this->firstName = firstName;
	this->id = id;
	this->phone = phone;
}

Entity::Person::~Person()
{
}

void Entity::Person::toString() const
{
	std::cout << "id: " + std::to_string(id) + ", name: " + firstName + ", phone: " + phone << std::endl;
}
