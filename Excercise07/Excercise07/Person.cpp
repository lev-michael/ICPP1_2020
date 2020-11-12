#include "Person.h"
#include "Address.h"
#include "Date.h"
#include <string>
#include <iostream>

using namespace std;


Person::Person(std::string forename, std::string surname, Address address, Date birthday)
{
	_forename = forename;
	_surname = surname;
	_address = address;
	_birthday = birthday;
}

Person::Person()
{
}

Person::~Person()
{
}

std::string Person::GetForename() const
{
	return _forename;
}

std::string Person::GetSurname() const
{
	return _surname;
}

Address Person::GetAddress() const
{
	return _address;
}

Date Person::GetDate() const
{
	return _birthday;
}

void Person::SetForename(std::string forename)
{
	_forename = forename;
}

void Person::SetSurname(std::string surname)
{
	_surname = surname;
}

void Person::SetAddress(Address address)
{
	_address = address;
}

void Person::SetBirthDay(Date birthday)
{
	_birthday = birthday;
}

std::ostream& operator<<(std::ostream& os, const Person& o)
{
	return os << o.GetForename() << " " << o.GetSurname() << " " << o.GetAddress() << ", " << o.GetDate();
}

std::istream& operator>>(std::istream& is, Person& o)
{
	char c;
	is >> o._forename >> o._surname >> o._address >> c >> o._birthday;
	return is;
}

