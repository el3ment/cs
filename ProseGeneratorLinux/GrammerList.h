/* 
 * File:   GrammerList.h
 * Author: robert
 *
 * Created on February 9, 2013, 6:53 PM
 */

#include <string>
#include <map>
#include <iostream>
#include <sstream>
#include "GrammerRule.h"

using namespace std;

#ifndef GRAMMERLIST_H
#define	GRAMMERLIST_H

class GrammerList {
public:
    GrammerList();
    GrammerList(const GrammerList& orig);
    virtual ~GrammerList();
    void loadFile(char* filename);
    string render();
    string printGrammer();
    void addWordToList(string word);
private:
    map< string, vector<GrammerRule> > _masterGrammerList;
    

};

#endif	/* GRAMMERLIST_H */

