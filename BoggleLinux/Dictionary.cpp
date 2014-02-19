/* 
 * File:   Dictionary.cpp
 * Author: robert
 * 
 * Created on February 9, 2013, 10:24 PM
 */
#include <fstream>
#include <string>
#include <iostream>
#include <algorithm>
#include "Dictionary.h"

Dictionary::Dictionary() {
}

Dictionary::Dictionary(const Dictionary& orig) {
}

Dictionary::~Dictionary() {
}
void Dictionary::loadFile(char* filename){
    
    ifstream file(filename);
    string line;
    
    while(getline(file, line)){
        transform(line.begin(), line.end(), line.begin(), ::tolower);
        
        this->list.insert(line);
    }
    
    file.close();
    
}
bool Dictionary::findComplete(string &word){
    if(this->list.count(word) == 1){
        return true;
    }
    
    return false;
}

bool Dictionary::findPartial(string &word){
    if(this->list.lower_bound(word) != this->list.end()){
        string entry = *this->list.lower_bound(word);
        return entry.substr(0, word.size()).compare(word) == 0;
    }
    
    return false;
}