#include "APipe.h"
#include <string>
#include <iostream>	
#include <fstream>


int main() {
	std::string line;
	int size;
	std::string file = "pipe.txt";
	std::ifstream in(file);
	if (in.is_open()) {
		std::getline(in, line);
		size = stoi(line);
		Pipe* pipe = new Pipe(size);
		for (int i = 0; i < size; i++) {
			std::getline(in, line);
			for (int j = 0; j < size; j++) {
				char c = line.at(j);
				Tube* newTube = nullptr;
				switch (c) {
				case '-':
					newTube = new Tube(i, j, EAST_WEST);
					break;
				case 'I':
					newTube = new Tube(i, j, NORTH_SOUTH);
					break;
				case '+':
					newTube = new  Tube(i, j, NORTH_SOUTH_EAST_WEST);
					break;
				case 'O':
					newTube = new  Tube(i, j, END);
					break;
				case 'T':
					newTube = new  Tube(i, j, SOUTH_EAST_WEST);
					break;
				case ' ':
					newTube = new Tube(i, j, EMPTY);
					break;
				}
				pipe->addTube(i,j,newTube);
			}

		}
		std::cout << pipe->isPipeOk() << std::endl;
		in.close();
	}
	else {
		std::cout << "Unable to open file" << std::endl;
	}

}