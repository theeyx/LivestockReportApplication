#include <iostream>
#include <string>

#include "Record.h"
using namespace std;

Record::Record(int y, const string& r, const string& s, const string& a, int f, int n){
  year = y;
  region = r;
  subRegion = s;
  animalType = a;
  numFarms = f;
  numAnimals = n;
}


int Record::getYear() const{
  return year;
}

int Record::getNumAnimals() const {
	return numAnimals;
}

int Record::getNumFarms() const {
	return numFarms;
}

string Record::getRegion() const{
  return region;
}

string Record::getSubRegion() const {
	return subRegion;
}

string Record::getAnimalType() const {
	return animalType;
}
