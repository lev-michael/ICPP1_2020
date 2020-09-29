#include <iostream>

struct Trojuhelnik {
	int a, b, c;  
};

bool lzeSestrojit(Trojuhelnik t) {
	if (t.a + t.b > t.c && t.b + t.c > t.a && t.a + t.c > t.b) {
		return true;
	}
	return false;
}

bool lzeSestrojit(Trojuhelnik* t) {
	if (t->a + t->b > t->c && t->b + t->c > t->a && t->a + t->c > t->b) {
		return true;
	}
	return false;
}

int main(int argc, char** argv) {

	Trojuhelnik t1;
	std::cout << "Zadejte stranu a: ";
	std::cin >> t1.a;
	std::cout << std::endl;
	std::cout << "Zadejte stranu b: ";
	std::cin >> t1.b;
	std::cout << std::endl;
	std::cout << "Zadejte stranu c: ";
	std::cin >> t1.c;
	std::cout << std::endl;

	if (lzeSestrojit(t1)) {
		std::cout << "Obvod: " << t1.a + t1.b + t1.c;
	}
	else {
		std::cout << "Nelze sestrojit";
	}

	//Ukol 3
	Trojuhelnik* t2;
	std::cout << "Zadejte stranu a: ";
	std::cin >> t2->a;
	std::cout << std::endl;
	std::cout << "Zadejte stranu b: ";
	std::cin >> t2->b;
	std::cout << std::endl;
	std::cout << "Zadejte stranu c: ";
	std::cin >> t2->c;
	std::cout << std::endl;

	if (lzeSestrojit(t2)) {
		std::cout << "Obvod: " << t2->a + t2->b + t2->c;
	}
	else {
		std::cout << "Nelze sestrojit";
	}

	return 0;
}