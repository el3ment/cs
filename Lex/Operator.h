/* 
 * File:   Operator.h
 * Author: robert
 *
 * Created on February 21, 2014, 12:01 AM
 */

#ifndef OPERATOR_H
#define	OPERATOR_H

#include "Lex.h"
#include "Token.h"
#include "Errors.h"

class Operator {
public:
	Token token;
	
	Operator(){}
	Operator(Lex &lex){
		if(lex.peek(ADD)){
			token = lex.match(ADD);
			return;
		}else if(lex.peek(MULTIPLY)){
			token = lex.match(MULTIPLY);
			return;
		}

		throw UNEXPECTED_TOKEN;
	};
	Operator(const Operator& orig){};
	virtual ~Operator(){};
	
	string toString() const{
		return token.getTokensValue();
	}
private:

};

#endif	/* OPERATOR_H */

