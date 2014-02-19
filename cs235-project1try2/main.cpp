/* 
 * File:   main.cpp
 * Author: el3ment
 *
 * Created on January 24, 2013, 12:21 PM
 */

#include <cstdlib>
#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>
#include <set>
#include <vector>
#include <tr1/unordered_map>

using namespace std;

float getGPA(std::string letterGrade){
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
    
    // If letterGrade is found in the map, use it - otherwise, throw an error
    if(gradeMap.find(letterGrade) != gradeMap.end()){
        return gradeMap[letterGrade];
    }
    
    return 0.0;
}

map<std::string, std::string> parseStudents(std::string filename){
    
    std::string line;
    map<std::string,std::string> database;
    std::ifstream fileObject;
    fileObject.open(filename.c_str());
   
    while(getline(fileObject, line)){
        
        std::string id = line;
        getline(fileObject, line);
        std::string name = line;
        getline(fileObject, line);
        std::string address = line;
        getline(fileObject, line);
        std::string phone = line;
        
        database[id] = name;
    }
    
    return database;
}

map<std::string, float> parseGrades(std::string filename){
    
    std::string line;
    map<std::string,float> database;
    map<std::string,float> counts;
    set<string> ids;
    std::ifstream fileObject;
    fileObject.open(filename.c_str());
   
    while(getline(fileObject, line)){
        
        std::string className = line;
        getline(fileObject, line);
        std::string id = line;
        getline(fileObject, line);
        std::string letterGrade = line;
        
        //if(database.find(id) == database.end()){
        //    database[id] = getGPA(letterGrade);
        //}else{
            database[id] += getGPA(letterGrade);
            counts[id] += 1;
            ids.insert(id);
            //database[id] = database[id] / 2;
        //}
    }
    
    for (set<string>::iterator iter = ids.begin(); iter != ids.end(); ++iter){
        database[*iter] = database[*iter] / counts[*iter];
    }
    
    return database;
}

vector<string> parseQueries(string filename){
    string line;
    vector<string> list;
    ifstream file;
    file.open(filename.c_str());
    
    while(getline(file, line)){
        list.push_back(line);
    }
    
    return list;
}

int main(int argc, char** argv) {
    
    map<std::string,std::string> studentNames;
    map<std::string,float> grades;
    ofstream outputFile;
    vector<std::string> queries;

    studentNames = parseStudents(argv[1]);
    grades = parseGrades(argv[2]);
    queries = parseQueries(argv[3]);
    
    outputFile.open(argv[4]);
    outputFile << fixed << setprecision(2) << setfill('0');
    cout << fixed << setprecision(2) << setfill('0');
    for(unsigned int i = 0; i < queries.size(); i++){
        if(studentNames.count(queries[i]) == 1){
                cout << queries[i] << "    " << grades[queries[i]] << "    " << studentNames[queries[i]] << endl;
                outputFile << queries[i] << "    " << grades[queries[i]] << "    " << studentNames[queries[i]] << endl;
        }
    }
    outputFile.close();
    
    return 0;
}