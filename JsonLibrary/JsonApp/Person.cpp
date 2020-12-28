#include "Person.h"
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

string Person::generateId() const
{
	string id;
	int random;
	srand(time(NULL));
	for (size_t i = 0; i < 6; i++)
	{
		random = rand() % 10;
		id +=  to_string(random);
	}
	return id;
}

Person::Person(string name, string phone, int day, int month, int year,
	string street, int houseNumber,  string city,  string zip)
{
	try {
		this->birthday = new Date(day, month, year);
	}
	catch (invalid_argument e) {
		throw std::invalid_argument(e.what());
	}
	this->id = generateId();
	this->name = name;
	this->phone = phone;
	this->address = new Address(street, houseNumber, city, zip);

}

Person::Person(std::string id, std::string name, std::string phone, int day, int month, int year, std::string street, int houseNumber, std::string city, std::string zip)
	: Person(name, phone, day, month, year, street, houseNumber, city, zip)
{
	this->id = id;
}

Person::~Person()
{
	delete address;
	delete birthday;
}

 string Person::GetId() const
{
	 return this->id;
}


 string Person::GetName() const
{
	return this->name;
}

Address* Person::GetAddress() const
{
	return this->address;
}

Date* Person::GetBirthday() const
{
	return this->birthday;
}

string Person::GetPhone() const
{
	return this->phone;
}

void Person::SetName( string name)
{
	this->name = name;
}

void Person::SetPhone(string phone)
{
	this->phone = phone;
}

void Person::SetAddressStreet(std::string street)
{
	this->address->SetStreet(street);
}

void Person::SetAddressCity(std::string city)
{
	this->address->SetCity(city);
}

void Person::SetAddressZip(std::string zip)
{
	this->address->SetZip(zip);
}

void Person::SetAddressHouse(int house)
{
	this->address->setHouseNum(house);
}

void Person::SetBirthDay(int day)
{
	this->birthday->SetDay(day);
}

void Person::SetBirthMonth(int month)
{
	this->birthday->SetMonth(month);
}


void Person::SetBirthYear(int year)
{
	this->birthday->SetYear(year);
}

string Person::toString() const {
	return "\nID: " + this->id + "\nName: " + this->name + "\nPhone:" + this->phone
		+ "\nBirthday: " + this->birthday->toString() + "\nAddress: " + this->address->toString() +"\n";
}
