#include <iostream>
#include "Population.h"

void runGenetics(
	int populationSize,			// number of the population
	int generationCount,		// how many times we will apply genetic operations
	int selectionRate,			// rate of selection *typically 30
	int mutationRate,			// no. of gen. iter. to perform each mutation
	bool elitism,
	const char* finalState){			

	Population population(populationSize, finalState);
	
	cout << "Initial population: " << endl << population << endl;
	
	for (int i=0; i<generationCount; i++){

		if (i % mutationRate == 0)
			population.mutate();
		
		population.sort();
		Population selected = population.select(selectionRate, true);
		selected.add(population.reproduce(100 - selectionRate));
		selected.trim(populationSize);
		population = selected;
		cout << "Generation " << i+1 << " with population count=" << population.size() << endl;
		cout << population << endl;
	}
	
	cout << "Done." << endl;
	
}

int main(int argc, char** argv) {
	
	runGenetics(20, 1000, 30, 20, true, "GIOVANI");
	
	return 0;
}
