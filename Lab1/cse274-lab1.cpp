// classes example
#include <iostream>
#include "rectangle.h"

using namespace std;



int main () {
  Rectangle rect; // stack allocation

  Rectangle *pHead = new Rectangle(); // heap allocation


  // creates a copy of the onject in memory
  Rectangle rect2 = rect;

  rect2.set_values(4,5);


  cout << "area for rect2: " << rect2.area() << endl;
  rect.set_values (3,3);
  cout << "area for rect: " << rect.area() << endl;

  //creates a pointer to a rectangle object

  Rectangle *pRect;

  //pointer assignment
    pRect = &rect;

    cout << "area for pointer: " << pRect->area() << endl;
    cout << "memory location for rect: " << pRect<< endl;

  //reference
    Rectangle &refRect;
    //r
    refRect = rect;

  return 0;
}
