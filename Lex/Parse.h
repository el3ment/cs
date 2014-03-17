#ifndef PARSE_H
#define	PARSE_H

#include <string>
#include "Lex.h"
#include "TokenType.h"
#include "Datalog.h";

using namespace std;

class Parse {
public:
	
	Lex* lexicalStructure;
	Datalog* data;
	
    Parse();
    Parse(const Parse& orig);
	Parse(const char* fileName);
    virtual ~Parse();
    string toString() const;
	Token* getCurrentToken();
	Datalog* parse();
	
private:
	
	
};

#endif	/* PARSE_H */

