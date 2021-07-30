#ifndef REPORTDATA_H
#define REPORTDATA_H

#include <string>
#include <vector>
#include "CompareBehaviour.h"
using namespace std;



template <class T>
class ReportData
{
  class ReportRow
  {
    public:
      ReportRow(T k = NULL, const string& r = "default"){
        key = k;
        row =r;
      }
      T key;
      string row;
  };

  template <class V>
  friend ostream &operator << (ostream &output, const ReportData<V> &r);


  public:
    ReportData(CompareBehaviour<T>* = NULL);
    ~ReportData();
    void add(T, string);

  private:
    vector<ReportData::ReportRow*> rowCollection;
    CompareBehaviour<T>* behaviourComp;


};



template <class T>
ReportData<T>::ReportData(CompareBehaviour<T>* c){
  behaviourComp = c;
}



template <class T>
ReportData<T>::~ReportData(){
  for(unsigned int i = 0; i < rowCollection.size(); ++i){
    delete rowCollection[i];
  }
}



template <class T>
void ReportData<T>::add(T key, string row){
  typename vector<ReportData::ReportRow*>::iterator itr;
  //loop through report row collection until we find intersection by comparing each rows key to the param key
  for( itr = rowCollection.begin(); (itr != rowCollection.end())&&(behaviourComp->compare(key,(*itr)->key)); ++itr){
    ;
  }
  //when we find the intersection we insert the data into the report row collection in correct position
  ReportData::ReportRow* reportRowPtr = new ReportData::ReportRow(key,row);
  rowCollection.insert(itr, reportRowPtr);
}



template <class T>
ostream &operator << (ostream &output, const ReportData<T> &r){
  //loops through the report, prints out all the rows of report
  for(unsigned int i = 0; i < r.rowCollection.size(); ++i){
    output << r.rowCollection[i]->row <<endl;
  }
  return output;
}


#endif
