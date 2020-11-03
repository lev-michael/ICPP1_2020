#include "increasingContainer.h"
#include <iostream>
#include <string>

int main(int argc, char** argv) {
	IncreasingContainer<std::string, 5> container = IncreasingContainer<std::string, 5>();
	for (size_t i = 0; i < 10; i++)
	{
		container.add("ahoj");
		std::cout <<"pocet: "<< container.count() << std::endl;
		std::cout <<"je misto: " << container.isArrayNotFull() << std::endl;
	}
	


	return 0;
}