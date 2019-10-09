#include <iostream>
#include "Population.h"

void runGenetics(
	int populationSize,			// number of the population
	int generationCount,		// how many times we will apply genetic operations
	int selectionRate,			// rate of selection *typically 30
	int mutationRate,
	const char* finalState){			// no. of gen. iter. to perform each mutation

	Population p(populationSize, finalState);
		
	cout << "Initial population: " << endl << p << endl;
	
	p.select(selectionRate);
	
	p.reproduce(100 - selectionRate);
	
	cout << "Selected chromosomes: " << endl << p;
	
}


int main(int argc, char** argv) {
	
	runGenetics(10, 1000, 30, 5, "Giovani");	
	
	return 0;
}
