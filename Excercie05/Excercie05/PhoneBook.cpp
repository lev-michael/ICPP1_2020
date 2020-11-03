#include "Node.h"
#include "Person.h"
#include "PhoneBook.h"

Model::PhoneBook::PhoneBook()
{
    this->first = nullptr;
}



Model::PhoneBook::~PhoneBook()
{
    Node* temp = NULL;
    while (first != NULL) {
        temp = first->next;
        delete first;
        first = temp;
    }
}

void Model::PhoneBook::push(Node* newNode)
{
    newNode->next = this->first;
    this->first = newNode;
}


Node* Model::PhoneBook::findById(int id)
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

Node* Model::PhoneBook::findByName(std::string name)
{

    if (name.empty()) {
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

