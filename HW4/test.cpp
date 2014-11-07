#include <climits>
#include <cmath>
#include "BinarySearchTree.h"
#include "utils.h"

using namespace ods;
using namespace std;

bool part1test(){
  BinarySearchTree<BSTNode1<int>,int> part1;

  part1.add(20);
  int height0 = part1.height2(part1.getNode(20)); 
  part1.add(30);
  int height1 = part1.height2(part1.getNode(20)); 
  part1.add(10);
  int height2 = part1.height2(part1.getNode(20)); 
  part1.add(1);
  int height3 = part1.height2(part1.getNode(20)); 
  part1.add(100);
  int height4 = part1.height2(part1.getNode(20)); 
  part1.add(90);
  int height5 = part1.height2(part1.getNode(20)); 
  part1.add(200);
  int height6 = part1.height2(part1.getNode(20)); 
  return (height0==0)&&(height1==1)&&(height2==1)&&(height3==2)&&
    (height4==2)&&(height5==3)&&(height6==3);
}

bool part2test(){
  BinarySearchTree<BSTNode1<int>,int> part2;
  part2.add(20);
  part2.add(30);
  part2.add(10);
  bool shouldbetrue = part2.isBalanced();
  part2.add(5);
  part2.add(1);
  bool shouldbefalse = part2.isBalanced();
  return shouldbetrue && !(shouldbefalse);
}
bool part3test(){
  BinarySearchTree<BSTNode1<int>,int> part3;
  part3.add(20);
  part3.add(10);
  part3.add(15);
  part3.add(30);
  part3.add(25);
  part3.add(40);
  part3.preOrderNumber();
  part3.inOrderNumber();
  part3.postOrderNumbers();
  
  return (part3.getNode(20)->pre_number==1)&&(part3.getNode(10)->pre_number==2)&&
    (part3.getNode(15)->pre_number==3)&&(part3.getNode(30)->pre_number==4)&&
    (part3.getNode(25)->pre_number==5)&&(part3.getNode(40)->pre_number==6)&&
    (part3.getNode(20)->in_number==3)&&(part3.getNode(10)->in_number==1)&&
    (part3.getNode(15)->in_number==2)&&(part3.getNode(30)->in_number==5)&&
    (part3.getNode(25)->in_number==4)&&(part3.getNode(40)->in_number==6)&&
    (part3.getNode(20)->post_number==6)&&(part3.getNode(10)->post_number==2)&&
    (part3.getNode(15)->post_number==1)&&(part3.getNode(30)->post_number==5)&&
    (part3.getNode(25)->post_number==3)&&(part3.getNode(40)->post_number==4);
}

bool part4test(){
  BinarySearchTree<BSTNode1<int>,int> part4;
  part4.add(20);
  part4.add(10);
  part4.add(30);
  part4.add(5);
  part4.add(15);
  part4.getLE(31);
  DLList<int> list =  part4.getLE(13);
  DLList<int> list2 =  part4.getLE(20);

  return (list.get(0)==5)&&(list.get(1)==10)&&
    (list2.get(0)==5)&&(list2.get(1)==10)&&(list2.get(2)==15)&&(list2.get(3)==20);
}

int main(){
    BinarySearchTree<BSTNode1<int>,int> tree;
 
  /* PART 1*/
 cout <<"Part 1 test, 1 for pass 0 for fail:  " << part1test() << endl;

 /* PART 2 */
 cout <<"Part 2 test, 1 for pass 0 for fail:  " << part2test() << endl;
  
 /* PART 3 */
 cout <<"Part 3 test, 1 for pass 0 for fail:  " << part3test() << endl;

 /* PART 4 */
 cout <<"Part 4 test, 1 for pass 0 for fail:  " << part4test() << endl;

  return 0;
}

