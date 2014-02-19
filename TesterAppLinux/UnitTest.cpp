/* 
 * File:   UnitTest.cpp
 * Author: robert
 * 
 * Created on February 4, 2013, 9:07 AM
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <algorithm>
#include "UnitTest.h"

UnitTest::UnitTest() {
}

UnitTest::UnitTest(const UnitTest& orig) {
}

UnitTest::~UnitTest() {
}

string UnitTest::buildCommand(string executeable){
    
    string command = executeable;
    
    for(set<string>::iterator iterator = this->inputFiles.begin(); iterator != this->inputFiles.end(); iterator++) {
        command += " " + *iterator;
    }
    
    command += " " + this->assertTest;
    
    return command;
}

bool UnitTest::compareFiles(string filename1, string filename2){
    
    bool returnBool = true;
    
    string linefile1;
    string linefile2;
    
    unsigned int lineNumber = 0;
    
    ifstream file1;
    ifstream file2;
    
    file1.open(filename1.c_str());
    file2.open(filename2.c_str());
    
    do{
        getline(file1, linefile1);
        getline(file2, linefile2);
        
        linefile1.erase(std::find_if(linefile1.rbegin(), linefile1.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), linefile1.end());
        linefile2.erase(std::find_if(linefile2.rbegin(), linefile2.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), linefile2.end());
        
        if(linefile1.compare(linefile2) != 0 || !returnBool){
            cout << "   Line #" << lineNumber << " - Failure" << endl;
            cout << "     Expecting : " << linefile1 << " (size " << linefile1.size() << ")" << endl;
            cout << "           Got : " << linefile2 << " (size " << linefile2.size() << ")" << endl;
            return false;
        }
        
        lineNumber++;
        
    }while(file1 && file2 && !file1.eof() && !file2.eof());
    
    file1.close();
    file2.close();
    
    return returnBool;
    
}

void UnitTest::emptyAssertionTestFile(){
    ofstream assertionFile;
    assertionFile.open(this->assertTest.c_str());
    assertionFile.clear();
    assertionFile.close();
}

bool UnitTest::assert(string executeable){
    
    //this->emptyAssertionTestFile();
    
    cout << "Test #" << this->testNumber << endl;
    system(this->buildCommand(executeable).c_str());
    
    cout << endl;
    
    return this->compareFiles(this->outputFile.name, this->assertTest);
}

void UnitTest::addFile(testFile file){
    
    this->testNumber = file.number;
    
    if(file.type.compare("input") == 0){
        this->inputFiles.insert(file.name);
    }else if(file.type.compare("output") == 0){
        this->outputFile = file;
    }
}
