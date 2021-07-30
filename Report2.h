#ifndef REPORT2_H
#define REPORT2_H

#include "ReportData.h"
#include "CompareBehaviour.h"
#include "ReportGenerator.h"
#include "AscBehaviour.h"
#include "DescBehaviour.h"

class Report2 : public ReportGenerator
{
public:
	Report2(AscBehaviour<float>);
	~Report2();
	virtual void compute();
	virtual void printReport();

private:
	ReportData<float>* dataReport2;
	static const string REGION;
	static const string REPORT_TITLE;
	string formatData(const string&, float, float, float);
};




#endif
