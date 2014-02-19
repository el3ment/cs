
// vector
// string
// Student


#include <vector>
#include "Student.h"
#include "GlobalTypeDefinitions.h"

#ifndef STUDENTDATABASE_H
#define	STUDENTDATABASE_H

class StudentDatabase {
private:
    std::vector<Student*> database;

public:
    StudentDatabase() : database() {};
    StudentDatabase(const StudentDatabase& orig){ };
    virtual ~StudentDatabase();

    bool addStudent(rawItem rawStudent); // Append to database
    bool addGrade(rawItem rawGrade); // Find, and append to student
    Student* findStudent(std::string id); // Return student by ID
    
    void print(); // Print summaries for entire student list

};

#endif	/* DATABASE_H */

