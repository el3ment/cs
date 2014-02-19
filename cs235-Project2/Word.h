/* 
 * File:   Word.h
 * Author: el3ment
 *
 * Created on January 29, 2013, 2:23 PM
 */
#include <cstdlib>
#include <string>
using namespace std;

#ifndef WORD_H
#define	WORD_H

class Word {
public:
    Word();
    Word(const Word& orig);
    Word(unsigned int lineNumber, string word);
    
    virtual ~Word();
    //string word();
    //unsigned int lineNumber();
    
    unsigned int lineNumber;
    string word;

private:
    void _initialize(unsigned int lineNumber, string word);
    
};

#endif	/* WORD_H */

