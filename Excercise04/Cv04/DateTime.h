#pragma once
#ifndef DATE_TIME_H
#define DATE_TIME_H
#include "Date.h"
#include "Time.h"
#include "IComparable.h"

struct DateTime : public IComparable {
private:
	Date _date;
	Time _time;
public:
	DateTime();
	DateTime(Date* date, Time* time);
	~DateTime();
	int compareTo(IComparable* obj) const override;
	std::string toString() const override;
};
#endif // DATE_TIME_H

