#ifndef REPORT1_H
#define REPORT1_H

#include "ReportData.h"
#include "CompareBehaviour.h"
#include "ReportGenerator.h"
#include "AscBehaviour.h"
#include "DescBehaviour.h"

class Report1 : public ReportGenerator
{
  public:
    Report1(DescBehaviour<int>);
    ~Report1();
    virtual void compute();
	  virtual void printReport();




  private:
    ReportData<int>* dataReport1;
  	static const string REPORT_TITLE;
    static const string SUB;
    static const string REGION;
    static const int YEAR;
  	string formatData(const string&, int,int,int,int,int,int,int,int,int,int);
  	int horseFarm;
  	int goatFarm;
  	int llamaFarm;
  	int rabbitFarm;
  	int bisonFarm;
  	int elkFarm;
  	int deerFarm;
  	int minkFarm;
  	int totalFarm;
    void computeFarms();
};




#endif
