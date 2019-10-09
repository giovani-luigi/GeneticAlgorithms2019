#include "Chromosome.h"

// default ctor
Chromosome::Chromosome(string finalState){	
	this->value = Utils::generateWord(finalState.size());
	this->fitness = calculateFitness(finalState);
}

// calculate a fitness based in how close
// the current state is to the finalState
int Chromosome::calculateFitness(string finalState){
	int fitness = 0;	
	
	for (int i=0; i<finalState.size(); i++){
	
		//	+5 if the character is present in any position	
		int pos = this->value.find(finalState[i]);
		if (pos > -1) fitness += 5; // if found at any position
		
		// 	+50 for the right char at the right position	
		if (value[i] == finalState[i]) fitness += 50;
				
	}
	return fitness;
}

// fitness getter
int Chromosome::getFitness(){
	return this->fitness;
}

// override < operator
bool operator < (const Chromosome& a, const Chromosome& b){
	return a.fitness < b.fitness;
}

// override 'output operator'
ostream& operator<< (ostream& out, const Chromosome& c){
	return out << "Chromosome \"" << c.value << "\" (fitness=" << c.fitness << ")";
}

// override operator == so we can compare equality
bool operator == (const Chromosome& a, const Chromosome& b){
	return a.value == b.value;
}

// override operator != so we can compare inequality
bool operator != (const Chromosome& a, const Chromosome& b){
	return a.value != b.value;
}
