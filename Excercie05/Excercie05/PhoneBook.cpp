#include "Node.h"
#include "Person.h"
#include "PhoneBook.h"
#include <stdexcept>

Model::PhoneBook::PhoneBook()
{}



Model::PhoneBook::~PhoneBook()
{
    Node* temp = NULL;
    while (first != NULL) {
        temp = first->GetNext();
        delete first;
        first = temp;
    }
}

void Model::PhoneBook::push(Node* newNode)
{
    newNode->SetNext(this->first);
    this->first = newNode;
}


Node* Model::PhoneBook::findById(int id)
{
    if (id < 1) {
        throw std::invalid_argument("Invalid ID");
    }

    Node* temp = this->first;
    while (temp != nullptr) {
        if (temp->GetPerson()->GetId() == id) {
            return temp;
        }
        temp = temp->GetNext();
    }
    throw std::invalid_argument("No person found");
}

Node* Model::PhoneBook::findByName(std::string name)
{

    if (name.empty()) {
        throw std::invalid_argument("Invalid name");
    }

    Node* temp = this->first;
    while (temp != nullptr) {
        if (temp->GetPerson()->GetFirstName() == name) {
            return temp;
        }
        temp = temp->GetNext();
    }
    throw std::invalid_argument("No person found");
}

Node* Model::PhoneBook::GetFirst()
{
    return first;
}

