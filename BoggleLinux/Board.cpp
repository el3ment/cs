/* 
 * File:   Board.cpp
 * Author: robert
 * 
 * Created on February 9, 2013, 10:05 PM
 */

#include <vector>
#include <set>
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <algorithm>
#include "Board.h"
#include "Dictionary.h"
#include "Point.h"
#include "math.h"

using namespace std;

typedef set<string> wordList;

Board::Board() {
}

Board::Board(const Board& orig) {
}

Board::~Board() {
}

wordList Board::findAllInDictionary(Dictionary &dictionary){
    wordList foundWords;
    Points usedPoints;
    
    //this->find(Point(0, 0), dictionary, foundWords, usedPoints, "");
    
    for(unsigned int i = 0; i < this->board.size(); i++){
        for(unsigned int j = 0; j < this->board[0].size(); j++){
            string word = "";
            this->find(i, j, dictionary, foundWords, usedPoints, word);
        }
    }
    
    return foundWords;
    
}
void Board::loadFile(char* filename){
    ifstream file(filename);
    vector<string> boardList;
    string letter;
    
    while(file >> letter){
        transform(letter.begin(), letter.end(), letter.begin(), ::tolower);
        boardList.push_back(letter);
    }
    
    unsigned int size = sqrt(boardList.size());
    unsigned int boardListIndex = 0;
    for(unsigned int i = 0; i < size; i++){
        vector<string> row;
        for(unsigned int j = 0; j < size; j++){
            row.push_back(boardList[boardListIndex]);
            boardListIndex++;
        }
        this->board.push_back(row);
    }
    
}

string Board::printBoard(){
    stringstream output;
    for(unsigned int i = 0; i < this->board.size(); i++){
        for(unsigned int j = 0; j < this->board.size(); j++){
            output << this->board[i][j] << " ";
        }
        output << endl;
    }
    return output.str();
}
void Board::find(unsigned int r, unsigned int c, Dictionary &dictionary, wordList &foundWords, Points &usedPoints, string word){
    
    Point point(r, c);
    
    // Base Cases
    if(point.row > this->board.size()-1 || // Out of bounds
       point.column > this->board[0].size()-1 || // Out of bounds
       point.row < 0 || point.column < 0 || // Out of Bounds
       usedPoints.count(point) == 1){ // Already used
        return;
    }
    
    word += board[point.row][point.column]; // Add point to word
    
    if(dictionary.findPartial(word)){
        if(word.size() > 3 && dictionary.findComplete(word)){
            foundWords.insert(word);
            //foundWords.push_back(word);
        }
        
        // Add point to usedPoints
        usedPoints.insert(point);

        // Move to the other points
        find(point.row - 1, point.column - 1, dictionary, foundWords, usedPoints, word);
        find(point.row - 1, point.column, dictionary, foundWords, usedPoints, word);
        find(point.row - 1, point.column + 1, dictionary, foundWords, usedPoints, word);

        find(point.row, point.column - 1, dictionary, foundWords, usedPoints, word);
        find(point.row, point.column + 1, dictionary, foundWords, usedPoints, word);

        find(point.row + 1, point.column - 1, dictionary, foundWords, usedPoints, word);
        find(point.row + 1, point.column, dictionary, foundWords, usedPoints, word);
        find(point.row + 1, point.column + 1, dictionary, foundWords, usedPoints, word);
    }
    
    usedPoints.erase(point);
    
}