/* 
 * File:   Student.cpp
 * Author: robert
 * 
 * Created on January 16, 2013, 8:54 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include "Student.h"


Student::Student(std::vector<std::string> rawStudent){
    this->parseData(rawStudent);
}

Student::~Student(){
    for(unsigned int i = 0; i < this->_grades.size(); i++){
        delete this->_grades.at(i);
    }
};

// Setters
void Student::id(std::string id){ this->_id = id; }
void Student::name(std::string name){ this->_name = name; }
void Student::address(std::string address){ this->_address = address; }
void Student::phone(std::string phone){ this->_phone = phone; }

// Getters
const std::string Student::id(){ return this->_id;}
const std::string Student::name(){ return this->_name;}
const std::string Student::address(){ return this->_address;}
const std::string Student::phone(){ return this->_phone;}

void Student::parseData(rawItem rawStudent){
    
    // Assign each raw line to the proper variable.
    std::string id = rawStudent.at(0);
    std::string name = rawStudent.at(1);
    std::string address = rawStudent.at(2);
    std::string phone = rawStudent.at(3);
    
    // Call the setters for each one.
    this->id(id);
    this->name(name);
    this->address(address);
    this->phone(phone);
}

// Append the grade to the student
// If needed, some verification would be appropriate here.
void Student::addGrade(Grade* gradeObject){
    this->_grades.push_back(gradeObject);
}

// Add up, and average the grade points for each grade
float Student::calculateGPA(){
    // Are there any grades to calculate from?
    if(this->_grades.size() > 0){
        float sum = 0;
        for(unsigned int i = 0; i < this->_grades.size(); i++){
            sum += this->_grades.at(i)->getGradePoints();
        }
        return sum / this->_grades.size();
    }else{
        // There are no grades to calculate GPA from
        return 0.0;
    }
}

// Print ID, GPA, and Name of this student to the screen
void Student::printSummary(){
    this->printSummary(std::cout);
}

void Student::printSummary(std::ostream &stream){
    stream << std::fixed << std::setprecision(2) << std::setfill('0');
    stream << this->id() << "  " << this->calculateGPA() << "   " << this->name() << std::endl;
}