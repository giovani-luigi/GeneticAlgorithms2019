#ifndef CROMOSOME_H
#define CROMOSOME_H

#include <string>	// string
#include "Utils.h"	// generateWord()

using namespace std;

class Chromosome{

	public:
		
		// Field: 
		// relative fitness, i.e. (100 * fitness/total)
		int fitnessPct;
		
		// Constructor: Generates a chromosome from a random word,
		// using a given final state to calculate the fitness
		Chromosome(string finalState);
		
		// Constructor: Generates a chromosome from a given value,
		// using a given final state to calculate the fitness
		Chromosome(string value, string finalState);
		
		// triggers a mutation in a gene of this chromosome
		void mutate();
		
		// fitness getter
		int getFitness();
		
		// value getter
		string getValue();
		
		// override operator < to support sort()
		// we make it friend so we can access private class members
		friend bool operator < (const Chromosome& a, const Chromosome& b);
	
		// override operator == so we can compare equality
		// we make it friend so we can access private class members
		friend bool operator == (const Chromosome& a, const Chromosome& b);
		
		// override operator != so we can compare inequality
		// we make it friend so we can access private class members
		friend bool operator != (const Chromosome& a, const Chromosome& b);
		
		// override operator for ostream objects
		// we make it friend so we can access private class members
		friend ostream& operator<< (ostream& out, const Chromosome& c);
		
	private:
		
		string value;
		
		// the fitness of this particular chromosome
		int fitness;
		
		// member function to calculate a fitness score given 
		// a final state expected from the cromosome
		int calculateFitness(string finalState);

};

#endif
