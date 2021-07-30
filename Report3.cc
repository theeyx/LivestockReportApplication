#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include "Report3.h"
using namespace std;

const string Report3::ANIMAL_TYPE = "Horses-Ponies";
const string Report3::REPORT_TITLE = "   SUB-REGION WITH MOST HORSES/PONIES BY REGION IN 2016";
const string Report3::SUB = "All";
const int Report3::YEAR = 2016;
const string Report3::REGION = "CAN";




Report3::Report3(DescBehaviour<int> c) {
	dataReport3 = new ReportData<int>(&c);
	compute();
}



Report3::~Report3() {
	delete dataReport3;
}



void Report3::compute() {
	try{
		vector<string>& tempKeys = ReportGenerator::mapRegion.getKey();
		//loop through the region keys
		for (unsigned int i = 0; i < tempKeys.size(); ++i) {
			//if the region is Canada then continue
			if (tempKeys[i] == REGION)
			{
				continue;
			}
			vector<Record*>& tempRecs = ReportGenerator::mapRegion[tempKeys[i]];
			//initialize place holders
			string subRegion = " ";
			int maxHorsesNum = 0;
			//loop through the values of the region and find subRegion with largest specified animal population inside current region
			for (unsigned int j = 0; j < tempRecs.size(); ++j) {
				//check if the year is 2016, animal is horses and subRegion cant be all
				if ((tempRecs[j]->getAnimalType() == ANIMAL_TYPE) && (tempRecs[j]->getYear() == YEAR) && (tempRecs[j]->getSubRegion() != SUB)) {
					if (tempRecs[j]->getNumAnimals() > maxHorsesNum) {
						maxHorsesNum = tempRecs[j]->getNumAnimals();
						subRegion = tempRecs[j]->getSubRegion();
					}
				}
			}
			//now we have found subregion with greatest number of specified animal
			//format our report row
			string reportRow = formatData(tempKeys[i], subRegion, maxHorsesNum);
			dataReport3->add(maxHorsesNum, reportRow);
		}
	//catch exception
	}
	catch(const char* str){
		cerr << str << endl;
		return;
	}
}



string Report3::formatData(const string& Region, const string& subRegion, int numAnimals) {
	//format data into readable string
	stringstream ss;
	ss <<setw(5) << Region << "    " << setw(38) << left << subRegion <<setw(5)<<right << numAnimals;
	return ss.str();
}



void Report3::printReport() {
	//print the report
	cout << endl;
	cout << endl;
	cout << REPORT_TITLE << endl;
	cout << "   ----------------------------------------------------" << endl;
	cout << *dataReport3;
}
