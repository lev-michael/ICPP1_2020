#include "DateTime.h"

DateTime::DateTime()
{
	this->_date = Date{};
	this->_time = Time{};
}

DateTime::DateTime(Date* date, Time* time)
{
	this->_date = *date;
	this->_time = *time;
}

DateTime::~DateTime()
{
	delete &this->_date;
	delete &this->_time;
}

int DateTime::compareTo(IComparable* obj) const
{	
	DateTime* dateTime = static_cast<DateTime*>(obj);
	if(dateTime == nullptr) {
		throw new std::exception("Null object");

	}
	int date = this->_date.compareTo((Date*) &dateTime->_date);
	int time = this->_time.compareTo((Time*) &dateTime->_time);
	if (date == 1 || (date == 0 && time == 1)) {
		return 1;
	} 
	if (date == 0 && time == 0) {
		return 0;
	}
	
	return -1;
}

void DateTime::SortArray(IComparable** array, int length) const
{
	DateTime** dateTimes = (DateTime**)array;
	DateTime* temp;
	for (size_t i = 0; i < length; i++) {
		for (size_t j = 0; j < length - i - 1; j++) {
			if (dateTimes[j]->compareTo(dateTimes[j + 1]) == 1) {
				temp = dateTimes[j];
				dateTimes[j] = dateTimes[j + 1];
				dateTimes[j + 1] = temp;
			}
		}
	}
}

std::string DateTime::toString() const
{
	return this->_date.toString() + " " + this->_time.toString();
}


