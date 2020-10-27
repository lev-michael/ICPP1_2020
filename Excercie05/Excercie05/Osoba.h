#pragma once
#ifndef OSOBA_H
#define OSOBA_H
#include <string>

class Person {
private:
	int id;
	std::string firstName;
	std::string phone;

public: 
	Person(int id, std::string firstName, std::string phone);
};

#endif // !OSOBA_H

