#pragma once
#ifndef DATE_H
#define DATE_H
#include "IComparable.h"

struct Date : public IComparable {
public:
	Date();
	Date(int day, int month, int year);
	~Date();
	int compareTo(IComparable* obj) const override;
	std::string toString() const override;
	bool checkDay(int d, int m) const ;
	void SortArray(IComparable** array, int length) const;
private:
	int _day;
	int _month;
	int _year;
};

#endif // DATE_H
