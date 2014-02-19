/* 
 * File:   Word.cpp
 * Author: el3ment
 * 
 * Created on January 29, 2013, 2:23 PM
 */
#include <cstdlib>
#include <iostream>
#include <string>
#include "Word.h"

using namespace std;

Word::Word() {
}

Word::Word(const Word& orig){
    this->_initialize(orig.lineNumber, orig.word);
}

Word::~Word() {
}

Word::Word(unsigned int lineNumber, string word) {
    this->_initialize(lineNumber, word);
}

void Word::_initialize(unsigned int lineNumber, string word){
    this->lineNumber = lineNumber;
    this->word = word;
}