/* 
 * File:   RuleList.h
 * Author: robert
 *
 * Created on February 21, 2014, 8:38 AM
 */

#ifndef RULELIST_H
#define	RULELIST_H

#include "Rule.h"
#include <vector>

using namespace std;

class Datalog;

class RuleList {
public:
	
	vector<Rule*> list;
	
	RuleList(){}
	RuleList(Lex &lex);
	
	RuleList(const RuleList& orig);
	virtual ~RuleList(){};
	
	void parseRuleList(Lex &lex);
	string toString() const;
	
	void eval(Datalog* db);
private:

};

#endif	/* RULELIST_H */

