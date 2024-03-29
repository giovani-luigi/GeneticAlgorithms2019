#ifndef POPULATION_H
#define POPULATION_H

#include "Chromosome.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

class Population{
	
	public:
		
		// Initialized a poppulation from a given group of chromosomes
		Population(vector<Chromosome> chromosomes, string finalState);
		
		// Generates a population with a given size
		Population(int size, string finalState);
		
		// add the chromosomes from other population to this
		void add(Population other);
		
		// trim the population to a maximum value
		void trim(int max);
		
		// sort the population (by fitness)
		void sort();
		
		// returns the number of chromosomes in the population
		int size();
		
		// creates a new population based in a selection rate
		//  - ratePct: the rate to select. e.g. 30 (30%)
		//  - elitism: when true, the last item (best fit if sorted) will be always included
		//  - return: the selected population
		Population select(int ratePct, bool elitism);
		
		// triggers a reproduction in the current population
		//  - ratePct: the rate to reproduce. e.g. 70 (70%)
		//  - return: the reproduced population
		Population reproduce(int ratePct);
		
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
