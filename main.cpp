#include <iostream>
#include "Cromosome.h"

int main(int argc, char** argv) {
	
	std::cout << Cromosome("Giovani") << std::endl;
	
	Cromosome c1("ABC");
	Cromosome c2("ABCD");
	
	if (c1 < c2)
		std::cout << "c1 is < c2";
	
	return 0;
}
