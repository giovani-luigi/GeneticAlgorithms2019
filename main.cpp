#include <iostream>
#include "Chromosome.h"

int main(int argc, char** argv) {
	
	std::cout << Chromosome("Giovani") << std::endl;
	
	Chromosome c1("ABC");
	Chromosome c2("ABCD");
	
	if (c1 < c2)
		std::cout << "c1 is < c2";
	
	return 0;
}
