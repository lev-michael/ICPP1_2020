#pragma once
#ifndef DATE_H
#define DATE_H
#include <iostream>
#include <ostream>
#include <string>

struct Date {
	int _day;
	int _month;
	int _year;
	Date(int day, int month, int year);
	Date();
	~Date();
	int GetDay() const;
	int GetMonth() const;
	int GetYear() const;
	void SetDay(int day);
	void SetMonth(int month);
	void SetYear(int year);
	friend std::ostream& operator<<(std::ostream& os, const Date& o);
	friend std::istream& operator>>(std::istream& is, Date& d);
};

#endif // !DATE_H