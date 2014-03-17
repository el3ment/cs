/* 
 * File:   Datalog.h
 * Author: robert
 *
 * Created on February 20, 2014, 7:55 PM
 */

#ifndef DATALOG_H
#define	DATALOG_H

#include <vector>
#include "Lex.h"
#include "Query.h"
#include "Scheme.h"
#include "SchemeList.h"
#include "RuleList.h"
#include "QueryList.h"
#include "FactList.h"
#include "Errors.h"
#include "Domain.h"
#include <iostream>
#include "Utils.h"
#include <map>

using namespace std;

class Datalog {
public:
	Scheme firstScheme;
	SchemeList schemeList;
	FactList factList;
	RuleList ruleList;
	Query firstQuery;
	QueryList queryList;
	vector<Table*> database;
	
	Domain domain;
	
	Datalog(){}
	Datalog(Lex& lex);
	
	Datalog(const Datalog& orig){};
	
	virtual ~Datalog(){};
	
	void parseSchemes();
	
	void parseFacts();
	Table* getTable(Token id);
	
	vector<Query*> getQueries();
	
	string toString() const;

private:

};

#endif	/* DATALOG_H */

