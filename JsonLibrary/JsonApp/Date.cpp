#include "Date.h"
#include <ostream>
#include <istream>
#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

Date::Date(int day, int month, int year)
{
	try {
		SetDay(day);
		SetMonth(month);
		SetYear(year);
	}
	catch (range_error e) {
		throw std::range_error(e.what());
	}
}


Date::~Date()
{
}

int Date::GetDay() const
{
	return _day;
}

int Date::GetMonth() const
{
	return _month;
}

int Date::GetYear() const
{
	return _year;
}

void Date::SetDay(int day)
{
	if (day < 1 || day > 31) {
		throw range_error("Invalid Birth day");
	}
	_day = day;
}

void Date::SetMonth(int month)
{
	if (month < 1 || month >12 || !checkDay(this->_day, month)) {
		throw range_error("Invalid Birth month");
	}	
	_month = month;
}

void Date::SetYear(int year)
{
	if (year < 1900 || year >2020) {
		throw range_error("Invalid Birth year");
	}
	_year = year;
}

string Date::toString() const
{
	string output = to_string(this->GetDay()) + ". " + to_string(this->GetMonth()) + ". " + to_string(this->GetYear());
	return output;
}

bool Date::checkDay(int d, int m) const {
	int maxDay = 0;
	switch (m)
	{
	case 2:
		maxDay = 28;
		break;
	case 4: case 6: case 9: case 11:
		maxDay = 30;
		break;
	default:
		maxDay = 31;
		break;
	}

	if (d < 1 || maxDay < d) {
		return false;
	}

	return true;
}