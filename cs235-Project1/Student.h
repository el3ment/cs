#include <vector>
#include <string>
#include "Grade.h"
#include "GlobalTypeDefinitions.h"

#ifndef STUDENT_H
#define	STUDENT_H

class Student {
    
private:
    std::string _id;
    std::string _name;
    std::string _address;
    std::string _phone;
    std::vector<Grade*> _grades;
    
public:
    Student(){ };
    Student(const Student& orig){ };
    Student(rawItem rawStudent); // For convenience mostly
    virtual ~Student();
    
    // Setters
    void id(std::string id);
    void name(std::string name);
    void address(std::string address);
    void phone(std::string phone);
    
    
    // Getters
    const std::string id();
    const std::string name();
    const std::string address();
    const std::string phone();
    
    // Logic Functions
    void parseData(rawItem); // Read LSV data
    void addGrade(Grade* gradeObject); // Append the grade to _grade
    float calculateGPA(); // Average the grades
    void printSummary(); // Print a simple summary to the screen
    void printSummary(std::ostream &stream); // Print a simple summary to a file

};

#endif	/* STUDENT_H */

