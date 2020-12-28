#pragma once
#ifndef ADDRES_H
#define ADDRES_H
#include <string>
#include <iostream>

class Address {
private:
	std::string street;
	int houseNumber;
	std::string city;
	std::string zip;
public:
	Address(std::string street, int houseNum, std::string city, std::string zip);
	Address() = default;
	~Address();
	std::string GetStreet() const;
	std::string GetCity() const;
	std::string GetZip() const;
	int getHouseNum() const;
	void SetStreet(std::string street);
	void SetCity(std::string city);
	void SetZip(std::string zip);
	void setHouseNum(int num);
	std::string toString() const;
};

#endif // !ADDRES_H