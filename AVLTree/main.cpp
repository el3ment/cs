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
#include "AVLTree.h"

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
    AVLTreeSet<string> master = AVLTreeSet<string>();

    for(unsigned int i = 0; i < cmds.size(); i++){
        
        // List
        if(cmds[i].method == "clear"){
            master.removeAll(master.root);
            output << "clear" << endl;
        
            
            
        // Insert
        }else if(cmds[i].method == "add"){
			string item = cmds[i].arguments[0];
            master.add(item);
            output << "add " << item << endl;
        
            
            
        // Remove
        }else if(cmds[i].method == "remove"){
			string item = cmds[i].arguments[0];
			master.remove(item);
            output << "remove " << item << endl;
            
            
        // Find
        }else if(cmds[i].method == "find"){
            string item = cmds[i].arguments[0];
            bool foundIndex = master.find(item);
			if(foundIndex)
				output << "find " << item << " true" << endl;
			else
				output << "find " << item << " false" << endl;
        
        // Print
        }else if(cmds[i].method == "print"){
            output << "print" << master.print();
            
            
        }else{
            cout << "Unknown Command : " << cmds[i].method << endl;
        }
    }
    return output.str();
}

int main(int argc, char** argv) {
    
    ofstream outputFile(argv[2]);
    
    commands cmds = parseInput(argv[1]);
    string output = execute(cmds);
    
    outputFile  << output;
    //cout << output;
	
    return 0;
}

