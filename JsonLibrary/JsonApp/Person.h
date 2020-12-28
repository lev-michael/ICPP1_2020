#pragma once
#ifndef PERSON_H
#define PERSON_H
#include <string>
#include "Address.h"
#include "Date.h"

class Person {
private:
	std::string id;
	std::string name;
	Address *address;
	Date *birthday;
	std::string phone;
	std::string generateId() const;
public:
	Person(std::string name, std::string phone,
		int day, int month, int year, std::string street, int houseNumber,
		std::string city, std::string zip);
	Person(std::string id, std::string name, std::string phone,
		int day, int month, int year, std::string street, int houseNumber,
		std::string city, std::string zip);
	Person() = default;
	~Person();
	std::string GetId() const;
	std::string GetName() const;
	Address* GetAddress() const;
	Date* GetBirthday() const;
	std::string GetPhone() const;
	void SetName(std::string name);
	void SetPhone(std::string phone);
	void SetAddressStreet(std::string street);
	void SetAddressCity(std::string city);
	void SetAddressZip(std::string zip);
	void SetAddressHouse(int house);
	void SetBirthDay(int day);
	void SetBirthMonth(int month);
	void SetBirthYear(int year);
	std::string toString() const;
};

#endif // !PERSON_H