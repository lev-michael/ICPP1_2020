#ifndef CONTAINER_H
#define CONTAINER_H
#include <stdexcept>

template<typename DataType, int startValue, int risingCoefficient = 2>
class IncreasingContainer {
	DataType* _array;
	unsigned _length;
	unsigned _counterValidElemnt;
public:
	IncreasingContainer();
	~IncreasingContainer();
	bool isArrayNotFull() const;
	void increaseArray();
	void add(const DataType& o);
	DataType& operator[](int index);
	DataType operator[](int index) const;
	unsigned int count() const;
};

#endif // !CONTAINER_H

template<typename DataType, int startValue, int risingCoefficient>
inline IncreasingContainer<DataType, startValue, risingCoefficient>::IncreasingContainer()
{
	this->_length = startValue;
	this->_counterValidElemnt = 0;
	this->_array = new DataType[_length];
}

template<typename DataType, int startValue, int risingCoefficient>
inline IncreasingContainer<DataType, startValue, risingCoefficient>::~IncreasingContainer()
{
	delete [] _array;
}

template<typename DataType, int startValue, int risingCoefficient>
inline bool IncreasingContainer<DataType, startValue, risingCoefficient>::isArrayNotFull() const
{
	return _counterValidElemnt < _length;
}

template<typename DataType, int startValue, int risingCoefficient>
inline void IncreasingContainer<DataType, startValue, risingCoefficient>::increaseArray()
{
	_length = _length * risingCoefficient;
	DataType* newArray = new DataType[_length];
	for (size_t i = 0; i < _counterValidElemnt; i++)
	{
		newArray[i] = _array[i];
	}
	delete [] _array;
	_array = newArray;
}

template<typename DataType, int startValue, int risingCoefficient>
inline void IncreasingContainer<DataType, startValue, risingCoefficient>::add(const DataType& o)
{
	if (isArrayNotFull()) {
		_array[_counterValidElemnt++] = o;
	}
	else {
		increaseArray();
		_array[_counterValidElemnt++] = o;
	}
}

template<typename DataType, int startValue, int risingCoefficient>
inline DataType& IncreasingContainer<DataType, startValue, risingCoefficient>::operator[](int index)
{
	if (index < 0 || index > this->_counterValidElemnt) {
		throw std::invalid_argument("Invalid index");
	}
	return _array[index];

}

template<typename DataType, int startValue, int risingCoefficient>
inline DataType IncreasingContainer<DataType, startValue, risingCoefficient>::operator[](int index) const
{
	if (index < 0 || index > this->_counterValidElemnt) {
		throw std::invalid_argument("Invalid index");
	}
	return _array[index];
}

template<typename DataType, int startValue, int risingCoefficient>
inline unsigned int IncreasingContainer<DataType, startValue, risingCoefficient>::count() const
{
	return this->_counterValidElemnt;
}
