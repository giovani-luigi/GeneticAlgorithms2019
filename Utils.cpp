#include "Utils.h"

using namespace std;

const string Utils::letters = "abcdefghijklmnopqrstuvxwyz ABCDEFGHIJHIJKLMNOPQRSTUVXWYZ";

string Utils::generateWord(int size){
	
	stringstream buffer;
	
	srand(time(0));
	
	for (int i=0; i<size; i++){
		int index = rand() % letters.size();
		buffer << letters[index];
	}	
	
	return buffer.str();
}
