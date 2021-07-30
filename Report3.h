#ifndef REPORT3_H
#define REPORT3_H

#include "ReportData.h"
#include "CompareBehaviour.h"
#include "ReportGenerator.h"
#include "AscBehaviour.h"
#include "DescBehaviour.h"

class Report3 : public ReportGenerator
{
public:
	Report3(DescBehaviour<int>);
	~Report3();
	virtual void compute();
	virtual void printReport();

private:
	ReportData<int>* dataReport3;
	static const string ANIMAL_TYPE;
	static const string REPORT_TITLE;
	static const int YEAR;
	static const string SUB;
	static const string REGION;
	string formatData(const string&, const string&, int);
};




#endif
