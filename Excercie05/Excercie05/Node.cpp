#include "Node.h"

Node::Node(Entity::Person* person)
{
	this->next = nullptr;
	this->person = person;
}

Node::~Node()
{}

Node* Node::GetNext()
{
	return next;
}

void Node::SetNext(Node* node)
{
	this->next = node;
}

Entity::Person* Node::GetPerson()
{
	return person;
}
