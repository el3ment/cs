/* 
 * File:   Parameter.h
 * Author: robert
 *
 * Created on February 20, 2014, 11:58 PM
 */

#ifndef PARAMETER_H
#define	PARAMETER_H

#include "Token.h"
#include "Expression.h"

class Parameter {
public:
	
	Token token;
	bool isToken;
	Expression expression;
	
	Parameter();
	Parameter(Lex &lex);
	Parameter(const Parameter& orig){};
	virtual ~Parameter(){};
	string toString() const;
private:

};



#endif	/* PARAMETER_H */

