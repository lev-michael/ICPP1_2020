#pragma once
#ifndef PHONE_BOOK_H
#define PHONE_BOOK_H
#include <string>
#include "Person.h"


class PhoneBook {
public:
	Node* first;
	PhoneBook();
	~PhoneBook();
	void push(Node* newNode);
	Node* findById(int id);
	Node* findByName(std::string name);
};

class Node {
public:
	Node* next;
	Person* person;
	Node(Person* person);
};


#endif
