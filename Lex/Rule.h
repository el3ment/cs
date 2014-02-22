/* 
 * File:   Rule.h
 * Author: robert
 *
 * Created on February 20, 2014, 9:23 PM
 */

#ifndef RULE_H
#define	RULE_H

#include "Errors.h"
#include "IdList.h"
#include "HeadPredicate.h"
#include "PredicateList.h"
#include "Lex.h"

class Rule {
public:
	
	HeadPredicate headPredicate;
	Predicate firstPredicate;
	PredicateList predicateList;
	
	Rule(){}
	Rule(Lex &lex){
		headPredicate = HeadPredicate(lex);
		lex.match(COLON_DASH);
		firstPredicate = Predicate(lex);
		predicateList = PredicateList(lex);
		lex.match(PERIOD);
	};
	
	Rule(const Rule& orig){};
	virtual ~Rule(){};
	string toString() const{
		string output;
		output = "  ";
		output += headPredicate.toString();
		output += " :- ";
		output += firstPredicate.toString();
		output += predicateList.toString();
		output += ".\n";
		return output;
	}

private:

};

#endif	/* RULE_H */

