#ifndef UTILS_H
#define UTILS_H

#include <sstream>		// stringstream
#include <string>
#include <ctime>		// srand(), time()


using namespace std;

class Utils{
	
	public:
		
		// generates a random word with a given size
		static string generateWord(int size);
		
		// generates a random number between 0 and a max. number
		// - max: a max. value to be generated (exclusive)		
		static int random(int excMax);
	
	private:
		
		static const string letters;
		
		static bool randomized;
};


#endif
