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
		throw new std::exception("Invalid time");
	}
	if (minute < 60 && minute >= 0) {
		this->_minutes = minute;
	}
	else {
		throw new std::exception("Invalid time");
	}
	if (second < 60 && second >= 0) {
		this->_seconds = second;
	}
	else {
		throw new std::exception("Invalid time");
	}
}

Time::~Time()
{
}


int Time::compareTo(IComparable* obj) const
{
	Time* time = static_cast<Time*>(obj);
	if (time == nullptr) {
		throw new std::exception("Null object");
	}
	if (this->_hours == time->_hours && this->_minutes == time->_minutes && this->_seconds == time->_seconds)
		return 0;

	if (this->_hours > time->_hours || (this->_hours >= time->_hours && this->_minutes > time->_minutes) ||
		(this->_hours >= time->_hours && this->_minutes >= time->_minutes && this->_seconds > time->_seconds))
		return 1;

	return -1;
}

void Time::SortArray(IComparable** array, int length)
{
	Time** times =(Time**) array;
	Time* temp;
	for (size_t i = 0; i < length; i++){
		for (size_t j = 0; j < length-i-1; j++){
			if (times[j]->compareTo(times[j+1])== 1) {
				temp = times[j];
				times[j] = times[j + 1];
				times[j + 1] = temp;
			}
		}
	}
	array = (IComparable**) times;
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
