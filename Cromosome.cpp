#include "Cromosome.h"

// default ctor
Cromosome::Cromosome(string finalState){	
	this->value = Utils::generateWord(finalState.size());
	this->fitness = calculateFitness(finalState);
}

Cromosome::calculateFitness(string finalState){
	return this->value.size();
}

// support for < operator
bool operator < (const Cromosome& a, const Cromosome& b){
	return a.fitness < b.fitness;
}

// support for 'output operator'
ostream& operator<< (ostream& out, const Cromosome& c){
	out << "Cromosome \"" << c.value << "\" (fitness=" << c.fitness << ")";
}
