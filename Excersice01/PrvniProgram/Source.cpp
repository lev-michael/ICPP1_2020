#include <iostream>


int main(int argc, char** argv) {
	int a,b,c;
	std::cout << "Zadejte stranu a: ";
	std::cin >> a;
	std::cout << std::endl;
	std::cout << "Zadejte stranu b: ";
	std::cin >> b;
	std::cout << std::endl;
	std::cout << "Zadejte stranu c: ";
	std::cin >> c;
	std::cout << std::endl;

	if (a + b > c && a + c > b && b + c > a) {
		std::cout << "obvod: " << a + b + c;
	}
	else {
		std::cout << "nelze sestrojit";
	}

	return 0;
}