// osuParseSub.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"

int main() {
	try {
		OsuMap map = OsuMap("map.txt");

		map.mapSettings().debugSettings();
	}
	catch (std::exception &e) {
		std::cout << e.what();
	}
}