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

int main(int argc, char** argv) {
	Trojuhelnik t;
	std::cout << "Zadejte stranu a: ";
	std::cin >> t.a;
	std::cout << std::endl;
	std::cout << "Zadejte stranu b: ";
	std::cin >> t.b;
	std::cout << std::endl;
	std::cout << "Zadejte stranu c: ";
	std::cin >> t.c;
	std::cout << std::endl;

	if (lzeSestrojit(t)) {
		std::cout << "Obvod: " << t.a + t.b + t.c;
	}
	else {
		std::cout << "Nelze sestrojit";
	}

	return 0;
}