/* 
 * File:   main.cpp
 * Author: robert
 *
 * Created on February 4, 2013, 8:58 AM
 */

#include <cstdlib>
#include <dirent.h>
#include <iostream>
#include <vector>
#include <regex.h>
#include <map>
#include <string>
#include <algorithm>

#include "UnitTest.h"

using namespace std;

const string EXECUTEABLENAME = "CompiledByTester";
const string TESTOUTPUTFILENAME = "testOutputAssertion.txt";

vector<string> readDirectory(string folder){
    
    DIR *dir;
    struct dirent *ent;
    vector<string> list;
    
    if ((dir = opendir (folder.c_str())) != NULL) {
      /* print all the files and directories within directory */
      while ((ent = readdir (dir)) != NULL) {
        list.push_back(folder + string(ent->d_name));
      }
      closedir (dir);
    }
    
    return list;

}

bool isInputFile(string name){
    reverse(name.begin(), name.end());
    if(name.substr(7, 2).compare("ni") == 0 &&
       name.substr(0, 4).compare("txt.") == 0){
        return true;
    }
    return false;
}

bool isOutputFile(string name){
    reverse(name.begin(), name.end());
    if(name.substr(6, 3).compare("tuo") == 0 &&
       name.substr(0, 4).compare("txt.") == 0){
        return true;
    }
    return false;
}

testFile parseFile(string name){
    string reversed = name;
    reverse(reversed.begin(), reversed.end());
    testFile output;
    
    if(isInputFile(name)){
        if(reversed.size() >= 9){
            output.type = "input";
            output.name = name;
            output.letter = reversed.substr(4, 1);
            output.number = reversed.substr(5, 2);
            output.parsed = true;
            return output;
        }
        
    }else if(isOutputFile(name)){
        if(name.size() >= 9){
            output.type = "output";
            output.name = name;
            output.number = reversed.substr(4, 2);
            output.parsed = true;
            return output;
        }
        
    }
    
    output.parsed = false;
    
    return output;
}

string compile(string directory){
    
    string command = "g++ -Wall " + directory + "*.cpp -o " + directory + EXECUTEABLENAME;
    system(command.c_str());
    
    return directory + EXECUTEABLENAME;
    
}

int main(int argc, char** argv) {

    vector<string> dirList;
    map<string, UnitTest> tests;
    bool isSuccess = true;
    string directory = argv[1];
    
    dirList = readDirectory(directory);
    
    for(unsigned int i = 0; i < dirList.size(); i++){
        
        testFile file = parseFile(dirList[i]);
        if(file.parsed){
            tests[file.number].addFile(file);
            tests[file.number].assertTest = directory + TESTOUTPUTFILENAME;
        }
    }
    
    string executeable = compile(directory);
    
    cout << endl << endl;
    cout << "Beginning the Testing!" << endl << endl;
    
    for(map<string, UnitTest>::iterator iterator = tests.begin(); iterator != tests.end(); iterator++) {
         isSuccess = iterator->second.assert(executeable) && isSuccess;
    }
    
    if(isSuccess){
        cout << "SUCCESS : All tests passed!";
    }
    
    return 0;
}

