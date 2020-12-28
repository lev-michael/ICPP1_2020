#pragma once
#ifndef DATE_H
#define DATE_H
#include <iostream>
#include <ostream>
#include <string>

class Date {
private:
	int _day;
	int _month;
	int _year;
	bool checkDay(int d, int m) const;
public:
	Date(int day, int month, int year);
	Date() = default;
	~Date();
	int GetDay() const;
	int GetMonth() const;
	int GetYear() const;
	void SetDay(int day);
	void SetMonth(int month);
	void SetYear(int year);
	std::string toString() const;

};

#endif // !DATE_H