#include <iostream>
#include <string>
#include <sstream>
#include<iomanip>
#include "Report2.h"
using namespace std;



const string Report2::REGION = "CAN";
const string Report2::REPORT_TITLE = "       PERCENTAGE CHANGE OF ANIMALS (2011-2016)";



Report2::Report2(AscBehaviour<float> c) {
	dataReport2 = new ReportData<float>(&c);
	compute();
}



Report2::~Report2() {
	delete dataReport2;
}



void Report2::compute() {
	try{
		//declare place holders
		int horseNum[100][100];
		int goatNum[100][100];
		int llamaNum[100][100];
		int rabbitNum[100][100];
		int bisonNum[100][100];
		int elkNum[100][100];
		int deerNum[100][100];
		int minkNum[100][100];
		int boarNum[100][100];
		int totalNum[100][100];
		vector<int> tempKeys = ReportGenerator::mapYear.getKey();
		//loop through the year keys
		for (unsigned int i = 0; i < tempKeys.size(); ++i) {
			vector<Record*>& tempRecs = ReportGenerator::mapYear[tempKeys[i]];
			//initialize place holders
			horseNum[i][0] = {0};
			goatNum[i][0] = {0};
			rabbitNum[i][0] = {0};
			bisonNum[i][0] = {0};
			elkNum[i][0] = {0};
			deerNum[i][0] = {0};
			minkNum[i][0] = {0};
			boarNum[i][0] = {0};
			//loop through values of keys if the region in Canada, then check the animal types and add to corresponding placeholders
			for (unsigned int j = 0; j < tempRecs.size(); ++j) {
				if (tempRecs[j]->getRegion() == REGION){
					if (tempRecs[j]->getAnimalType() == "Horses-Ponies") {
						horseNum[i][0] = tempRecs[j]->getNumAnimals();
					}
					else if (tempRecs[j]->getAnimalType() == "Goats") {
						goatNum[i][0] = tempRecs[j]->getNumAnimals();
					}
					else if (tempRecs[j]->getAnimalType() == "Llamas-Alpacas") {
						llamaNum[i][0] = tempRecs[j]->getNumAnimals();
					}
					else if (tempRecs[j]->getAnimalType() == "Rabbits") {
						rabbitNum[i][0] = tempRecs[j]->getNumAnimals();
					}
					else if (tempRecs[j]->getAnimalType() == "Bison-Buffalo") {
						bisonNum[i][0] = tempRecs[j]->getNumAnimals();
					}
					else if (tempRecs[j]->getAnimalType() == "Elk-Wapiti") {
						elkNum[i][0] = tempRecs[j]->getNumAnimals();
					}
					else if (tempRecs[j]->getAnimalType() == "Domestic-Deer") {
						deerNum[i][0] = tempRecs[j]->getNumAnimals();
					}
					else if (tempRecs[j]->getAnimalType() == "Wild-Boars") {
						boarNum[i][0] = tempRecs[j]->getNumAnimals();
					}
					else if (tempRecs[j]->getAnimalType() == "Mink") {
						minkNum[i][0] = tempRecs[j]->getNumAnimals();
					}
				}
			}
			totalNum[i][0] = horseNum[i][0] + goatNum[i][0] + llamaNum[i][0] + rabbitNum[i][0] + bisonNum[i][0] + elkNum[i][0] + deerNum[i][0] + boarNum[i][0] + minkNum[i][0];
		}
		//compute and add the horse records to the dataReport and to format the row
		float horseDif = 0.0;
		float horse2011 = 0.0;
		float horse2016 = 0.0;
		horse2011 = ((float)horseNum[0][0] / totalNum[0][0])*100.00f;
		horse2016 = ((float)horseNum[1][0] / totalNum[1][0])*100.00f;
		horseDif = horse2016 - horse2011;
		string reportRow = formatData("Horses-Ponies", horse2011,horse2016, horseDif);
		dataReport2->add(horseDif, reportRow);
		//compute and add the goat records to the dataReport and to format the row
		float goatDif = 0.0;
		float goat2011 = 0.0;
		float goat2016 = 0.0;
		goat2011 = ((float)goatNum[0][0] / totalNum[0][0])*100.00f;
		goat2016 = ((float)goatNum[1][0] / totalNum[1][0])*100.00f;
		goatDif = goat2016 - goat2011;
		string reportRow2 = formatData("Goats",  goat2011, goat2016,goatDif);
		dataReport2->add(goatDif, reportRow2);
		//compute and add the rabbit records to the dataReport and to format the row
		float rabbitDif = 0.0;
		float rabbit2011 = 0.0;
		float rabbit2016 = 0.0;
		rabbit2011 = ((float)rabbitNum[0][0] / totalNum[0][0])*100.00f;
		rabbit2016 = ((float)rabbitNum[1][0] / totalNum[1][0])*100.00f;
		rabbitDif = rabbit2016 - rabbit2011;
		string reportRow3 = formatData("Rabbits", rabbit2011, rabbit2016, rabbitDif);
		dataReport2->add(rabbitDif, reportRow3);
		//compute and add the bison records to the dataReport and to format the row
		float bisonDif = 0.0;
		float bison2011 = 0.0;
		float bison2016 = 0.0;
		bison2011 = ((float)bisonNum[0][0] / totalNum[0][0])*100.00f;
		bison2016 = ((float)bisonNum[1][0] / totalNum[1][0])*100.00f;
		bisonDif = bison2016 - bison2011;
		string reportRow4 = formatData("Bison-Buffalo", bison2011, bison2016, bisonDif);
		dataReport2->add(bisonDif, reportRow4);
		//compute and add the deer records to the dataReport and to format the row
		float deerDif = 0.0;
		float deer2011 = 0.0;
		float deer2016 = 0.0;
		deer2011 = ((float)deerNum[0][0] / totalNum[0][0])*100.00f;
		deer2016 = ((float)deerNum[1][0] / totalNum[1][0])*100.00f;
		deerDif = deer2016 - deer2011;
		string reportRow5 = formatData("Domestic-Deer", deer2011, deer2016, deerDif);
		dataReport2->add(deerDif, reportRow5);
		//compute and add the elk records to the dataReport and to format the row
		float elkDif = 0.0;
		float elk2011 = 0.0;
		float elk2016 = 0.0;
		elk2011 = ((float)elkNum[0][0] / totalNum[0][0])*100.00f;
		elk2016 = ((float)elkNum[1][0] / totalNum[1][0])*100.00f;
		elkDif = elk2016 - elk2011;
		string reportRow6 = formatData("Elk-Wapiti", elk2011, elk2016, elkDif);
		dataReport2->add(elkDif, reportRow6);
		//compute and add the llama records to the dataReport and to format the row
		float llamaDif = 0.0;
		float llama2011 = 0.0;
		float llama2016 = 0.0;
		llama2011 = ((float)llamaNum[0][0] / totalNum[0][0])*100.00f;
		llama2016 = ((float)llamaNum[1][0] / totalNum[1][0])*100.00f;
		llamaDif = llama2016 - llama2011;
		string reportRow7 = formatData("Llama-Alpacas", llama2011, llama2016, llamaDif);
		dataReport2->add(llamaDif, reportRow7);
		//compute and add the boar records to the dataReport and to format the row
		float boarDif = 0.0;
		float boar2011 = 0.0;
		float boar2016 = 0.0;
		boar2011 = ((float)boarNum[0][0] / totalNum[0][0])*100.00f;
		boar2016 = ((float)boarNum[1][0] / totalNum[1][0])*100.00f;
		boarDif = boar2016 - boar2011;
		string reportRow8 = formatData("Wild-Boars", boar2011, boar2016, boarDif);
		dataReport2->add(boarDif, reportRow8);
		//compute and add the mink records to the dataReport and to format the row
		float minkDif = 0.0;
		float mink2011 = 0.0;
		float mink2016 = 0.0;
		mink2011 = ((float)minkNum[0][0] / totalNum[0][0])*100.00f;
		mink2016 = ((float)minkNum[1][0] / totalNum[1][0])*100.00f;
		minkDif = mink2016 - mink2011;
		string reportRow9 = formatData("Mink", mink2011, mink2016, minkDif);
		dataReport2->add(minkDif, reportRow9);
	}
	//catch the exception
	catch(const char* str){
		cerr << str << endl;
		return;
	}
}



string Report2::formatData(const string& Region, float numAnimals2011, float numAnimals2016, float dif) {
	//format the data to readable string
	stringstream ss;
	if(dif > 0.0){
		ss << fixed;
		ss << setprecision(1);
		ss <<setw(20)<< Region  <<setw(8) << numAnimals2011 << setw(8) << numAnimals2016 << setw(5) << "+" << dif;
		return ss.str();
	}else{
		ss << fixed;
		ss << setprecision(1);
		ss <<setw(20)<< Region  <<setw(8) << numAnimals2011 << setw(8) << numAnimals2016 << setw(8) << dif;
		return ss.str();
	}
}



void Report2::printReport() {
	//print the report
	cout << endl;
	cout << endl;
	cout << REPORT_TITLE << endl;
	cout << "       ----------------------------------------" << endl;
	cout << endl;
	cout << "                        2011    2016   Change"<< endl;
	cout << endl;
	cout << *dataReport2;
}
