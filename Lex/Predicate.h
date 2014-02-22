/* 
 * File:   Predicate.h
 * Author: robert
 *
 * Created on February 20, 2014, 11:56 PM
 */

#ifndef PREDICATE_H
#define	PREDICATE_H

#include "Parameter.h"
#include "ParameterList.h"

class Predicate {
public:
	
	Token id;
	Parameter firstParameter;
	ParameterList parameterList;
	
	Predicate(){}
	Predicate(Lex &lex){
		id = lex.match(ID);
		lex.match(LEFT_PAREN);
		firstParameter = Parameter(lex);
		parameterList = ParameterList(lex);
		lex.match(RIGHT_PAREN);
	};
	Predicate(const Predicate& orig){}
	virtual ~Predicate(){};
	string toString() const{
		string output;
		output += id.getTokensValue();
		output += "(";
		output += firstParameter.toString();
		output += parameterList.toString();
		output += ")";
		return output;
	}
private:

};

#endif	/* PREDICATE_H */

