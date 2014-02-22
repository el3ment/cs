/* 
 * File:   Scheme.h
 * Author: robert
 *
 * Created on February 20, 2014, 7:55 PM
 */

#ifndef SCHEME_H
#define	SCHEME_H

#include "Lex.h"
#include "Errors.h"
#include "IdList.h"
#include <vector>
#include <iostream>

class Scheme {
public:
	
	Token id;
	IdList idList;
	
	Scheme(){}
	Scheme(Lex &lex){
		id = lex.match(ID);
		lex.match(LEFT_PAREN);

		idList = IdList(lex);

		lex.match(RIGHT_PAREN);
	};
	Scheme(const Scheme& orig){};
	virtual ~Scheme(){};
	
	string toString() const{
		string output;
		output = "  ";
		output += id.getTokensValue();
		output += "(";
		output += idList.toString();
		output += ")\n";
		return output;
	}
private:

};

#endif	/* SCHEME_H */

