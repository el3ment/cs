/* 
 * File:   Board.h
 * Author: robert
 *
 * Created on February 9, 2013, 10:05 PM
 */
#include <cstdlib>
#include <vector>
#include <set>
#include <string>
#include "Dictionary.h"
#include "Point.h"

#ifndef BOARD_H
#define	BOARD_H

using namespace std;

typedef set<Point> Points;
typedef set<string> wordList;

class Board {
public:
    Board();
    Board(const Board& orig);
    virtual ~Board();
    
    set<string> foundWords;
    vector< vector<string> > board;
    
    void loadFile(char* filename);
    wordList findAllInDictionary(Dictionary &dictionary);
    string printBoard();
    
    void find(unsigned int r, unsigned int c, Dictionary &dictionary, wordList &foundWords, Points &usedPoints, string word);

private:
    string _createPoint(int row, int column);
};

#endif	/* BOARD_H */

