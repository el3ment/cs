/* 
 * File:   Parse.h
 * Author: el3ment
 *
 * Created on February 19, 2014, 3:50 PM
 */

#ifndef PARSE_H
#define	PARSE_H

#include "Lex.h"
#include "TokenType.h"
#include "Datalog.h";
#include <string>

using namespace std;

class Parse {
public:
    Parse();
    Parse(const Parse& orig);
    Parse(const char* fileName);
    virtual ~Parse();
    string toString() const;
	Token* getCurrentToken();
	string parse();
    Datalog* structure;
private:
    Lex _lexicalStructure;
	

};

#endif	/* PARSE_H */

