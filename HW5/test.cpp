//============================================================================
// Name        : hw5.cpp
// Author      : John Shaver
// Version     :
// Copyright   : Your copyright notice
// Description : DataStructureTester
//============================================================================

#include <iostream>
#include "ChainedHashTable.h"
#include "DataStructureTester.h"
#include "LinearHashTable.h"
#include "BinarySearchTree.h"
#include "RedBlackTree.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

using namespace std;
using namespace ods;

int main() {
  DataStructureTester<BinarySearchTree<BSTNode1<int>,int> >  test;
  int total_sequential_add_BST = 0;
  int total_sequential_find_BST = 0;
  int total_sequential_remove_BST = 0;
  int total_random_add_BST = 0;
  int total_random_find_BST = 0;
  int total_random_remove_BST = 0;
  for(int i = 0;i < 20; i++){
   total_sequential_add_BST += test.DoSequentialAdd(0,50000,1);
   total_sequential_find_BST += test.DoSequentialFind(0,50000,1);
   total_sequential_remove_BST += test.DoSequentialRemove(0,50000,1);
   total_random_add_BST += test.DoRandomAdd(50000);
   total_random_find_BST += test.DoRandomFind(50000);
   total_random_remove_BST += test.DoRandomRemove(50000);
   // cout << "Test " << i << " Done" <<endl;
  }
  cout <<"Binary Search Tree Sequetial Add Average: "<<(double)(total_sequential_add_BST/20) <<" Milliseconds"<< endl;
  cout <<"Binary Search Tree Sequetial Find Average: "<<(double)(total_sequential_find_BST/20)<<" Milliseconds"<< endl;
  cout <<"Binary Search Tree Sequetial Remove Average: "<<(double)(total_sequential_remove_BST/20)<<" Milliseconds"<< endl;
  cout <<"Binary Search Tree Random Add Average: "<<(double)(total_random_add_BST/20)<<" Milliseconds"<< endl;
  cout <<"Binary Search Tree Random Find Average: "<<(double)(total_random_find_BST/20)<<" Milliseconds"<< endl;
  cout <<"Binary Search Tree Random Remove Average: "<<(double)(total_random_remove_BST/20)<<" Milliseconds"<< endl;
  cout << endl;

  DataStructureTester<RedBlackTree<RedBlackNode1<int>,int> > test2;
  int total_sequential_add_RBT = 0;
  int total_sequential_find_RBT = 0;
  int total_sequential_remove_RBT = 0;
  int total_random_add_RBT = 0;
  int total_random_find_RBT = 0;
  int total_random_remove_RBT = 0;
  for(int i = 0;i < 20; i++){
   total_sequential_add_RBT += test2.DoSequentialAdd(0,50000,1);
   total_sequential_find_RBT += test2.DoSequentialFind(0,50000,1);
   total_sequential_remove_RBT += test2.DoSequentialRemove(0,50000,1);
   total_random_add_RBT += test2.DoRandomAdd(50000);
   total_random_find_RBT += test2.DoRandomFind(50000);
   total_random_remove_RBT += test2.DoRandomRemove(50000);
   // cout << "Test " << i << " Done" <<endl;
  }
  cout <<"Red Black Tree Sequetial Add Average: "<<(double)(total_sequential_add_RBT/20) <<" Milliseconds"<< endl;
  cout <<"Red Black Tree Sequetial Find Average: "<<(double)(total_sequential_find_RBT/20)<<" Milliseconds"<< endl;
  cout <<"Red Black Tree Sequetial Remove Average: "<<(double)(total_sequential_remove_RBT/20)<<" Milliseconds"<< endl;
  cout <<"Red Black Tree Random Add Average: "<<(double)(total_random_add_RBT/20)<<" Milliseconds"<< endl;
  cout <<"Red Black Tree Random Find Average: "<<(double)(total_random_find_RBT/20)<<" Milliseconds"<< endl;
  cout <<"Red Black Tree Random Remove Average: "<<(double)(total_random_remove_RBT/20)<<" Milliseconds"<< endl;
  cout << endl;

  DataStructureTester<ChainedHashTable<int> > test3;
  int total_sequential_add_CHT = 0;
  int total_sequential_find_CHT = 0;
  int total_sequential_remove_CHT = 0;
  int total_random_add_CHT = 0;
  int total_random_find_CHT = 0;
  int total_random_remove_CHT = 0;
  for(int i = 0;i < 20; i++){
   total_sequential_add_CHT += test3.DoSequentialAdd(0,50000,1);
   total_sequential_find_CHT += test3.DoSequentialFind(0,50000,1);
   total_sequential_remove_CHT += test3.DoSequentialRemove(0,50000,1);
   total_random_add_CHT += test3.DoRandomAdd(50000);
   total_random_find_CHT += test3.DoRandomFind(50000);
   total_random_remove_CHT += test3.DoRandomRemove(50000);
   // cout << "Test " << i << " Done" <<endl;
  }
  cout <<"Chained Hash Table Sequetial Add Average: "<<(double)(total_sequential_add_CHT/20) <<" Milliseconds"<< endl;
  cout <<"Chained Hash Table Sequetial Find Average: "<<(double)(total_sequential_find_CHT/20)<<" Milliseconds"<< endl;
  cout <<"Chained Hash Table Sequetial Remove Average: "<<(double)(total_sequential_remove_CHT/20)<<" Milliseconds"<< endl;
  cout <<"Chained Hash Table Random Add Average: "<<(double)(total_random_add_CHT/20)<<" Milliseconds"<< endl;
  cout <<"Chained Hash Table Random Find Average: "<<(double)(total_random_find_CHT/20)<<" Milliseconds"<< endl;
  cout <<"Chained Hash Table Random Remove Average: "<<(double)(total_random_remove_CHT/20)<<" Milliseconds"<< endl;
  cout << endl;



  DataStructureTester<LinearHashTable<int> > test4;
  int total_sequential_add_LHT = 0;
  int total_sequential_find_LHT = 0;
  int total_sequential_remove_LHT = 0;
  int total_random_add_LHT = 0;
  int total_random_find_LHT = 0;
  int total_random_remove_LHT = 0;
  for(int i = 0;i < 20; i++){
   total_sequential_add_LHT += test4.DoSequentialAdd(0,50000,1);
   total_sequential_find_LHT += test4.DoSequentialFind(0,50000,1);
   total_sequential_remove_LHT += test4.DoSequentialRemove(0,50000,1);
   total_random_add_LHT += test4.DoRandomAdd(50000);
   total_random_find_LHT += test4.DoRandomFind(50000);
   total_random_remove_LHT += test4.DoRandomRemove(50000);
   //   cout << "Test " << i << " Done" <<endl;
  }
  cout <<"Linear Hash Table Sequetial Add Average: "<<(double)(total_sequential_add_LHT/20) <<" Milliseconds"<< endl;
  cout <<"Linear Hash Table Sequetial Find Average: "<<(double)(total_sequential_find_LHT/20)<<" Milliseconds"<< endl;
  cout <<"Linear Hash Table Sequetial Remove Average: "<<(double)(total_sequential_remove_LHT/20)<<" Milliseconds"<< endl;
  cout <<"Linear Hash Table Random Add Average: "<<(double)(total_random_add_LHT/20)<<" Milliseconds"<< endl;
  cout <<"Linear Hash Table Random Find Average: "<<(double)(total_random_find_LHT/20)<<" Milliseconds"<< endl;
  cout <<"Linear Hash Table Random Remove Average: "<<(double)(total_random_remove_LHT/20)<<" Milliseconds"<< endl;
  cout << endl;

  
  return 0;
}
