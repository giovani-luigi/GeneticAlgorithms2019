#include <iostream>
#include "Population.h"

void runGenetics(
	int populationSize,			// number of the population
	int generationCount,		// how many times we will apply genetic operations
	int selectionRate,			// rate of selection *typically 30
	int mutationRate,
	const char* finalState){			// no. of gen. iter. to perform each mutation

	Population population(populationSize, finalState);
	
	cout << "Initial population: " << endl << population << endl;
	
	for (int i=0; i<generationCount; i++){
		Population selected = population.select(selectionRate);
		selected.add(population.reproduce(100 - selectionRate));
		population = selected;
		cout << "Generation " << i+1 << endl;
		cout << population << endl;
	}
	
	cout << "Done." << endl;
	
}

int main(int argc, char** argv) {
	
	runGenetics(20, 1000, 30, 5, "GIOVANI");	
	
	return 0;
}
