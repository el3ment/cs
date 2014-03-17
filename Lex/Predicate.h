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
	Parameter* firstParameter;
	ParameterList parameterList;
	
	Predicate(){}
	Predicate(Lex &lex){
		id = lex.match(ID);
		lex.match(LEFT_PAREN);
		firstParameter = new Parameter(lex);
		parameterList = ParameterList(lex);
		lex.match(RIGHT_PAREN);
	};
	Predicate(const Predicate& orig){}
	virtual ~Predicate(){};
	
	Parameter* at(int index){
		if(index == 0){
			return firstParameter;
		}else{
			return parameterList.list.at(index - 1);
		}
	}
	
	int size(){
		return (parameterList.list.size() > 0 ? 1 + parameterList.list.size() : 1);
	}
	
	string toString() const{
		string output;
		output += id.getTokensValue();
		output += "(";
		output += firstParameter->toString();
		output += parameterList.toString();
		output += ")";
		return output;
	}
private:

};

#endif	/* PREDICATE_H */

