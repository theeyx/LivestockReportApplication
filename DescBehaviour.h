#ifndef DESCBEHAVIOUR_H
#define DESCBEHAVIOUR_H

#include "CompareBehaviour.h"


template <class T>
class DescBehaviour : public CompareBehaviour<T>
{
  public:
    virtual bool compare(T, T);


};

template <class T>
bool DescBehaviour<T>::compare(T a, T b){
  //compares 2 objects to descending order
  if(a <= b){
    return true;
  }else{
    return false;
  }
}


#endif
