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
    
    bool peek(TokenType test);
    bool match(TokenType consume);
    bool parseDatalog();
    bool parseScheme();
	bool parseIdList();
    bool parseSchemeList();
    bool parseFactList();
	bool parseFact();
    bool parseRuleList();
    bool parseQuery();
    bool parseQueryList();
	bool parseStringList();
	
	bool parseRule();
	bool parseHeadPredicate();
	bool parsePredicate();
	bool parsePredicateList();
	
	bool parseParameter();
	bool parseParameterList();
	
	bool parseExpression();
	bool parseOperator();
private:
    Lex _lexicalStructure;

};

#endif	/* PARSE_H */

