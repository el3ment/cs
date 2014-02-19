/* 
 * File:   Point.h
 * Author: robert
 *
 * Created on February 9, 2013, 10:42 PM
 */

#ifndef POINT_H
#define	POINT_H

#include <iostream>

class Point {
public:
    Point();
    Point(unsigned int row, unsigned int column);
    Point(const Point& orig);
    virtual ~Point();
    unsigned int row;
    unsigned int column;
private:

};

inline bool operator==(const Point& lhs, const Point& rhs){ 
    return lhs.row == rhs.row && rhs.row == rhs.row &&
           lhs.column == rhs.column && rhs.column == lhs.column;
} 
inline bool operator!=(const Point& lhs, const Point& rhs){ return !operator==(lhs,rhs); } 
inline bool operator< (const Point& lhs, const Point& rhs){
    
    if(lhs.row < rhs.row || (lhs.row == rhs.row && lhs.column < rhs.column)){
      return true;
    }
    
    return false;
    
} 
inline bool operator> (const Point& lhs, const Point& rhs){ return  operator< (rhs,lhs); } 
inline bool operator<=(const Point& lhs, const Point& rhs){ return !operator> (lhs,rhs); } 
inline bool operator>=(const Point& lhs, const Point& rhs){ return !operator< (lhs,rhs); }

#endif	/* POINT_H */

