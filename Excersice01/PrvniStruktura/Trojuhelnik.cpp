#include "Trojuhelnik.h"

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

bool Trojuhelnik::lzeSestrojit(Trojuhelnik* t){
	if (t->a + t->b > t->c&& t->b + t->c > t->a&& t->a + t->c > t->b) {
		return true;
	}
	return false;
}

