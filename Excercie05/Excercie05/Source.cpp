#include "Person.h"
#include "PhoneBook.h"
#include <string>
#include <iostream>
#include <time.h>       

using namespace std;
using namespace Entity;
using namespace Model;

int main(int argc, char* argv[]) {
	Person* p;
	Node* n;
	srand(time(NULL));
	PhoneBook* phoneBook = new PhoneBook();
	string name = "Person";
	string phone;

	for (size_t i = 1; i < 1000; i++)
	{
		p = new Person(i, name + to_string(i), to_string(rand() % 899 + 100)+" "+ to_string(rand() % 899 + 100) + " "+ to_string(rand() % 899 + 100));
		n = new Node(p);
		phoneBook->push(n);
	}
	n = phoneBook->first;
	while (n != NULL) {
		n->person->toString();
		n = n->next;
	}

	n = phoneBook->findById(50);
	n->person->toString();
	n = phoneBook->findByName("Person77");
	n->person->toString();

}