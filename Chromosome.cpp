#include "Chromosome.h"

// default ctor
Chromosome::Chromosome(string finalState){	
	this->value = Utils::generateWord(finalState.size());
	this->fitness = calculateFitness(finalState);
}

Chromosome::calculateFitness(string finalState){
	return this->value.size();
}

// support for < operator
bool operator < (const Chromosome& a, const Chromosome& b){
	return a.fitness < b.fitness;
}

// support for 'output operator'
ostream& operator<< (ostream& out, const Chromosome& c){
	out << "Chromosome \"" << c.value << "\" (fitness=" << c.fitness << ")";
}
