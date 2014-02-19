/* 
 * File:   StudentDatabase.cpp
 * Author: robert
 * 
 * Created on January 16, 2013, 9:32 AM
 */

#include <iostream>
#include <vector>
#include <string>
#include "StudentDatabase.h"


StudentDatabase::~StudentDatabase(){
    for(unsigned int i = 0; i < this->database.size(); i++){
        delete this->database.at(i);
    }
}

// Create and append student to database,
bool StudentDatabase::addStudent(rawItem rawStudent){
    
    Student* newStudent = new Student(rawStudent); // Create the object
    
    // if the student was created, and it's not already in the system
    if(newStudent){
        this->database.push_back(newStudent);
        return true;
    }
    
    delete newStudent;
    
    // If we make it this far, it's probably becuase the student requested is a duplicate
    return false;
}

// Find student, and add the grade
bool StudentDatabase::addGrade(rawItem rawGrade){
    Grade* gradeObject = new Grade(rawGrade);
    Student* foundStudent = this->findStudent(gradeObject->id());
    if(foundStudent){ // If the student was found
        foundStudent->addGrade(gradeObject);
        return true;
    }
    
    delete gradeObject;
    delete foundStudent;
    
    // ID was not found in student list
    return false;
}

// Search a student by ID, and return a pointer to the student
Student* StudentDatabase::findStudent(std::string id){
    if(!id.empty()){
        for(unsigned int i = 0; i < this->database.size(); i++){
            Student* selectedStudent = this->database.at(i);
            //std::cout << "    Testing : " << selectedStudent->id() << std::endl;
            if(id.compare(selectedStudent->id()) == 0){
                //std::cout << "    Found!" << std::endl;
                return selectedStudent;
            }
        }
    }
    
    // If it couldn't be found
    return NULL;
}

// Loop through the database, and print a summary for each student
void StudentDatabase::print(){
    for(unsigned int i = 0; i < this->database.size(); i++){
        Student* student = this->database.at(i);
        student->printSummary();
    }
}