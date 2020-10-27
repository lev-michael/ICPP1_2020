#pragma once
#ifndef OSOBA_H
#define OSOBA_H
#include <string>
#include "PhoneBook.h"


class Person {
	public:
		Person(int id, std::string firstName, std::string phone);
		int id;
		std::string firstName;
		std::string phone;
		void toString() const;
	};

#endif // !OSOBA_H


