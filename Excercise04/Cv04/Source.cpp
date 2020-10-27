#include "Time.h"
#include "Date.h"
#include "DateTime.h"
#include <iostream>
#define LENGTH 10
using namespace std;

void SortArray(IComparable** array, int length)
{
	IComparable* temp;
	for (size_t i = 0; i < length; i++) {
		for (size_t j = 0; j < length - i - 1; j++) {
			if (array[j]->compareTo(array[j + 1]) == 1) {
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
}

int main(int argv, char** argc) {	
	Time** times = new Time*[LENGTH];
	Date** dates = new Date * [LENGTH];
	DateTime** dateTimes = new DateTime * [LENGTH];
	for (size_t i = 0; i < LENGTH; i++)
	{
		times[i] = new Time(rand() % 12, rand() % 60, rand() % 60);
		dates[i] = new Date(rand() % 30 + 1, rand() % 12 + 1, rand() % 200 + 1900);
		dateTimes[i] = new DateTime(dates[i], times[i]);
	}
	SortArray((IComparable**) times, LENGTH);
	SortArray((IComparable**)dates, LENGTH);
	SortArray((IComparable**)dateTimes, LENGTH);

	cout << "Sorted time" << endl;
	for (size_t i = 0; i < LENGTH; i++)
	{
		cout << times[i]->toString() << endl;
	}
	cout << endl << "Sorted date" << endl;

	for (size_t i = 0; i < LENGTH; i++)
	{
		cout << dates[i]->toString() << endl;
	}
	cout << endl << "Sorted datetime" << endl;

	for (size_t i = 0; i < LENGTH; i++)
	{
		cout << dateTimes[i]->toString() << endl;
	}


	delete dates;
	delete times;
	delete dateTimes;

	
	return 0;
}

