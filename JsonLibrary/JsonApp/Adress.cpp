#include "Address.h"
#include <string>
#include <iostream>
#include "Address.h"

using namespace std;

Address::Address(std::string street, int houseNum, std::string city, std::string zip)
{
	this->street = street;
	this->city = city;
	this->zip = zip;
	this->houseNumber = houseNum;
}


Address::~Address()
{
}

std::string Address::GetStreet() const
{
	return this->street;
}

std::string Address::GetCity() const
{
	return this->city;
}

std::string Address::GetZip() const
{
	return this->zip;
}

int Address::getHouseNum() const
{
	return this->houseNumber;
}

void Address::SetStreet(std::string street)
{
	this->street = street;
}

void Address::SetCity(std::string city)
{
	this->city = city;
}

void Address::SetZip(std::string zip)
{
	this->zip = zip;
}

void Address::setHouseNum(int num)
{
	this->houseNumber = num;
}

string Address::toString() const
{
	return this->street + " " + to_string(this->houseNumber) + " " + this->city + " " + this->zip;
}
