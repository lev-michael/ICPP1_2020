#include "Time.h"
#include<iostream>


Time::Time()
{
	this->_hours = 0;
	this->_minutes = 0;
	this->_seconds = 0;
}

Time::Time(int hour, int minute, int second)
{
	if (hour < 24 && hour >= 0) {
		this->_hours = hour;
	}
	else {
		this->_hours = 0;
	}
	if (minute < 60 && minute >= 0) {
		this->_minutes = minute;
	}
	else {
		this->_minutes = 0;
	}
	if (second < 60 && second >= 0) {
		this->_seconds = second;
	}
	else {
		this->_seconds = 0;
	}
}

int Time::compareTo(IComparable* obj) const
{
	Time* time = static_cast<Time*>(obj);
	if (this->_hours == time->_hours && this->_minutes == time->_minutes && this->_seconds == time->_seconds)
		return 0;

	if (this->_hours > time->_hours || (this->_hours == time->_hours && this->_minutes > time->_minutes) ||
		(this->_hours == time->_hours && this->_minutes == time->_minutes && this->_seconds>time->_seconds))
		return 1;

	return -1;
}

void Time::SeraditPole(IComparable** pole, int velikostPole)
{
	Time* times = dynamic_cast<Time*>(*pole);
	int = 1;
}

std::string Time::toString() const
{	
	return std::to_string(this->_hours) + ':' + std::to_string(this->_minutes) + ':' + std::to_string(this->_seconds);
}
