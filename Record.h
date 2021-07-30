#ifndef RECORD_H
#define RECORD_H

#include <iostream>
#include <string>
using namespace std;

class Record
{

  public:
    Record(int = 0, const string& = "default", const string& = "default", const string& = "default", int = 0, int = 0);
    int getYear() const;
    string getRegion() const;
  	string getSubRegion() const;
  	string getAnimalType() const;
  	int getNumAnimals() const;
  	int getNumFarms() const;

  private:
    int year;
    string region;
    string subRegion;
    string animalType;
    int numFarms;
    int numAnimals;


};

#endif
