#ifndef ASCBEHAVIOUR_H
#define ASCBEHAVIOUR_H

#include "CompareBehaviour.h"

template <class T>
class AscBehaviour : public CompareBehaviour<T>
{
  public:
    virtual bool compare(T, T);


};

template <class T>
bool AscBehaviour<T>::compare(T a, T b){
  //compares 2 objects in ascending order
  if(a > b){
    return true;
  }else{
    return false;
  }
}


#endif
