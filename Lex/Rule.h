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
#include <vector>

class Datalog;

class Rule {
public:
	
	HeadPredicate headPredicate;
	Predicate firstPredicate;
	PredicateList predicateList;
	
	Rule();
	Rule(Lex &lex);
	
	Table eval(Datalog* datalog);
	Table eval(Table left, std::vector<Table> list);
	
	Rule(const Rule& orig);
	virtual ~Rule(){};
	string toString() const;

private:

};

#endif	/* RULE_H */

