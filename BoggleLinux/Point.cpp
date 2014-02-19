/* 
 * File:   Point.cpp
 * Author: robert
 * 
 * Created on February 9, 2013, 10:42 PM
 */

#include "Point.h"

Point::Point() {
}
Point::Point(unsigned int row, unsigned int column){
    this->row = row;
    this->column = column;
}

Point::Point(const Point& orig) {
    this->row = orig.row;
    this->column = orig.column;
}

Point::~Point() {
}
