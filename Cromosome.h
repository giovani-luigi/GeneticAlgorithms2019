#ifndef CROMOSOME_H
#define CROMOSOME_H

#include <string>	// string
#include "Utils.h"	// generateWord()

using namespace std;

class Cromosome{

	public:
		
		// Constructor: Generates a cromosome from a random word,
		// using a given final state to calculate the fitness
		Cromosome(string finalState);
		
		// override operator < to support sort()
		// we make it friend so we can access private class members
		friend bool operator < (const Cromosome& a, const Cromosome& b);
		
		// override operator for ostream objects
		// we make it friend so we can access private class members
		friend ostream& operator<< (ostream& out, const Cromosome& c);
		
	private:
		
		string value;
		int fitness;
		
		// member function to calculate a fitness score given 
		// a final state expected from the cromosome
		calculateFitness(string finalState);

};

#endif
