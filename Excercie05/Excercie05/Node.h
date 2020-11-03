#pragma once
#ifndef NODE_H
#define NODE_H
#include "Person.h"

class Node {
public:
	Node* next;
	Entity::Person* person;
	Node(Entity::Person* person);
	~Node();
};


#endif // !NODE_H



