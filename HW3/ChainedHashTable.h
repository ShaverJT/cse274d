/*
 * ChainedHashTable.h
 *
 *  Created on: 2011-11-30
 *      Author: morin
 */

#ifndef CHAINEDHASHTABLE_H_
#define CHAINEDHASHTABLE_H_
#include <climits>
#include "array.h"
#include "utils.h"
#include "ArrayStack.h"
#include "DLList.h"

namespace ods {

template<class T>
class ChainedHashTable {
protected:
	typedef DLList<T> List;
	T null;
	array<List> t;
	float loadfactor;
	int n;
	int d;
	int z;
	static const int w = 32; //sizeof(int)*8;
	void allocTable(int m);
	void resize();
	int hash(T x) {
	  return ((unsigned)(z * x)%(1 << d));
      	}

public:
	ChainedHashTable();
	virtual ~ChainedHashTable();
	bool add(T x);
	T remove(T x);
	T find(T x);
	int size() {
		return n;
	}
	void SetLocalFactor(float f){
	  loadfactor = f;
	  resize();
	}
	int GetLongestList();
	void clear();
};

/**
 * FIXME:  A copy-constructor for arrays would be useful here
 */
template<class T>
void ChainedHashTable<T>::resize() {
  d = 1;
  while (1<<d <= n/loadfactor) d++;
  n = 0;
  array<List> newTable(1<<d);
  for (int i = 0; i < t.length; i++) {
    for (int j = 0; j < t[i].size(); j++) {
      T x = t[i].get(j);
      newTable[hash(x)].add(x);
      n++;
    }
  }
  t = newTable;
}


template<class T>
ChainedHashTable<T>::ChainedHashTable() : t(2) {
  n = 0;
  d = 1;
  null = INT_MIN;
  z = rand() | 1;     // is a random odd integer
  loadfactor = 1;
}



template<class T>
ChainedHashTable<T>::~ChainedHashTable() {
}


template<class T>
bool ChainedHashTable<T>::add(T x) {
  if (find(x) != null) return false;
  if (n+1 > loadfactor * t.length) resize();
  t[hash(x)].add(x);
  n++;
  return true;
}


template<class T>
T ChainedHashTable<T>::remove(T x) {
  int j = hash(x);
  for (int i = 0; i < t[j].size(); i++) {
    T y = t[j].get(i);
    if (x == y) {
      t[j].remove(i);
      n--;
      return y;
    }
  }
  return null;
}


template<class T>
T ChainedHashTable<T>::find(T x) {
  int j = hash(x);
  for (int i = 0; i < t[j].size(); i++)
    if (x == t[j].get(i))
      return t[j].get(i);
  return null;
}


template<class T>
void ChainedHashTable<T>::clear() {
  n = 0;
  d = 1;
  array<List> b(2);
  t = b;
}

 template<class T>
   int ChainedHashTable<T>::GetLongestList(){
   int longestsize = 0;
   for(int i =0; i<t.length; i++){
     if(t[i].size()>longestsize){
       longestsize = t[i].size();
     }
   }
   return longestsize;
 }






} /* namespace ods */
#endif /* CHAINEDHASHTABLE_H_ */



/*
(hash(x)+i*(1+(hash(x))%(m-1)))%m
*/
