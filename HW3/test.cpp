#include <climits>
#include "ChainedHashTable.h"
#include "LinearHashTable.h"

using namespace std;
using namespace ods;

int main(){
  //LinearHashTable
  LinearHashTable<int> line(-1,-2);

  for(int i = 1; i<2500; i++){
    cout << "Adding slowly " <<i<<" element: "  << line.addSlow(i)<< endl;
  }
  for(int i = 2500; i<5000; i++){
    cout << "Adding " <<i<<" element: "  << line.add(i)<< endl;
  }
  for(int i = 1; i<5002; i++){
    cout << "Removing " <<i<<" element: "  << line.remove(i)<< endl;
  }
  

  // ChainedHashTable 
  ChainedHashTable<int> chain;
  chain.SetLocalFactor(5);

  for(int i = 1; i<5000; i++){
    chain.add(i);
  }

  // chain.SetLocalFactor(10);
  
  cout <<"items in hashtable " <<chain.size()<< endl;

  cout <<"Longest list :" <<chain.GetLongestList() << endl;
  
} 



