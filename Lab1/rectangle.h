/*
 * rectangle.h
 *
 *  Created on: Aug 27, 2014
 *      Author: shaverjt
 */

#ifndef RECTANGLE_H_
#define RECTANGLE_H_

using namespace std;

class Rectangle {
  private:
    int width, height;

  public:
    Rectangle();
    void set_values (int,int);
    int area();
};




#endif /* RECTANGLE_H_ */
