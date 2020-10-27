#pragma once
#ifndef OSOBA_H
#define OSOBA_H
#include <string>


class Person {
public:
	Person(int id, std::string firstName, std::string phone);
	~Person();
	int id;
	std::string firstName;
	std::string phone;
	void toString() const;
};

#endif // !OSOBA_H


