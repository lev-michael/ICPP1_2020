#include "PhoneBook.h"
#include "Person.h"

PhoneBook::PhoneBook()
{
    this->first = nullptr;
}

PhoneBook::~PhoneBook()
{
}

void PhoneBook::push(Node* newNode)
{
    newNode->next = this->first;
    this->first = newNode;
}


Node* PhoneBook::findById(int id)
{
    if (id < 1) {
        throw new std::exception("Invalid ID");
    }

    Node* temp = this->first;
    while (temp != nullptr) {
        if (temp->person->id == id) {
            return temp;
        }
        temp = temp->next;
    }
    throw new std::exception("No person found");
}

Node* PhoneBook::findByName(std::string name)
{

    if (name.empty) {
        throw new std::exception("Invalid name");
    }

    Node* temp = this->first;
    while (temp != nullptr) {
        if (temp->person->firstName == name) {
            return temp;
        }
        temp = temp->next;
    }
    throw new std::exception("No person found");
}
Node::Node(Person* person)
{
    this->next = nullptr;
    this->person = person;
}
