#ifndef UTILS_H
#define UTILS_H

#include <sstream>		// stringstream
#include <string>
#include <ctime>		// srand(), time()

using namespace std;

class Utils{
	
	public:
		
		// Generates a random word with a given size
		static string generateWord(int size);
	
	private:
		
		static const string letters;
		
};


#endif
