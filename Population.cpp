#include "Population.h"

Population::Population(int size, string finalState){
	this->finalState = finalState;
	
	// populate population with random chromosomes
	for (int i=0; i < size; i++){
		Chromosome c(finalState);
		this->chromosomes.push_back(c);
	}
}

// sort the population (by fitness)
void Population::sort(){
	// sort using default comparison (operator <)
	std::sort(chromosomes.begin(), chromosomes.end());
}

// creates a new population based in a selection rate
void Population::select(int ratePct){
	
    // store the selected chromosomes to pass to next generation
	vector<Chromosome> newPopulation;
	
	// calculate the total fitness
	int totalFitness = 0;
	for (int i=0; i < chromosomes.size() ;i++){
		totalFitness += chromosomes[i].getFitness();
	}
	
	// calculate the relative fitness (chromosome/total)
	for (int i=0; i < chromosomes.size(); i++){
		chromosomes[i].fitnessPct = chromosomes[i].getFitness() * 100 / totalFitness;
	}
	
	// create a roulette wheel
	cout << "Creating Roulette: " << endl;
	vector<Chromosome*> roulette; // vector of pointers (reference) to the objects
	int slots;
	for (int i=0; i < chromosomes.size(); i++){
		slots = chromosomes[i].fitnessPct; // how many slots to use in the roulette wheel
		for (int j=0; j < slots; j++){
			roulette.push_back(&(chromosomes[i])); // add a pointer (not a copy to the object)
			cout << "Roulette item: " << *roulette[roulette.size()-1] << endl;
		}
	}
	
	// from the given rate, calculate the amount of chromosomes to select 
	int qtyToSelect = (chromosomes.size() * ratePct) / 100;
	
	for (int i = 0; i < qtyToSelect; i++){
		
		// select a random chromosome from roulette slots
		int randomSlot = Utils::random(roulette.size());
		Chromosome* selected = roulette[randomSlot];

		cout << "Roulette selecting: " << *selected << endl;

		// create a new roulette without the drawn chromosome for next iterations
		vector<Chromosome*> newRoulette;
		for (int j=0; j < roulette.size(); j++){
			if ( *roulette[j] != *selected )
				newRoulette.push_back(roulette[j]);
		}
		roulette.clear();
		roulette = newRoulette;
		
		cout << "New roulette:" << endl;
		for (int j =0; j < roulette.size(); j++)
			cout << "Roulette item: " << *roulette[j] << endl;		

		// add the selected chromosome to the new population if not added already
		newPopulation.push_back(*selected); // insert by copy
	}
	
	// copy local container to outer container
	chromosomes = newPopulation;
	
}

//
void Population::reproduce(){
	
}

ostream& operator<<(ostream& out, const Population& p){
	// populate population with random chromosomes
	for (int i=0; i < p.chromosomes.size(); i++){
		out << p.chromosomes[i] << endl;
	}
	return out;
}
