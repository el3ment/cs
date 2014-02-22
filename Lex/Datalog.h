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

class Datalog {
public:
	Scheme firstScheme;
	SchemeList schemeList;
	FactList factList;
	RuleList ruleList;
	Query firstQuery;
	QueryList queryList;
	
	Domain domain;
	
	Datalog(){}
	Datalog(Lex& lex){
		if(lex.peek(SCHEMES)){
			lex.match(SCHEMES);
			lex.match(COLON);
			firstScheme = Scheme(lex);
			
			schemeList = SchemeList(lex);
            
			lex.match(FACTS);
			lex.match(COLON);
			factList = FactList(lex, domain);
            
			lex.match(RULES);
			lex.match(COLON);
			ruleList = RuleList(lex);

			lex.match(QUERIES);
			lex.match(COLON);
			
			firstQuery = Query(lex);
			queryList = QueryList(lex);
		}else{
			throw UNEXPECTED_TOKEN;
		}
	}
	
	Datalog(const Datalog& orig){};
	
	virtual ~Datalog(){};
	
	string toString() const{
		string output;
		output += "Schemes(";
			output += schemeList.list.empty() ? "1" : itoa(1 + schemeList.list.size());
			output += "): \n";
			output += firstScheme.toString();
			output += schemeList.toString();
		output += "Facts(";
			output += itoa(factList.list.size());
			output += "): \n";
			output += factList.toString();
		output += "Rules(";
			output += itoa(ruleList.list.size());
			output += "): \n";
			output += ruleList.toString();
		output += "Queries(";
			output += queryList.list.empty() ? "1" : itoa(1 + queryList.list.size());
			output += "): \n";
			output += firstQuery.toString();
			output += queryList.toString();
		output += "Domain(";
			output += itoa(domain.list.size());
			output += "): \n";
			output += domain.toString();
		return output;
	};

private:

};

#endif	/* DATALOG_H */

