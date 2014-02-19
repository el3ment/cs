// Student
// string
#include <vector>
#include <string>
#include "GlobalTypeDefinitions.h"

#ifndef GRADE_H
#define	GRADE_H

class Grade {
    
private:
    // TODO : Add Student* parent
    std::string _id;
    std::string _letterGrade;
    std::string _className;

public:
    Grade(){ };
    Grade(const Grade& orig){ };
    Grade(rawItem rawGrade);
    virtual ~Grade(){ };
    
    // Setters
    void id(std::string id);
    void setClassName(std::string className);
    void letterGrade(std::string letterGrade);
    
    // Getters
    const std::string id();
    const std::string className();
    const std::string letterGrade();
    
    // Logic
    void parseRawGrade(std::vector<std::string> rawGrade); // Read LSV
    float getGradePoints(); // Converts _letterGrade to gradePoints
};

#endif	/* GRADE_H */

