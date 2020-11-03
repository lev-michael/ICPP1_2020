#include "Node.h"

Node::Node(Entity::Person* person)
{
	this->next = nullptr;
	this->person = person;
}

Node::~Node()
{
	delete person;
	delete next;
}
