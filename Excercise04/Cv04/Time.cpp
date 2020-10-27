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
	if (hour > 23 | hour < 0 || minute > 59 || minute < 0 || second >59 || second<0) {
		throw new std::exception("Invalid time");
	}
	_hours = hour;
	_minutes = minute;
	_seconds = second;
}

Time::~Time()
{
}


int Time::compareTo(IComparable* obj) const
{
	if (obj == nullptr) {
		throw new std::exception("Null object");
	}

	Time* time = static_cast<Time*>(obj);
	if (time == nullptr) {
		throw new std::exception("Null object");
	}
	if (this->_hours == time->_hours && this->_minutes == time->_minutes && this->_seconds == time->_seconds)
		return 0;

	if (this->_hours > time->_hours || (this->_hours == time->_hours && this->_minutes > time->_minutes) ||
		(this->_hours == time->_hours && this->_minutes == time->_minutes && this->_seconds > time->_seconds))
		return 1;

	return -1;
}


std::string Time::toString() const
{
	std::string h = std::to_string(this->_hours);
	std::string m = std::to_string(this->_minutes);
	std::string s = std::to_string(this->_seconds);
	if (this->_minutes < 10)
		m = "0" + std::to_string(this->_minutes);
	if(this->_hours < 10)
		h = "0" + std::to_string(this->_hours);
	if (this->_seconds < 10)
		s = "0" + std::to_string(this->_seconds);

	return h+':'+m+':'+s;
}
