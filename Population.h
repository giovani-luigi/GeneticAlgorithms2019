#ifndef POPULATION_H
#define POPULATION_H

#include "Chromosome.h"
#include <iostream>

using namespace std;

class Population{
	
	public:
		
		// Generates a population with a given size
		Population(int size);
		
		// sort the population (by fitness)
		void sort();
		
		// creates a new population based in a selection rate
		void select();
		
		// triggers a reproduction in the current population
		void reproduce();
		
		// triggers a mutation in the current population
		void mutate();
		
		// override operator for ostream objects
		// we make it friend so we can access private class members
		friend ostream& operator<< (ostream& out, const Population& p);
		
	private:
		
		vector<Chromosome> chromosomes;
	
};

#endif
