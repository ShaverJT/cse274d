#include<iostream>
#include"DLList.h"

using namespace std;
using namespace ods;

int main(){
  
  DLList<int> leven;
  for(int i = 0; i<30; i++){
    leven.add(i);
  }

  DLList<int> lodd = leven.deal();
  
  for(int i =0; i<leven.size(); i++){
    cout <<"entry "<< i << " of leven " << leven.get(i)<< endl;
  }
  for(int i =0; i<lodd.size(); i++){
    cout <<"entry "<< i << " of lodd " << lodd.get(i)<< endl;
  }
  
  
  DLList<int> lr;
  for(int i = 0; i<20; i++){
    lr.add(i);
  }

  for(int i =0; i<lr.size(); i++){
    cout <<"entry before rotate "<< i << " of lr " << lr.get(i)<< endl;
  }
  
  lr.Rotate(5);



  for(int i =0; i<lr.size(); i++){
    cout <<"entry after rotate "<< i << " of lr " << lr.get(i)<< endl;
  }
   


  
  DLList<int> l1;
  DLList<int> l2;
 
  l1.add(1);
  l1.add(2);
  l1.add(3);
  l1.add(4);
 
  l2.add(5);
  l2.add(6);
  l2.add(7);
  l2.add(8);

  cout<<"before absorb" << endl;

  for(int i =0; i<l1.size(); i++){
    cout <<"entry of l1 "<< i << " of l1 " << l1.get(i)<< endl;
  }

  for(int i =0; i<l2.size(); i++){
    cout <<"entry of l2 "<< i << " of l2 " << l2.get(i) <<endl;
  }
  
  l1.Absorb(l2);

  cout<<"after absorb" << endl;
  for(int i =0; i<l1.size(); i++){
    cout <<"entry of l1 "<< i << " of l1 " << l1.get(i)<< endl;
  }

  for(int i =0; i<l2.size(); i++){
    cout <<"entry of l2 "<< i << " of l2 " << l2.get(i) <<endl;
  }



   DLList<int> l;
  l.add(5);
  l.add(5);
  l.add(5);
  l.add(5);
 
  cout << "True " << l.IsPalindrome()<< endl;
 
  l.add(6);

  cout << "Now False " << l.IsPalindrome()<< endl;
  

}
