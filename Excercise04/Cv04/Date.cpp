#include "Date.h"
#include "IComparable.h"


Date::Date()
{
	this->_day = 1;
	this->_month = 1;
	this->_year = 1900;
}

Date::Date(int day, int month, int year)
{
	if (month <= 12 && month > 0) {
		this->_month = month;
	}
	else {
		throw new std::exception("Invalid date");
	}
	if (checkDay(day,month)) {
		this->_day = day;
	}
	else {
		throw new std::exception("Invalid time");
	}
	this->_year = year;
}

Date::~Date()
{
}


int Date::compareTo(IComparable* obj) const 
{
	Date* date = static_cast<Date*>(obj);
	if (date==nullptr) {
		throw new std::exception("Null object");
	}
	if (this->_year == date->_year && this->_month == date->_month && this->_day == date->_day)
		return 0;

	if (this->_year > date->_year || (this->_year >= date->_year && this->_month > date->_month) ||
		(this->_year >= date->_year && this->_month >= date->_month && this->_day > date->_day))
		return 1;

	return -1;
}

std::string Date::toString() const 
{
	std::string y = std::to_string(this->_year);
	std::string m = std::to_string(this->_month);
	std::string d = std::to_string(this->_day);
	if (this->_month < 10)
		m = "0" + std::to_string(this->_month);
	if (this->_day < 10)
		d = "0" + std::to_string(this->_day);

	return d + '.' + m + '.' + y;
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

void Date::SortArray(IComparable** array, int length) const
{
	Date** dates = (Date**)array;
	Date* temp;
	for (size_t i = 0; i < length; i++) {
		for (size_t j = 0; j < length - i - 1; j++) {
			if (dates[j]->compareTo(dates[j + 1]) == 1) {
				temp = dates[j];
				dates[j] = dates[j + 1];
				dates[j + 1] = temp;
			}
		}
	}
	array = (IComparable**)dates;
}
