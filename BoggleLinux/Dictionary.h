/* 
 * File:   Dictionary.h
 * Author: robert
 *
 * Created on February 9, 2013, 10:24 PM
 */

#include <string>
#include <set>

#ifndef DICTIONARY_H
#define	DICTIONARY_H

using namespace std;

class Dictionary {
public:
    Dictionary();
    Dictionary(const Dictionary& orig);
    virtual ~Dictionary();
    bool findPartial(string &word);
    bool findComplete(string &word);
    void loadFile(char* filename);
    set<string> list;
private:

};

#endif	/* DICTIONARY_H */

