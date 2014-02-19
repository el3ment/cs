// http://www.dave-reed.com/Nifty/randSeq.html

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <algorithm>
#include "Board.h"
#include "Dictionary.h"
#include "Point.h"
using namespace std;

typedef set<string> wordList;

int main(int argc, char** argv) {
    
    ofstream outputFile(argv[3]);
    
    Dictionary dictionary;
    dictionary.loadFile(argv[1]);

    Board board;
    board.loadFile(argv[2]);
    outputFile << board.printBoard() << endl;
    
    wordList foundWords = board.findAllInDictionary(dictionary);
    
    //sort(foundWords.begin(), foundWords.end());
    //string lastWord;
    //for(unsigned int i = 0; i < foundWords.size(); i++){
    //    if(foundWords[i] != lastWord){
    //       outputFile << foundWords[i] << endl;
    //   }
    //    lastWord = foundWords[i];
    //}
    for(set<string>::iterator i = foundWords.begin(); i != foundWords.end(); i++){
        outputFile << *i << endl;
    }

        
    ifstream print(argv[3]);
    string line;
    while(getline(print, line)){
        cout << line << endl;
    }
    print.close();
    
    return 0;
}

