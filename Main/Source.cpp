//
//  main.cpp
//  FieldsGlen - Project3
//
//  Created by Glen Fields on 4/7/15.
//  Copyright (c) 2015 gfields. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <utility>
#include <iterator>
#include <sstream>
#include <iomanip>
#include "Cars.h"


int main() {
	//declarations
	int cases;
	int faresNum = 24;
	int i, j;
	int month, day, hour, min;
	int roadNum;
	std::string license;
	std::string token;
	std::string string;
	char dontNeed;
	std::vector<float> fares(faresNum);
	std::map<std::string, class Cars> carMap;
	std::ofstream OutPut("output.txt");
	std::ifstream Input("input.txt");            //open file

	getline(Input, string);                      //get cases
	cases = std::stoi(string);
	Input.ignore();                             //skip blank line

	for (i = 0; i < cases; ++i) {
		getline(Input, string);                      //collect fares
		std::istringstream iss(string);
		for (j = 0; j < 24; ++j) {
			iss >> fares.at(j);
		}

		iss.clear();
		iss.str("");
		getline(Input, string);                  //retrieve car info
		while (string != ""){
			iss.str(string);
			iss >> license >> month >> dontNeed >> day >> dontNeed >> hour >> dontNeed >> min >> token >> roadNum;
			if (carMap.count(license) == 0) {
				Cars Car;
				Car.setMonthA(month);
				Car.setDayA(day);
				Car.setHourA(hour);
				Car.setMinA(min);
				Car.setEnter(roadNum);
				Car.setFare(fares.at(hour));
				carMap.insert(std::make_pair(license, Car));
			}
			else if (carMap.count(license) != 0 && token == "exit"){
				carMap[license].setMonthA(month);
				carMap[license].setDayA(day);
				carMap[license].setHourD(hour);
				carMap[license].setMinD(min);
				carMap[license].setExit(roadNum);
				carMap[license].calculateBill();
			}
			else if (carMap.count(license) != 0 && token == "enter"){
				carMap[license].setMonthA(month);
				carMap[license].setDayA(day);
				carMap[license].setHourA(hour);
				carMap[license].setMinA(min);
				carMap[license].setEnter(roadNum);
				carMap[license].setFare(fares.at(hour));
			}
			if (Input.eof()) {
				break;
			}

			iss.clear();
			iss.str("");
			getline(Input, string);
		}

		for (std::map<std::string, class Cars>::iterator it = carMap.begin(); it != carMap.end(); ++it) {
			OutPut << std::setprecision(2) << std::fixed << it->first << " $" << it->second.getBill() << "\n";
		}
		OutPut << std::endl;
		carMap.clear();
		std::cout << std::endl;
	}

	OutPut.close();
	Input.close();
	return 0;
}
