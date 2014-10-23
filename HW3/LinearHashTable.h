/*
 * LinearHashTable.h
 *
 *  Created on: 2011-12-16
 *      Author: morin
 */

#ifndef LINEARHASHTABLE_H_
#define LINEARHASHTABLE_H_
#include <climits>
#include <iostream>
using namespace std;
#include "array.h"
namespace ods {

extern unsigned int tab[4][256];

template<class T>
class LinearHashTable {

	static const int w = 32;
	static const int r = 8;
	array<T> t1;
	array<T> t2;
	int n;   // number of values in T
	int q;   // number of non-null entries in T
	int d;   // t.length = 2^d
	int z;
	T null, del;
	void resize();
	int hash(T x) {
	  return ((unsigned)(z * x)%(1 << d));
	}
	int hash2(T x, int i){
	  return ((unsigned)(hash(x)+i*(1+(hash(x))%((1<<d)-1)))%(1<<d));
	}



public:
	// FIXME: get rid of default constructor
	LinearHashTable();
	LinearHashTable(T null, T del);
	virtual ~LinearHashTable();
	bool add(T x);
	bool addSlow(T x);
	T remove(T x);
	T find(T x);
	int size() { return n; }
	void clear();
	// FIXME: yuck
	void setNull(T null) { this->null = null; t1.fill(null); t2.fill(null); }
	void setDel(T del) { this->del = del; }
	
	
	T get1(int i){
	 return t1[i];
	}
	T get2(int i){
	 return t2[i];
	}
	void set1(int index, T x){
	  t1[index] = x;
	}
	void set2(int index, T x){
	  t2[index] = x;
	}
	
};


/**
 * FIXME: Dangerous - leaves null and del uninitialized
 */
template<class T>
  LinearHashTable<T>::LinearHashTable() : t1(2), t2(2) {
/*
	this->null = null;
	this->del = del;
*/
	n = 0;
	q = 0;
	d = 1;
}


template<class T>
  LinearHashTable<T>::LinearHashTable(T null, T del) : t1(2, null), t2(2, null) {
	this->null = null;
	this->del = del;
	n = 0;
	q = 0;
	d = 1;
	z = rand() | 1;
}

template<class T>
LinearHashTable<T>::~LinearHashTable() {
}

template<class T>
void LinearHashTable<T>::resize() {
 
  d =1;
  while((1<<d) < 3*n) d++;
  array<T> t1new(1<<(d-1), null);
  array<T> t2new(1<<(d-1), null);
  q=n;
  T item;
  int p;
  for(int a = 0; a < (t1.length+t2.length); a++){
    if(a<t1.length) item = t1[a];
    else item = t2[a-t1.length];
    int i = 0;
    if(item != null && item != del){
	p = hash2(item,i);
      while((p<t1new.length && t1new[p] != null) ||
	    (p>=t1new.length && t2new[p-t1new.length]!= null )){
	i++;
	p = hash2(item,i);
      }
      if(p<t1new.length && t1new[p]==null ){
	t1new[p] = item;
      }
      if(p >= t1new.length && t2new[p-t1new.length]==null ){
	t2new[p-t1new.length] = item;
	
      }
      
    }
  
  }
  t1 = t1new;
  t2 = t2new;
  

 }

template<class T>
void LinearHashTable<T>::clear() {
  n = 0;
  q = 0;
  d = 1;
  array<T> tnew1(2, null);
  array<T> tnew2(2, null);
  t1 = tnew1;
  t2 = tnew2;
}

template<class T>
bool LinearHashTable<T>::add(T x) {
  if (find(x) != null) return false;
  if (2*(q+1) > (t1.length+t2.length)) resize();   // max 50% occupancy
  int i = 0;
  int lookup = hash2(x,i);
    while(((lookup<t1.length) && t1[lookup] != null)||
	  ((lookup>t1.length-1) && t2[lookup-(t1.length)] != null)){
      i++;
      lookup = hash2(x, i);
    }
    if(lookup<t1.length){
      if(t1[lookup] == null) q++;
      t1[lookup] = x;
      n++;
    }
    else{
      if(t2[lookup - (t1.length)] == null) q++;
      t2[lookup - (t1.length)] = x;
      n++;
    }
    return true;
}

template<class T>
T LinearHashTable<T>::find(T x) {
  int i = 0;
  int lookup = hash2(x,i);
  while(((lookup<t1.length && t1[lookup] != null) ||
	 (lookup>=t1.length && t2[lookup-t1.length] != null)) &&
	i<100*(t1.length + t2.length)){
    if((lookup<t1.length) && t1[lookup] != del && t1[lookup] == x) return t1[lookup];
    if(lookup>=t1.length && 
       t2[lookup-t1.length] != del &&
       t2[lookup-t1.length] == x) return t2[lookup-t1.length];      
    i++;
    lookup = hash2(x, i);
  }
  return null;
 }

template<class T>
T LinearHashTable<T>::remove(T x) {  
  int i = 0;
  int lookup = hash2(x,i);
  while ((lookup < t1.length && t1[lookup] != null)
	 || (lookup >= t1.length && t2[lookup - t1.length] != null)){
    if(lookup < t1.length && t1[lookup] != del){
      T y = t1[lookup];
      if (y != del && x == y) {
	t1[lookup] = del;
	n--;
	if (8*n < (t1.length+t2.length)) resize(); // min 12.5% occupancy
	return y;
      }
    }
    if(lookup >= t1.length && t2[lookup - t1.length] != del){
      T y = t2[lookup - t1.length];
      if (y != del && x == y) {
	t2[lookup - t1.length] = del;
	n--;
	if (8*n < (t1.length+t2.length)) resize(); // min 12.5% occupancy
	return y;
      }
    }
    i++;  // increment i
    lookup = hash2(x, i);
  }
  return null;
}

template<class T>
bool LinearHashTable<T>::addSlow(T x) {
  if (2*(q+1) > (t1.length+t2.length)) resize();   // max 50% occupancy
  int i = 0;
  int lookup = hash2(x,i);
  while(((lookup<t1.length) && t1[lookup] != null)||
	((lookup>t1.length-1) && t2[lookup-(t1.length)] != null)){
    
    if(lookup<t1.length){
      if(t1[lookup] != del && x == t1[lookup]) return false;
    }
    if(lookup>=t1.length){
      if(t2[lookup - (t1.length)] != del &&
	 x == t2[lookup - t1.length]) return false;  
    }
    i++;
    lookup = hash2(x,i);
  }	  
    

  if(lookup<t1.length){
    t1[lookup] = x;
    n++;
    q++;
  }
  if(lookup>=t1.length){
    t2[lookup - (t1.length)] = x; 
    n++;
    q++;
  }
  return true;
}


} /* namespace ods */
#endif /* LINEARHASHTABLE_H_ */
