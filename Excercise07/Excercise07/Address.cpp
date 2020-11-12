#include "Address.h"
#include <string>
#include <iostream>


using namespace std;

Address::Address(std::string street, std::string city, int zip)
{
	this->street = street;
	this->city = city;
	this->ZIP_code = zip;
}

Address::Address()
{
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

	int Address::GetZip() const
	{
		return this->ZIP_code;
	}

	void Address::SetStreet(std::string street)
	{
		this->street = street;
	}

	void Address::SetCity(std::string city)
	{
		this->city = city;
	}

	void Address::SetZip(int zip)
	{
		this->ZIP_code = zip;
	}

	std::ostream& operator<<(std::ostream& os, const Address& o)
	{
		return os << o.GetStreet() << " " << o.GetCity() << " " << o.GetZip();
	}

	std::istream& operator>>(std::istream& is, Address& o)
	{
		return is >> o.street >> o.city >> o.ZIP_code;
	}
