#pragma once
#ifndef OSOBA_H
#define OSOBA_H
#include <string>

namespace Entity {
	class Person {
		int id;
		std::string firstName;
		std::string phone;
	public:
		Person(int id, std::string firstName, std::string phone);
		~Person();
		void toString() const;
		std::string GetFirstName();
		int GetId();
	};
}



#endif // !OSOBA_H


