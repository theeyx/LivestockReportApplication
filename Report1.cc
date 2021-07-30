#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include "Report1.h"
using namespace std;


const string Report1::REPORT_TITLE = "                      PERCENTAGE OF FARMS BY REGION IN 2016";
const int Report1::YEAR = 2016;
const string Report1::SUB = "All";
const string Report1::REGION = "CAN";




Report1::Report1(DescBehaviour<int> c){
  dataReport1 = new ReportData<int>(&c);
  try{
    compute();
  }
  catch(const char* str){
    cerr << str << endl;
  }
}



Report1::~Report1(){
  delete dataReport1;
}



//helper function for compute to get the record of all the particular farms in country
void Report1::computeFarms() {
   //initialize record holders
   horseFarm = 0;
   goatFarm = 0;
   llamaFarm = 0;
   rabbitFarm = 0;
   bisonFarm = 0;
   elkFarm = 0;
   deerFarm = 0;
   minkFarm = 0;
   totalFarm = 0;
  //get all the keys in the mapRegion
	vector<string>& tempKeys = ReportGenerator::mapRegion.getKey();
  //loop through the mapRegion if the region is Canada, continue
	for (unsigned int i = 0; i < tempKeys.size(); ++i) {
		if (tempKeys[i] == REGION)
		{
			continue;
		}
    //get all the values for the region
		vector<Record*>& tempRecs = ReportGenerator::mapRegion[tempKeys[i]];
    //loop through all the values of the region
		for (unsigned int j = 0; j < tempRecs.size(); ++j) {
      //check if the subRegion is all and the year is 2016
			if ((tempRecs[j]->getSubRegion() == SUB) && (tempRecs[j]->getYear() == YEAR)) {
        //if it matches any one of these checks add them to the farm of the type
				if (tempRecs[j]->getAnimalType() == "Horses-Ponies") {
					horseFarm += tempRecs[j]->getNumFarms();
				}
				else if (tempRecs[j]->getAnimalType() == "Goats") {
					goatFarm += tempRecs[j]->getNumFarms();
				}
				else if  (tempRecs[j]->getAnimalType() == "Llamas-Alpacas") {
					llamaFarm += tempRecs[j]->getNumFarms();
				}
				else if (tempRecs[j]->getAnimalType() == "Rabbits") {
					rabbitFarm += tempRecs[j]->getNumFarms();
				}
				else if (tempRecs[j]->getAnimalType() == "Bison-Buffalo") {
					bisonFarm += tempRecs[j]->getNumFarms();
				}
				else if (tempRecs[j]->getAnimalType() == "Elk-Wapiti") {
					elkFarm += tempRecs[j]->getNumFarms();
				}
				else if (tempRecs[j]->getAnimalType() == "Domestic-Deer") {
					deerFarm += tempRecs[j]->getNumFarms();
				}
				else if (tempRecs[j]->getAnimalType() == "Mink") {
					minkFarm += tempRecs[j]->getNumFarms();
				}
        else{
          //throw exception if none matches
          throw "Cant get the right animal type";
        }
			}
		}
    //compute total number of all farms
		totalFarm = horseFarm + goatFarm + llamaFarm + rabbitFarm + bisonFarm + elkFarm + deerFarm + minkFarm;
	}
}




void Report1::compute(){
  computeFarms();
  try{
  	//get all the keys in the mapRegion
  	vector<string>& tempKeys = ReportGenerator::mapRegion.getKey();
    //loop theough the mapRegion if the region is Canada, continue
  	for (unsigned int i = 0; i < tempKeys.size(); ++i) {
  		if (tempKeys[i] == REGION)
  		{
  			continue;
  		}
  		vector<Record*>& tempRecs = ReportGenerator::mapRegion[tempKeys[i]];
  		//initialize record holders to 0 every loop
  		int horseNum = 0;
  		int goatNum = 0;
  		int llamaNum = 0;
  		int rabbitNum = 0;
  		int bisonNum = 0;
  		int elkNum = 0;
  		int deerNum = 0;
  		int minkNum = 0;
  		int totalNum = 0;
  		int boarNum = 0;
      //loop through all the values of the region
  		for (unsigned int j = 0; j < tempRecs.size(); ++j) {
        //check if the subRegion is all and the year is 2016
  			if ((tempRecs[j]->getSubRegion() == SUB)&&(tempRecs[j]->getYear() == YEAR)) {
          //if the type matches one of the checks add it to the corresponding record holder
  				if (tempRecs[j]->getAnimalType() == "Horses-Ponies") {
  					horseNum = tempRecs[j]->getNumFarms();
  				}
  				else if (tempRecs[j]->getAnimalType() == "Goats") {
  					goatNum = tempRecs[j]->getNumFarms();
  				}
  				else if (tempRecs[j]->getAnimalType() == "Llamas-Alpacas") {
  					llamaNum = tempRecs[j]->getNumFarms();
  				}
  				else if(tempRecs[j]->getAnimalType() == "Rabbits") {
  					rabbitNum = tempRecs[j]->getNumFarms();
  				}
  				else if(tempRecs[j]->getAnimalType() == "Bison-Buffalo") {
  					bisonNum = tempRecs[j]->getNumFarms();
  				}
  				else if(tempRecs[j]->getAnimalType() == "Elk-Wapiti") {
  					elkNum = tempRecs[j]->getNumFarms();
  				}
  				else if(tempRecs[j]->getAnimalType() == "Domestic-Deer") {
  					deerNum = tempRecs[j]->getNumFarms();
  				}
  				else if (tempRecs[j]->getAnimalType() == "Wild-Boars") {
  					boarNum = tempRecs[j]->getNumFarms();
  				}
  				else if(tempRecs[j]->getAnimalType() == "Mink") {
  					minkNum = tempRecs[j]->getNumFarms();
  				}
          else{
            throw "Cant get the right animal type";
          }
  			}
  		}
      //compute total number of farms per region
  		totalNum = horseNum + goatNum + llamaNum + rabbitNum + bisonNum + elkNum + deerNum + boarNum + minkNum;
      //format string and add to our report
  		string reportRow = formatData(tempKeys[i], horseNum, goatNum, llamaNum, rabbitNum, bisonNum, elkNum, deerNum, boarNum, minkNum, totalNum);
  		dataReport1->add(totalNum, reportRow);
    }
  }
  //catch exception
  catch(const char* str){
    cerr << str << endl;
    return;
  }
}



string Report1::formatData(const string& Region, int horses, int goat, int llama, int rabbit, int bison, int elk, int deer, int boar, int mink, int total) {
  //format data to readable string
	stringstream ss;
	ss << fixed;
	ss << setprecision(1);
	ss <<Region << "\t"  << (static_cast<float>(horses)/horseFarm)*100.00 << "\t" << ((float)goat/goatFarm)*100.00 << "\t" << ((float)llama/llamaFarm)*100.00<< "\t" << ((float)rabbit/rabbitFarm)*100.00 << "\t" << ((float)bison/bisonFarm)*100.00 << "\t" << ((float)elk/elkFarm)*100.00 << "\t" << ((float)deer/deerFarm)*100.00 << "\t" << (float)boar << "\t" << ((float)mink/minkFarm)*100.00 << "\t" << ((float)total/totalFarm)*100.00;
	return ss.str();
}



void Report1::printReport(){
  //prints the report on screen;
	cout << endl;
	cout << endl;
	cout << REPORT_TITLE << endl;
	cout << "                      -------------------------------------" << endl;
	cout << endl;
	cout << "       Horses/  Goats  Llamas  Rabbits Bison/   Elk   Domestic  Wild    Mink   Totals" << endl;
	cout << "       Ponies          Alpacas         Buffalo  Wapiti  Deer    Boars                " << endl;
	cout << *dataReport1;
}
