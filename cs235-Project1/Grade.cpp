/* 
 * File:   Grade.cpp
 * Author: robert
 * 
 * Created on January 16, 2013, 8:54 AM
 */

#include <iostream>
#include <string>
#include <tr1/unordered_map>
#include "Grade.h"

Grade::Grade(std::vector<std::string> rawGrade){
    this->parseRawGrade(rawGrade);
}

// Setters
void Grade::id(std::string id){ this->_id = id; }
void Grade::letterGrade(std::string letterGrade){ this->_letterGrade = letterGrade; }
void Grade::setClassName(std::string className){ this->_className = className;}

// Getters
const std::string Grade::id(){ return this->_id; }
const std::string Grade::className(){ return this->_className; }
const std::string Grade::letterGrade(){ return this->_letterGrade; }

// Parse the LSV
void Grade::parseRawGrade(rawItem rawGrade){
    // Assign, and store data points
    std::string className = rawGrade.at(0);
    std::string id = rawGrade.at(1);
    std::string letterGrade = rawGrade.at(2);
    
    this->id(id);
    this->letterGrade(letterGrade);
    this->setClassName(className);
}

// Convert Letter Grade to Grade Points (to use for GPA calculation)
float Grade::getGradePoints(){
    std::tr1::unordered_map<std::string,float> gradeMap;
    gradeMap["A+"] = 4.0;
    gradeMap["A"]  = 4.0;
    gradeMap["A-"] = 3.7;
    gradeMap["B+"] = 3.4;
    gradeMap["B"]  = 3.0;
    gradeMap["B-"] = 2.7;
    gradeMap["C+"] = 2.4;
    gradeMap["C"]  = 2.0;
    gradeMap["C-"] = 1.7;
    gradeMap["D+"] = 1.4;
    gradeMap["D"]  = 1.0;
    gradeMap["D-"] = 0.7;
    gradeMap["E"]  = 0.0;
    
    std::string letterGrade = this->letterGrade();
    
    // If letterGrade is found in the map, use it - otherwise, throw an error
    if(gradeMap.find(letterGrade) != gradeMap.end()){
        return gradeMap[letterGrade];
    }
    
    return 0.0;

}

