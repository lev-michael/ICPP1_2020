#pragma once
#ifndef MATRIX_H
#define MATRIX_H
#include <stdexcept>
#include <iostream>


using namespace std;

template<typename T>
class Matrix {
private:
	T** matrix;
	int columns;
	int rows;
public: 
	Matrix(int cols, int rows);
	Matrix(const Matrix<T>& m);
	~Matrix();
	void SetValue(int col, int row, T value);
	void SetFromArray(T* arr);
	T& GetValue(int col, int row);
	const T& GetValue(int col, int row) const;
	Matrix<T> Transpose() const;
	Matrix<T> Multiply(const Matrix& m) const;
	Matrix<T> Multiply(T scalar) const;
	Matrix<T> Sum(const Matrix& m) const;
	Matrix<T> Sum(T scalar) const;
	bool Equals(const Matrix& m) const;
	void toString() const;
	template<typename R>
	Matrix<R> Cast() const;
};

template<typename T>
 Matrix<T>::Matrix(int cols, int rows)
{
	if (cols < 0 || rows <0) {
		 throw invalid_argument("Invalid size of matrix");
	}
	this->rows = rows;
	columns = cols;

	matrix = new T*[rows];
	for (size_t i = 0; i < rows; i++)
	{
		matrix[i] = new T[columns];
	}
}

template<typename T>
 Matrix<T>::Matrix(const Matrix<T>& m)
{
	columns = m.columns;
	rows = m.rows;
	T** newMatrix = new T *[m.rows];
	for (size_t i = 0; i < m.rows; i++)
	{
		newMatrix[i] = new T[m.columns];
		for (size_t j = 0; j < m.columns; j++)
		{
			newMatrix[i][j] = m.GetValue(i, j);
		}
	}
	matrix = newMatrix	;
}

template<typename T>
 Matrix<T>::~Matrix()
{
	for (size_t i = 0; i < columns; i++)
	{
		delete[] matrix[i];
	}
	delete matrix;
}

template<typename T>
 void Matrix<T>::SetValue(int col, int row, T value)
{
	if (col < 0 || col > columns || row<0 || row>rows) {
		throw invalid_argument("Invalid size of matrix");
	}
	matrix[row][col] = value;
}

template<typename T>
 void Matrix<T>::SetFromArray(T* arr)
{
	int arraySize = 0;
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < columns; j++)
		{
			matrix[i][j] = arr[arraySize++];
		}
	}
}

template<typename T>
T& Matrix<T>::GetValue(int col, int row)
{
	if (col < 0 || col > columns || row<0 || row>rows) {
		throw invalid_argument("Invalid size of matrix");
	}
	return matrix[row][col];
}
	
template<typename T>
const T& Matrix<T>::GetValue(int col, int row) const
{
	if (col < 0 || col > columns || row<0 || row>rows) {
		throw invalid_argument("Invalid size of matrix");
	}
	return matrix[row][col];
}

template<typename T>
Matrix<T> Matrix<T>::Transpose() const
{
	Matrix<T> m{columns, rows};
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < columns; j++)
		{
			m.SetValue(j,i, matrix[i][j]);
		}
	}
	return m;
}



template<typename T>
Matrix<T> Matrix<T>::Multiply(const Matrix& m) const
{
	if (columns != m.rows) {
		throw invalid_argument("Invalid size of Matrix. Number of columns in first matrix must be same as number of rows in second matrix.");
	}
	Matrix mltp{ rows, columns };
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < columns; j++)
		{
			mltp.matrix[i][j] = 0;
			for (size_t k = 0; k < columns; k++)
			{
				mltp.matrix[i][j] += matrix[i][k] * m.matrix[k][j];
			}
		}
	}
	return mltp;
}

template<typename T>
Matrix<T> Matrix<T>::Multiply(T scalar) const
{
	Matrix<T> m{ rows, columns };
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < columns; j++)
		{
			m.matrix[i][j] = matrix[i][j]*scalar;
		}
	}
	return m;
}

template<typename T>
Matrix<T> Matrix<T>::Sum(const Matrix& m) const
{
	if (columns != m.columns || rows != m.rows) {
		throw invalid_argument("Rows and columns must be equal");
	}
	Matrix<T> sum{ rows, columns };
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < columns; j++)
		{
			sum.matrix[i][j] = m[i][j] + matrix[i][j];
		}
	}
	return sum;	
}

template<typename T>
Matrix<T> Matrix<T>::Sum(T scalar) const
{
	Matrix<T> m{ rows, columns };
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < columns; j++)
		{
			m.SetValue(i,j, matrix[i][j] + scalar);
		}
	}
	return m;
}

template<typename T>
bool Matrix<T>::Equals(const Matrix& m) const
{
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < columns; j++)
		{
			if (matrix[i][j] != m.GetValue(i, j)) {
				return false;
			}
		}
	}
	return true;
}

template<typename T>
void Matrix<T>::toString() const
{
	for (size_t i = 0; i < this->rows; i++)
	{
		for (size_t j = 0; j < this->columns; j++)
		{
			cout << matrix[i][j] << " ";
		}
		
		cout << endl;
	}
	cout << endl;
}

template<typename T>
template<typename R>
Matrix<R> Matrix<T>::Cast() const
{
	Matrix<R> m{ rows, columns };
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < columns; j++)
		{
			m.SetValue(i, j, static_cast<R>(matrix[i][j]));
		}
	}
	return m;
}

#endif