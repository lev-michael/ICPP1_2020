#pragma once
#ifndef PERSON_H
#define PERSON_H
#include <string>
#include "Address.h"
#include "Date.h"

struct Person {
	std::string _forename;
	std::string _surname;
	Address _address;
	Date _birthday;
	Person(std::string forename, std::string surname, Address address, Date birthday);
	Person();
	~Person();
	std::string GetForename() const;
	std::string GetSurname() const;
	Address GetAddress() const;
	Date GetDate() const;
	void SetForename(std::string forename);
	void SetSurname(std::string surname);
	void SetAddress(Address address);
	void SetBirthDay(Date birthday);
	friend std::ostream& operator<<(std::ostream& os, const Person& o);
	friend std::istream& operator>>(std::istream& is, Person& o);
};

#endif // !PERSON_H