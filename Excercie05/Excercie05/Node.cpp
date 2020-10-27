#include "Node.h"

Node::Node(Person* person)
{
	this->next = nullptr;
	this->person = person;
}

Node::~Node()
{
	delete person;
	delete next;
}
