#include <iostream>
#include "Trojuhelnik.h"

int main(int argc, char** argv) {
	int count;
	std::cout << "Zadejte pocet trojuhelniku: ";
	std::cin >> count;
	if (count > 0) {
		Trojuhelnik** t = new Trojuhelnik*[count];
		for (size_t i = 0; i < count; i++)
		{
			std::cout << std::endl << i + 1 << ". trojuhelnik" << std::endl;
			t[i] = new Trojuhelnik();
			if (t[i]->lzeSestrojit()) {
				std::cout << "Obvod " << i+1 <<". trojuhelniku: "<< t[i]->getObvod() << std::endl;
			}
			else {
				std::cout << i + 1 << ". trojuhelnik Nelze sestrojit" << std::endl;
			}
		}

		for (size_t i = 0; i < count; i++)
		{
			delete t[i];
		}
		delete t;
	}


	
	return 0;
}
