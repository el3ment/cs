/* 
 * File:   GrammerList.cpp
 * Author: robert
 * 
 * Created on February 9, 2013, 6:53 PM
 */
#include <fstream>
#include <iostream>
#include <sstream>
#include "GrammerList.h"
#include <stdlib.h>
#include <time.h>

GrammerList::GrammerList() {
}

GrammerList::GrammerList(const GrammerList& orig) {
}

GrammerList::~GrammerList() {
}

void GrammerList::loadFile(char* filename){
    ifstream file(filename);
    string word;
    bool active = false;
    bool hasName = false;
    
    string grammerType;
    string rule;
    unsigned int ruleIndex = 0;
    
    while(file >> word){
        
        if(word.compare("{") == 0){
            hasName = false;
            active = true;
        }else if(active){
            if(word.compare(";") == 0){
                ruleIndex++;
                this->_masterGrammerList[grammerType].push_back(GrammerRule(rule));
                rule = "";
            }else if(word.compare("}") == 0){
                active = false;
                hasName = false;
                ruleIndex = 0;
                grammerType = "";
            }else if(!hasName && word.substr(0, 1).compare("<") == 0){
                hasName = true;
                grammerType = word;
            }else{
                rule += word + " ";
            }
        }
    }
    
    file.close();
}
void GrammerList::addWordToList(string word){
    

    
    
}
string GrammerList::render(){
    
    stringstream output("");
    
    if(this->_masterGrammerList["<start>"].size() > 0){
        unsigned int random = (rand() % (this->_masterGrammerList["<start>"].size()));
        output << this->_masterGrammerList["<start>"][random].render(this->_masterGrammerList) << endl;
    }
    
    return output.str();
}

string GrammerList::printGrammer(){
    stringstream output;
    
    for(map< string, vector<GrammerRule> >::iterator iterator = this->_masterGrammerList.begin(); iterator != this->_masterGrammerList.end(); iterator++){
        output << "{" << endl;
        output << iterator->first << endl;
        for(unsigned int i = 0; i < iterator->second.size(); i++){
            output << iterator->second[i].rule << ";" << endl;
        }
        output << "}" << endl;
    }
    
    return output.str();
}