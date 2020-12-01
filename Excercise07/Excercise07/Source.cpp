#include "Person.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

Person* loadBin() {
	int i = 0;
	int size = 0;
	Person p;
	Person* persons;
	ifstream in{};
	in.open("output.bin", ios_base::binary);
	if (in.is_open()) {
		in.seekg(0, ios::end);
		size = in.tellg()/sizeof(p);
		in.seekg(0, ios::beg);
		persons = new Person[size];
		for (size_t i = 0; i < size; i++)
		{
			in.read((char*)(&p), sizeof(p));
			persons[i] = p;
			cout << p << endl;
		}
		in.close();
		return persons;
	}
	return nullptr;
}

void saveBin() {
	Person array[5];

	for (size_t i = 0; i < 5; i++)
	{
		int num = (i + 2) * 3;
		Date d{ num, 10, 2010-num };
		Address a{ "Hlavni", "Praha", 11100 + num };
		Person p{ "Jan","Novak", a,d };
		array[i] = p;
	}

	ofstream out{};
	out.open("output.bin", ios_base::out | ios_base::binary);
	if (out.is_open()) {
		out.write((const char*)&array, sizeof(array));
		out.close();
	}
}

void uloz() {
	Person array[5];
	
	for (size_t i = 0; i < 5; i++)
	{
		Date d{ 1, 10, 2010 };
		Address a{ "Hlavni", "Praha", 11100 + 2 };
		Person p{ "Jan","Novak", a,d };
		array[i] = p;
	}

	ofstream out{};
	out.open("output.txt");
	if(out.is_open()){
		for (size_t i = 0; i < 5; i++)
		{
			out << array[i];
			out << endl;
		}	
		out.close();
		}
}

Person* nacti() {
	Person p{};
	ifstream in{};
	int size = 0;
	string line;
	Person* persons;
	in.open("output.txt");
	if(in.is_open())
	{
		while (getline(in, line)) {
			++size;
		}
		persons = new Person[size];
		in.clear();
		in.seekg(0);

		for (size_t i = 0; i < size; i++)
		{
			in >> p;
			persons[i] = p;
			cout << p << endl;
		}
		in.close();
		return persons;
	}
	else {
		cerr << "Nepodarilo se otevrit soubor" << endl;
	}
	return nullptr;
}



int main(int argc, char** argv) {
	uloz();
	Person* p = nacti();
	cout << "binarni soubor" << endl;
	saveBin();
	loadBin();
	return 0;
}

