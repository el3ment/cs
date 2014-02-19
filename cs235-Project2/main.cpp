#include <cstdlib>
#include <set>
#include <map>
#include <vector>
#include <iterator>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cctype>
#include "Word.h"

using namespace std;

typedef set<string> Dictionary;
typedef vector<int> lineNumber;
typedef map<string,lineNumber> Errors;
typedef vector<Word> Document;
typedef vector<string> File;

bool isNonAlpha(char c){
    return !isalpha(c);
}

File loadFile(string filename){
    ifstream file;
    string line;
    File output;
    file.open(filename.c_str());
    while(getline(file, line)){
        output.push_back(line);
    }
    
    return output;
}

Dictionary loadDictionary(string filename){
    File file = loadFile(filename);
    Dictionary output;
    
    for(unsigned int i = 0; i < file.size(); i++){
        transform(file[i].begin(), file[i].end(), file[i].begin(), ::tolower);
        if(file[i].size() > 0){
             output.insert(file[i]);
        }
    }
    
    return output;
}

Document loadDocument(string filename){
    
    File file = loadFile(filename);
    vector<Word> output;
    
    for(unsigned int i = 0; i < file.size(); i++){
        
        // Transform to lower case
        transform(file[i].begin(), file[i].end(), file[i].begin(), ::tolower);
        
        // Remove all non-alpha chars
        replace_if(file[i].begin(), file[i].end(), isNonAlpha, ' ');
        
        // Split into words
        istringstream wordStream(file[i]);
        vector<string> wordsForLine;
        
        copy(istream_iterator<string>(wordStream),
             istream_iterator<string>(),
             back_inserter< vector<string> >(wordsForLine));
        
        for(unsigned int j = 0; j < wordsForLine.size(); j++){
            // Add each word to the list
            Word newWord(i+1, wordsForLine[j]); // i is indexed from 0, so we add one
            output.push_back(newWord);
        }
    }
    
    return output;
}

int main(int argc, char** argv) {

    Dictionary dictionary = loadDictionary(argv[1]);
    Document document = loadDocument(argv[2]);
    Errors errors;
    
    ofstream outputFile;
    outputFile.open(argv[3]);
    
    // For each word in the document
    for(unsigned int i = 0; i < document.size(); i++){
        // Is the word in the dictionary?
        if(!dictionary.count(document[i].word)){
            // Add it to the errors map
            if(document[i].word.size() > 0){
                errors[document[i].word].push_back(document[i].lineNumber);
            }
        }
    }
    
    // Loop through the errors, and save them to a file
    for(map< string, vector<int> >::iterator it = errors.begin(); it != errors.end(); it++){
        if(it->first.size() > 0){
            cout << it->first << ":";
            outputFile << it->first << ":";
            for(unsigned int e = 0; e < it->second.size(); e++){
                cout << " " << it->second[e];
                outputFile << " " << it->second[e];
            }
            cout << endl;
            outputFile << endl;
        }
    }
              
    
    return 0;
}

