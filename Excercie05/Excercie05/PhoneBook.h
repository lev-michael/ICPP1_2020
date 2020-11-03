#pragma once
#ifndef PHONE_BOOK_H
#define PHONE_BOOK_H
#include <string>
#include "Person.h"
#include "Node.h"

namespace Model{
	class PhoneBook {
		Node* first;
	public:
		PhoneBook();
		~PhoneBook();
		void push(Node* newNode);
		Node* findById(int id);
		Node* findByName(std::string name);
		Node* GetFirst();
	};
}





#endif
