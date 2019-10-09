#include "Population.h"

Population::Population(int size, string finalState){
	this->finalState = finalState;
	
	// populate population with random chromosomes
	for (int i=0; i < size; i++){
		Chromosome c(finalState);
		this->chromosomes.push_back(c);
	}
}

Population::Population(vector<Chromosome> chromosomes, string finalState){
	this->finalState = finalState;
	this->chromosomes = chromosomes; // copy the collection
}


// sort the population (by fitness)
void Population::sort(){
	// sort using default comparison (operator <)
	std::sort(chromosomes.begin(), chromosomes.end());
}

// add the chromosomes from other population to this
void Population::add(Population other){
	for (int i=0; i < other.chromosomes.size(); i++){
		this->chromosomes.push_back(other.chromosomes[i]);
	}	
}

// creates a new population based in a selection rate
//  - ratePct: the rate to select. e.g. 30 (30%)
//  - elitism: when true, the best fit will be always selected
//  - return: the selected population
Population Population::select(int ratePct, bool elitism){
	
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
//	cout << "Creating Roulette: " << endl;
	vector<Chromosome*> roulette; // vector of pointers (reference) to the objects
	int slots;
	for (int i=0; i < chromosomes.size(); i++){
		slots = chromosomes[i].fitnessPct; // how many slots to use in the roulette wheel
		for (int j=0; j < slots; j++){
			roulette.push_back(&(chromosomes[i])); // add a pointer (not a copy to the object)
//			cout << "Roulette item: " << *roulette[roulette.size()-1] << endl;
		}
	}
	
	// from the given rate, calculate the amount of chromosomes to select 
	int qtyToSelect = (chromosomes.size() * ratePct) / 100;
	
	for (int i = 0; i < qtyToSelect && roulette.size() > 0 ; i++){ 

		// as if the fit is Zero it is not added to the roulette,
		// there are occasions where there are no more items to add
		// in the roulette, but we still did not select enough items
		// so we need to perform the roulette.size() check before entering the for
			
		Chromosome* selected;

		if (i==0 && elitism){
			// select the last chromosome of the collection (best fit)
			selected = &(chromosomes[chromosomes.size()-1]);
			cout << "Roulette selecting (by elitism): " << *selected << endl;
		}else{
			// select a random chromosome from roulette slots
			int randomSlot = Utils::random(roulette.size());
			selected = roulette[randomSlot];
			cout << "Roulette selecting: " << *selected << endl;
		}		

		// create a new roulette without the drawn chromosome for next iterations
		vector<Chromosome*> newRoulette;
		for (int j=0; j < roulette.size(); j++){
			if ( *roulette[j] != *selected )
				newRoulette.push_back(roulette[j]);
		}
		roulette.clear();
		roulette = newRoulette;
		
//		cout << "New roulette:" << endl;
//		for (int j =0; j < roulette.size(); j++)
//			cout << "Roulette item: " << *roulette[j] << endl;		

		// add the selected chromosome to the new population if not added already
		newPopulation.push_back(*selected); // insert by copy
	}
	
 	// return selected chromosomes
	return Population(newPopulation, this->finalState);
}

// triggers a reproduction in the current population
//  - ratePct: the rate to reproduce. e.g. 70 (70%)
Population Population::reproduce(int ratePct){
	
	int idxMom, idxDad; // index of parents
	string mom, dad; // parents
	string child1, child2;
	
	// generated children
	vector<Chromosome> newPopulation;
	
	// calculate amount of chromosomes to reproduce
	int qtyToReproduce = (chromosomes.size() * ratePct) / 100;
	
	for (int i=0; i <= (qtyToReproduce / 2) ; i++){
		
		// select two different chromosomes to cross
		idxDad = Utils::random(chromosomes.size());
		do {
			idxMom = Utils::random(chromosomes.size());
		} while (idxMom == idxDad);
		
		dad = chromosomes[idxDad].getValue();
		mom = chromosomes[idxMom].getValue();
		
//		cout << "Crossing [dad= " << dad << "; mom=" << mom << "]" << endl;
		
		// child1 = dad's first half + mom's last half
		child1 = dad.substr(0, dad.size()/2) + mom.substr(mom.size()/2, mom.size());
		// child2 = mom's first half + dad's last half
		child2 = mom.substr(0, mom.size()/2) + dad.substr(dad.size()/2, dad.size());
	
//		cout << "Children [c1= " << child1 << "; c2=" << child2 << "]" << endl;
	
		newPopulation.push_back(Chromosome(child1, this->finalState));
		newPopulation.push_back(Chromosome(child2, this->finalState));
	}
	
	return Population(newPopulation, this->finalState); // returns a copy of generated population
}

// triggers a mutation in the current population
void Population::mutate(){
	
	int qtyToMutate = Utils::random(chromosomes.size()/2) + 1;
	
	cout << "Mutating " << qtyToMutate << " chromosomes." << endl;
	
	while (qtyToMutate --> 0){
		int pos = Utils::random(chromosomes.size());
		
		Chromosome* mutant = &chromosomes[pos];
		
		cout << "Mutating [" << *mutant << "] to [";
		
		mutant->mutate();
		
		cout << *mutant << "]" << endl;
	}
}

ostream& operator<<(ostream& out, const Population& p){
	// populate population with random chromosomes
	for (int i=0; i < p.chromosomes.size(); i++){
		out << p.chromosomes[i] << endl;
	}
	return out;
}
