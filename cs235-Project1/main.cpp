/* 
 * File:   main.cpp
 * Author: robert
 *
 * Created on January 16, 2013, 8:52 AM
 */

#include <cstdlib>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include "StudentDatabase.h"
#include "GlobalTypeDefinitions.h"

rawList parseFile(std::string filename, int lineCountPerGroup){
    
    std::fstream file;
    std::string line;
    int key = 0;
    std::vector<std::string> fileVector;
    rawList output;
    
    file.open(filename.c_str()); // Convert C++ String to C String
    while(getline(file, line)){
        fileVector.push_back(line);
    }
    file.close(); // Finish and close
    
    for(unsigned int i = 0; i < fileVector.size() / lineCountPerGroup; i++){
        
        std::vector<std::string> item; // Temporary item holder
        
        for(int j = 0; j < lineCountPerGroup; j++){
            item.push_back(fileVector.at(key)); // Add the line to the item
            key++;
        }
        if(item.size() > 0){ // only if a complete line was added
            output.push_back(item); // Add the item to the list
        }
        
        item.clear(); // Empty the item to reuse the object
        
    }
    
    return output; // Send back the list
}


int main(int argc, char** argv) {
 
    StudentDatabase database;
    
    if(argc >= 4){
        
        std::string studentFilename = argv[1];
        std::string gradeFilename = argv[2];
        std::string queryFilename = argv[3];
        std::string reportFilename = (argc > 4) ? argv[4] : "";
        
        
        
        //Add each student to the database
        rawList students = parseFile(studentFilename, 4);
        for(unsigned int i = 0; i < students.size(); i++){
            database.addStudent(students.at(i));
            // If addStudent returns false, it's because it's a duplicate
        }

        // Read each grade, and ask the database to find the student, and add
        // the grade
        rawList grades = parseFile(gradeFilename, 3);
        for(unsigned int i = 0; i < grades.size(); i++){
            database.addGrade(grades.at(i));
        }

        // Read the queries, and look for each student, and print the summary
        rawList queries = parseFile(queryFilename, 1);
        std::ofstream reportFile;
        reportFile.open(reportFilename.c_str());
        for(unsigned int i = 0; i < queries.size(); i++){
            std::vector<std::string> queryEntry = queries.at(i);
            std::string actualQuery = queryEntry.at(0);
            //std::cout << "'" << actualQuery << "'" << std::endl;
            
            actualQuery.erase(actualQuery.find_last_not_of(" \n\r\t")+1);
            actualQuery.erase(0, actualQuery.find_first_not_of(" \n\r\t"));
            
            Student* queriedStudent = database.findStudent(actualQuery);
            
            // If the student exists
            if(queriedStudent){

                if(!reportFilename.empty()){ // If the user asked for a report
                    queriedStudent->printSummary(reportFile);
                }

                // Print it to the screen
                queriedStudent->printSummary();

            }
        }

        // Close up the file
        reportFile.close();
        
    }
    
    return 0;
}