#pragma once
#ifndef PHONE_BOOK_H
#define PHONE_BOOK_H
#include <string>
#include "Person.h"

	class PhoneBook {
	private:
		DynamicArray<Person*> *contacts;
		int findIndex(std::string id);
		void load();
		
	public:
		PhoneBook();
		~PhoneBook();
		void add(Person* person);
		Person* remove(std::string id);
		Person* find(std::string id);
		void save(std::string file) const;
		void toString() const;
		bool isEmpty() const;
	};

#endif