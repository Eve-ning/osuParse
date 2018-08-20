// osuParse.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "DBug.h"

int main()
{
	// Changes std::cout << (bool) outputs to True & False instead of 1 or 0.
	std::cout << std::boolalpha;

	bool DEBUG_FLAG = true;

	if (DEBUG_FLAG) {
		// Debug functions
		Dbug::primitive_debug();
		Dbug::algorithm_debug();
	}


	
	// Pauses progam before closing
	int PAUSE = 0;
	std::cout << "Enter any key to EXIT. ";
	std::cin >> PAUSE;
    return 0;
}
