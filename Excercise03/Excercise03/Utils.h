#pragma once
#ifndef UTILS_H
#define UTILS_H
#include <iostream>


class Base {
	int id;
public: 
	virtual ~Base() {

	}

	virtual void PrintMe() const {
		std::cout << "Base" << std::endl;
	}
};

class Advanced : public Base {
public: 
	void PrintMe() const {
		std::cout << "Advanced" << std::endl;
	}
};

class Advanced2 : public Base {
	int id2;
	int* id3;
public:
	Advanced2() {
		id3 = new int(0);
	}

	Advanced2(const Advanced2& src) {
		id3 = new int(*src.id3);
	}

	~Advanced2() {
		delete id3;
	}

	void PrintMe() const {
		std::cout << "Advanced2" << std::endl;
	}
	
};







#endif 
