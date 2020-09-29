#include <iostream>
#include "Car.h"


int main(int argc, char** argv) {
    std::cout << "Choose print count: ";
	int count;
	std::cin >> count;
	std::cout << std::endl;

	for (size_t i = 1; i < argc && i <= count; i++)
	{
		std::cout << argv[i] << std::endl;
	}
	Car car = Car();
	car.move();

	Car* car1 = (Car*)malloc(sizeof(Car));
	*car1 = Car();
	car1->move;
	free(car1);
	Car* car2 = new Car();
	car2->move;
	delete car2;

	return 0;
}