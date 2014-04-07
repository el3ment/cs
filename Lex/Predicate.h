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

class Datalog;

class Predicate {
public:
	
	Token id;
	Parameter* firstParameter;
	ParameterList parameterList;
	
	Predicate();
	Predicate(Lex &lex);
	Predicate(const Predicate& orig);
	virtual ~Predicate(){};
	
	Parameter* at(int index);
	
	int size();
	
	Table eval(Datalog* db);
	
	string toString() const;
private:

};

#endif	/* PREDICATE_H */

