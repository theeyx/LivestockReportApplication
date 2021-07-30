#ifndef REPORTGENERATOR_H
#define REPORTGENERATOR_H

#include <vector>
#include "Map.h"
#include "Record.h"

class ReportGenerator{

  public:
    virtual void compute() = 0;
	  virtual void printReport() = 0;
    static void loadData();
    static void releaseData();


  protected:
    static vector<Record*> censusData;
    static Map<int> mapYear;
    static Map<string> mapRegion;
    static Map<string> mapAnimal;





};



#endif
