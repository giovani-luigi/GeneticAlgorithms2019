#include "Utils.h"

using namespace std;

const string Utils::letters = "ABCDEFGHIJHIJKLMNOPQRSTUVXWYZ";

bool Utils::randomized = false;

// generates a random word with a given size
string Utils::generateWord(int size){
	
	stringstream buffer;
	
	// randomize only once
	if (!randomized){
		srand(time(0));
		randomized = true;
	}	
	
	for (int i=0; i<size; i++){
		int index = rand() % letters.size();
		buffer << letters[index];
	}	
	
	return buffer.str();
}

// generates a random number between 0 and a max. value (exclusive)
int Utils::random(int excMax){
	
	// randomize only once
	if (!randomized){
		srand(time(0));
		randomized = true;
	}	
	
	return rand() % excMax;
	
}
