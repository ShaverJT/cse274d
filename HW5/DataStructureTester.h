#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
namespace ods {

template<class T>
class DataStructureTester {
protected:
  T list;

public:
  void AddRandom(int i) {
    list.add(i);
    //std::cout << "find " << list.find(i) << std::endl;
  }
  DataStructureTester();
  ~DataStructureTester();
  int DoSequentialAdd(int start, int end, int step);
  int DoRandomAdd(int n);
  int DoSequentialRemove(int start, int end, int step);
  int DoRandomRemove(int n);
  int DoSequentialFind(int start,int  end, int step);
  int DoRandomFind(int n);   
 };
 
 template<class T>
   DataStructureTester<T>:: DataStructureTester(){
 }
 template<class T>
   DataStructureTester<T>::~DataStructureTester(){
 }
 template<class T>
   int DataStructureTester<T>::DoSequentialAdd(int start, int end, int step){
   time_t t = clock();
   for(int i = start; i< end; i = i+step ){
     list.add(i);
   }
   t = clock()-t;
   int mill = (int)((t*1000/CLOCKS_PER_SEC));
   return mill;
 }
 template<class T>
   int DataStructureTester<T>::DoRandomAdd(int n){
   srand(time(NULL));
   time_t t = clock();
   for(int i = 0; i< n; i++){
     list.add(rand() % 100000000);
   }
   t = clock()-t;
   int mill = (int)((t*1000/CLOCKS_PER_SEC));
   return mill;
 }
 template<class T>
   int DataStructureTester<T>::DoSequentialRemove(int start, int end, int step){
   time_t t = clock();
   for(int i = start; i< end; i = i+step ){
     list.remove(i);
   }
   t = clock()-t;
   int mill = (int)((t*1000/CLOCKS_PER_SEC)); 
   return mill;
 }
 template<class T>
   int DataStructureTester<T>:: DoRandomRemove(int n){
   srand(time(NULL));
   time_t t = clock();
   for(int i = 0; i< n; i++){
     list.remove(rand() %  100000000);
   }
   t = clock()-t;
   int mill = (int)((t*1000/CLOCKS_PER_SEC));
   return mill;
 }
 template<class T>
   int DataStructureTester<T>:: DoSequentialFind(int start, int end, int step){
   time_t t = clock();
   for(int i = start; i< end; i = i+step ){
     list.find(i);
   }
   t = clock()-t;
   int mill = (int)((t*1000/CLOCKS_PER_SEC));
   return mill;
 }
 template<class T>
   int DataStructureTester<T>:: DoRandomFind(int n){
   srand(time(NULL));
   time_t t = clock();
   for(int i = 0; i< n; i++){
     list.find(rand() %  100000000);
   }
   t = clock()-t;
   int mill = (int)((t*1000/CLOCKS_PER_SEC));
   return mill;
 }   
 

}
