#ifndef CONTROL_H
#define CONTROL_H

#include <vector>
#include "Record.h"
#include "Map.h"
#include "View.h"
#include "ReportGenerator.h"

class Control
{

  public:
    ~Control();
    void launch();


  private:
    vector<ReportGenerator*> repGen;
	  View v;
};

#endif
