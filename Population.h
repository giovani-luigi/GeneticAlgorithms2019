#ifndef POPULATION_H
#define POPULATION_H

#include "Chromosome.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Population{
	
	public:
		
		// Generates a population with a given size
		Population(int size, string finalState);
		
		// sort the population (by fitness)
		void sort();
		
		// creates a new population based in a selection rate
		//  - ratePct: the rate to select. e.g. 30 (30%)
		void select(int ratePct);
		
		// triggers a reproduction in the current population
		//  - ratePct: the rate to reproduce. e.g. 70 (70%)
		void reproduce(int ratePct);
		
		// triggers a mutation in the current population
		void mutate();
		
		// override operator for ostream objects
		// we make it friend so we can access private class members
		friend ostream& operator<< (ostream& out, const Population& p);
		
	private:
		
		string finalState;

		vector<Chromosome> chromosomes;
	
};

#endif
