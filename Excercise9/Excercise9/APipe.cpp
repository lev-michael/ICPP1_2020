#include "APipe.h"
#include <stdexcept>
#include <string>
#include <iostream>

Pipe::Pipe(const int size)
{
	this->size = size;
	matrix = new ATube **[size];
	for (int i = 0; i < size; i++) {
		matrix[i] = new ATube * [size];
	}
}

Pipe::~Pipe()
{
}

void Pipe::addTube(int x, int y, ATube* tube)
{
	if (tube->x > size || tube->x < 0 || tube->y < 0 || tube->y > size) {
		throw std::out_of_range("Input is out of range");
	}
	matrix[tube->x][tube->y] = tube;
}

const ATube* Pipe::getTube(int x, int y)
{
	if (size < x || size < y || x < 0 || y < 0) {
		throw std::out_of_range("Input is out of range");
	}
	return matrix[x][y];
}

bool Pipe::isPipeOk() const
{
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++)
		{
			if (matrix[i][j]->isValid(this) == false) {
				return false;
			}
		}
	}
	return true;
}

int Pipe::getSize() const
{
	return size;
}

void Pipe::toString() const
{
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++)
		{
			std::cout << matrix[i][j]->toString();
		}
	}
}

Tube::Tube(int x, int y, Type type)
{
	this->x = x;
	this->y = y;
	this->type = type;
}

Tube::~Tube()
{
}

bool Tube::isValid(const IPipe* pipe) const
{
	if (type == NORTH_SOUTH) {
		if (x == 0 || x == pipe->getSize() - 1) {
			return false;
		}
		Type above = pipe->getTube(x + 1, y)->getType();
		if (above == EMPTY) {
			return false;
		}
		Type under = pipe->getTube(x - 1, y)->getType();
		if (under == EMPTY) {
			return false;
		}
	}
	if (type == EAST_WEST) {
		if (y == 0 || y == pipe->getSize() - 1) {
			return false;
		}
		Type right = pipe->getTube(x, y + 1)->getType();
		if (right == EMPTY) {
			return false;
		}
		Type left = pipe->getTube(x, y - 1)->getType();
		if (left == EMPTY) {
			return false;
		}
	}

	if (type == NORTH_SOUTH_EAST_WEST) {
		if (y == 0 || y == pipe->getSize() - 1
			|| x == 0 || x == pipe->getSize() - 1) {
			return false;
		}
		Type right = pipe->getTube(x, y + 1)->getType();
		if (right == EMPTY) {
			return false;
		}
		Type left = pipe->getTube(x, y - 1)->getType();
		if (left == EMPTY) {
			return false;
		}
		Type above = pipe->getTube(x + 1, y)->getType();
		if (above == EMPTY) {
			return false;
		}
		Type under = pipe->getTube(x - 1, y)->getType();
		if (under == EMPTY) {
			return false;
		}
	}

	if (type == SOUTH_EAST_WEST) {
		if (y == 0 || y == pipe->getSize() - 1
			|| x == pipe->getSize() - 1) {
			return false;
		}
		Type right = pipe->getTube(x, y + 1)->getType();
		if (right == EMPTY) {
			return false;
		}
		Type left = pipe->getTube(x, y - 1)->getType();
		if (left == EMPTY) {
			return false;
		}
		Type under = pipe->getTube(x - 1, y)->getType();
		if (under == EMPTY) {
			return false;
		}
	}
	return true;
}

const Type Tube::getType() const
{
	return type;
}

char Tube::toString() const
{
	switch (type) {
	case NORTH_SOUTH:
		return 'I';
	case EAST_WEST:
		return '-';
	case NORTH_SOUTH_EAST_WEST:
		return '+';
	case SOUTH_EAST_WEST:
		return 'T';
	case EMPTY:
		return ' ';
	case END:
		return 'O';
	}
	return ' ';

}
