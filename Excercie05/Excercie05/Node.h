#pragma once
#ifndef NODE_H
#define NODE_H
#include "Person.h"

class Node {
	Node* next;
	Entity::Person* person;
public:
	Node(Entity::Person* person);
	~Node();
	Node* GetNext();
	void SetNext(Node* node);
	Entity::Person* GetPerson();
};


#endif // !NODE_H



