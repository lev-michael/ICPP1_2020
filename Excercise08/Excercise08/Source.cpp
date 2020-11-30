#include "Matrix.h"
#include <iostream>

using namespace std;


int main(int argc, char** argv) {
	Matrix<int> m{ 3,3 };
	int arr[] = { 0,1,2,3,4,5,6,7,8 };
	m.SetFromArray(arr);
	cout << "m:" << endl;
	m.toString();

	Matrix<int> mt = m.Transpose();
	cout << "Transposed m => mt:" << endl;
	mt.toString();

	Matrix<int> mmt = m.Multiply(mt);
	cout << "m*mt => mmt:" << endl;
	mmt.toString();

	Matrix<double> mmt_d = mmt.Cast<double>();
	cout << "mmt_double:" << endl;
	mmt_d.toString();

	Matrix<double> n_d{ 3,3 };
	double jednodpole_d[] = { 4.5,5,0,2,-0.5,7,1.5,9,6 };
	n_d.SetFromArray(jednodpole_d);
	cout << "n_double:" << endl;
	n_d.toString();

	Matrix<double> mmtn_d = mmt_d.Multiply(n_d);
	cout << "mmt_double * n_double:" << endl;
	mmtn_d.toString();

	Matrix<int> r = mmtn_d.Cast<int>();
	cout << "r:" << endl;
	r.toString();

	Matrix<int> t{ 3,3 };
	int tpole[] = { 85,225,236,292,819,866,499,1413,1496 };
	t.SetFromArray(tpole);
	cout << "t:" << endl;
	t.toString();

	std::cout << "r==t ? " << (r.Equals(t) ? "true" : "false") << std::endl;


	return 0;
}