#include "Trojuhelnik.h"
#include <iostream>

Trojuhelnik::Trojuhelnik()
{
	std::cout << "Zadejte stranu a: ";
	std::cin >> a;
	std::cout << std::endl;
	std::cout << "Zadejte stranu b: ";
	std::cin >> b;
	std::cout << std::endl;
	std::cout << "Zadejte stranu c: ";
	std::cin >> c;
	std::cout << std::endl;
}

bool Trojuhelnik::lzeSestrojit() {
	if (a + b > c && b + c > a && a + c > b) {
		return true;
	}
	return false;
}

int Trojuhelnik::getObvod()
{
	if (lzeSestrojit()) {
		return a + b + c;
	} return 0;
}

