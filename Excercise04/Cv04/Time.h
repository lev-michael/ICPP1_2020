#pragma once
#ifndef TIME_H
#define TIME_H
#include "IComparable.h"
#include <string>

struct Time : public IComparable {
public:
	Time();
	Time(int hour, int minute, int second);
	~Time();
	int compareTo(IComparable* obj) const override;
	std::string toString() const override;

private:
	int _hours;
	int _minutes;
	int _seconds;

};
#endif // !TIME_H

