#pragma once
#ifndef ADDRES_H
#define ADDRES_H
#include <string>
#include <iostream>

struct Address {
	std::string street;
	std::string city;
	int ZIP_code;
	Address(std::string street, std::string city, int zip);
	Address();
	~Address();
	std::string GetStreet() const;
	std::string GetCity() const;
	int GetZip() const;
	void SetStreet(std::string street);
	void SetCity(std::string city);
	void SetZip(int zip);
	friend std::ostream& operator<<(std::ostream& os, const Address& o);
	friend std::istream& operator>>(std::istream& is, Address& o);

};

#endif // !ADDRES_H

