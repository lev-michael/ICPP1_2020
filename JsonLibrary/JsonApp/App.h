#pragma once
#include <iostream>
#include <api.h>
#include "PhoneBook.h"

class App {
private:
	PhoneBook* book;
	bool is_number(const std::string& s) const;
	std::string getInput(std::string text) const;
	int getNumberInput(std::string text) const;
	std::string getEditInput(std::string text) const;
	int getEditNumberInput(std::string text) const;
	void listAll() const;
	bool stillContinue;
	void saveAtEnd() const;
	void writeMenu() const;
	void find() const;
	void add();
	void deletePerson();
	void editPerson();
	void save() const;
	void printDelimeter() const;
public:
	App();
	~App();
	void run();
};