#include <iostream>
using namespace std;
#include <string>
#include "Control.h"
#include "ReportGenerator.h"
#include "CompareBehaviour.h"
#include "AscBehaviour.h"
#include "DescBehaviour.h"
#include "Report1.h"
#include "Report2.h"
#include "Report3.h"



Control::~Control(){
  for(unsigned int i = 0; i < repGen.size(); ++i){
    delete repGen[i];
  }
}



void Control::launch(){
  //load the .dat file and read it
  ReportGenerator::loadData();
  //declare behaviour types
  DescBehaviour<int> intCb;
  AscBehaviour<float> floatBc;
  //add each report to the collection with behaviour in the paramaters
  repGen.push_back(new Report1(intCb));
  repGen.push_back(new Report2(floatBc));
  repGen.push_back(new Report3(intCb));
  int cont = 1;
  while (cont != 0) {
    //display the menu
	  v.showMenu(cont);
	  switch (cont) {
		//if 0 then exit
		case 0:
		  break;
		//if 1 then compute Percentage distribution of farms by province in (2016)
		case 1:
			repGen[0]->printReport();
			break;
		//if 2 then compute Percentage change of animals, by province (2011-2016)
		case 2:
			repGen[1]->printReport();
			break;
		//if 3 then compute sub-region with highest number of horses, by province (2016)
		case 3:
			repGen[2]->printReport();
			break;
		default:
			cout << "ERROR invalid case entered" << endl;
	  }
  }
  //clean up the data when finished
  ReportGenerator::releaseData();
}
