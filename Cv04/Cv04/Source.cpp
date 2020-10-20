#include "Time.h"
#include <iostream>
using namespace std;

int main(int argv, char** argc) {
	Time** times;
	Time t1{ 12, 20, 40 };
	Time *t2 = new Time( 10,50,20 );
	cout << t1.toString() << endl;
	cout << t2->toString() << endl;
	cout << t1.compareTo(t2) << endl;
	t1.SeraditPole()

	return 0;
}