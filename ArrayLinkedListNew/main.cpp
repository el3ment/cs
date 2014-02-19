/* 
 * File:   main.cpp
 * Author: robert
 *
 * Created on March 18, 2013, 9:00 PM
 */

#include <cstdlib>
#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#include <sstream>
#include "ArrayLinkedList.h"

using namespace std;

struct Command{
    string method;
    vector<string> arguments;
};

typedef vector< Command > commands;

commands parseInput(char * filename){
    commands cmds;
    ifstream file(filename);
    string line;
    string command;
    while(getline(file, line)){
        stringstream stream(line);
        Command cmd;
        stream >> command;
        cmd.method = command;
        while(stream >> command){
            cmd.arguments.push_back(command);
        }
        cmds.push_back(cmd);
    }
            
    return cmds;
}

int toint(const string& input){
    return atoi(input.c_str());
}

string execute(commands cmds){
    
    stringstream output;
    LinkedArrayList<string>* master = new LinkedArrayList<string>(2);

    for(unsigned int i = 0; i < cmds.size(); i++){
        
        // List
        if(cmds[i].method == "list"){
            int size = toint(cmds[i].arguments[0]);
	    if(size >= 2){
                delete master;
		master = new LinkedArrayList<string>(size);
	    }
            output << "list " << size << endl;
        
            
            
        // Insert
        }else if(cmds[i].method == "insert"){
            int index = toint(cmds[i].arguments[0]);
            string item = cmds[i].arguments[1];
            master->insert(index, item);
            output << "insert " << index << " " << item << endl;
        
            
            
        // Remove
        }else if(cmds[i].method == "remove"){
            int index = toint(cmds[i].arguments[0]);
            string item = master->remove(index);
            output << "remove " << index << " " << item << endl;
            
            
        // Find
        }else if(cmds[i].method == "find"){
            string item = cmds[i].arguments[0];
            int foundIndex = master->find(item);
            output << "find " << item << " " << foundIndex << endl;
        
            
            
        // Print
        }else if(cmds[i].method == "print"){
            output << "print" << endl << master->print();
            
            
        }else{
            //cout << "Unknown Command : " << cmds[i].method << endl;
        }
    }
    
    delete master;
    
    return output.str();
}

int main(int argc, char** argv) {
    
    ofstream outputFile(argv[2]);
    
    commands cmds = parseInput(argv[1]);
    string output = execute(cmds);
    
    outputFile  << output;
    cout << output;
    
    return 0;
}

