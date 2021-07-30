#ifndef MAP_H
#define MAP_H

#include <vector>
#include "Record.h"




template <class T>
class Map
{
  public:
    Map();
    void add(T , Record*);
    int getKeySize();
    vector<T>& getKey();
    vector<Record*>& operator[](T);

  private:
    vector<T> keys;
    vector<vector<Record*>> values;
};



template <class T>
Map<T>::Map(){}



template <class T>
void Map<T>::add(T key, Record* rec){
  //error check to see if record ptr is null
  if(rec == 0){
    cerr << "record pointer in Map class template add() is null" << endl;
    return;
  }
  //loop through the key collection, if the given key is in the collection add rec to the back of values collection
  for(unsigned int i = 0; i < keys.size(); ++i){
    if(key == keys[i]){
      values[i].push_back(rec);
      return;
    }
  }
  //if not in the key collecton add key to the back of keys collection and add rec to a new collection, pushed back on values collection
  keys.push_back(key);
  vector<Record*> temp;
  temp.push_back(rec);
  values.push_back(temp);
}



template <class T>
int Map<T>::getKeySize(){
  return keys.size();
}



template <class T>
vector<T>& Map<T>::getKey(){
  return keys;
}



template <class T>
vector<Record*>& Map<T>::operator[](T key){
    //loops through collection of keys to find key matching paramater
    for(unsigned int i = 0; i < keys.size(); ++i){
      //returns reference to element of values corresponding to key
      if(key == keys[i]){
        return values[i];
      }
    }
    //throws exception if key not found
    throw "Given key is not found!";
}



#endif
