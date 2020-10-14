#include <iostream>
#include "Utils.h"

int main(int argc, char** argv) {
	std::cout << "sizeof(Base):" << sizeof(Base) << std::endl;
	std::cout << "sizeof(Advanced):" << sizeof(Advanced) << std::endl;
	std::cout << "sizeof(Advanced2):" << sizeof(Advanced2) << std::endl;
	
	Base base = Base();
	base.PrintMe();

	Advanced advanced = Advanced();
	advanced.PrintMe();

	Base* basePtr = new Base();
	basePtr->PrintMe();

	Advanced2* advanced2Ptr = new Advanced2();
	advanced2Ptr->PrintMe();
	std::cout << "advanced2Ptr:" << advanced2Ptr << std::endl;

	Base* advanced2PtrToBasePtr = advanced2Ptr;
	advanced2PtrToBasePtr->PrintMe();
	std::cout << "advanced2PtrToBasePtr:" << advanced2PtrToBasePtr << std::endl;

	delete advanced2PtrToBasePtr;

	return 0;
}