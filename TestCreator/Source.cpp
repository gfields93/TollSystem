//
//  main.cpp
//  TestCreator
//
//  Created by Glen Fields on 4/13/15.
//  Copyright (c) 2015 gfields. All rights reserved.
//

#include <stdlib.h>
#include <vector>
#include <iostream>
#include <string>
#include <array>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <sstream>

int main(int argc, const char * argv[]){
	const char characters[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	std::ofstream output("input.txt");
	int x = sizeof(characters) - 1;
	std::string string;
	srand(time(NULL));
	int cases = atoi(argv[1]);
	int cars = atoi(argv[2]);
	output << cases << "\n" << "\n";

	for (int i = 0; i < cases; ++i) {
		int month = (rand() % 12) + 1;
		int day = (rand() % 31) + 1;


		for (int j = 0; j < 24; ++j) {
			int fares = (rand() % 100) + 1;
			if (j == 23){
				output << fares << "\n";
			}
			else{
				output << fares << " ";
			}
		}
		for (int j = 0; j < cars; ++j) {
			string.clear();
			for (int y = 0; y < 6; ++y) {
				char pickChar = characters[rand() % x];
				string.push_back(pickChar);
			}
			int hourEnter = (rand() % 24);
			int minEnter = (rand() % 60);
			int hourExit;
			int minExit;
			if (hourEnter == 0){
				hourExit = (rand() % 1) + (23 - hourEnter);
			}
			else{
				hourExit = (rand() % hourEnter) + (23 - hourEnter);
			}
			if (minEnter == 0) {
				minExit = (rand() % 1) + (59 - minEnter);
			}
			else{
				minExit = (rand() % minEnter) + (59 - minEnter);
			}
			int enter = (rand() % 100) + 1;
			int exit = (rand() % 100) + 1;

			output << string << " " << month << ":" << day << ":" << hourEnter << ":" << minEnter << " enter " << enter << "\n";
			output << string << " " << month << ":" << day << ":" << hourExit << ":" << minExit << " exit " << exit << "\n";

		}
		output << "\n";
	}
	output.close();

	return 0;
}