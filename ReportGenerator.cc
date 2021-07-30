
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <cstdlib>
#include <iterator>


#include "ReportGenerator.h"
using namespace std;

//initialize fileName
const char* fileName = "farms.dat";


vector<Record*> ReportGenerator::censusData;
Map<int> ReportGenerator::mapYear;
Map<string> ReportGenerator::mapRegion;
Map<string> ReportGenerator::mapAnimal;





void ReportGenerator::loadData() {
	//read in the .dat file
	ifstream infile(fileName, ios::in);
	//if we cant find file print out an Error message and exit
	if (!infile) {
		cout << "ERROR: CANNOT OPEN FILE: " << fileName << endl;
		exit(1);
	}
	int year, numFarms, numAnimals;
	string region, subRegion, animalType;
	while (infile >> year >> region >> subRegion >> animalType >> numFarms >> numAnimals) {
		//push back each record on the censusData collection and to each map
		Record* rec = new Record(year, region, subRegion, animalType, numFarms, numAnimals);
		censusData.push_back(rec);
		mapYear.add(year, rec);
		mapRegion.add(region, rec);
		mapAnimal.add(animalType, rec);
	}
}



void ReportGenerator::releaseData() {
	//free up the records in the censusData collection
	for (unsigned int i = 0; i < censusData.size(); ++i) {
		delete censusData[i];
	}
}
