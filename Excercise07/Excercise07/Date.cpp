#include "Date.h"
#include <ostream>
#include <istream>
#include <iostream>
#include <string>

Date::Date(int day, int month, int year)
{
	_day = day;
	_month = month;
	_year = year;
}

Date::Date()
{
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
	_day = day;
}

void Date::SetMonth(int month)
{
	_month = month;
}

void Date::SetYear(int year)
{
	_year = year;
}

std::ostream& operator<<(std::ostream& os, const Date& o)
{
	return os << o.GetDay() << ". " << o.GetMonth() << ". " << o.GetYear();
}

std::istream& operator>>(std::istream& is, Date& d)
{
	char c;
	is >> d._day >> c >> d._month >> c >> d._year;
	return is;
}
