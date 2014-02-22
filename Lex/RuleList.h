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

class RuleList {
public:
	
	vector<Rule*> list;
	
	RuleList(){}
	RuleList(Lex &lex){
		parseRuleList(lex);
	};
	
	RuleList(const RuleList& orig){};
	virtual ~RuleList(){};
	
	void parseRuleList(Lex &lex){ 
		if(lex.peek(ID)){
			list.push_back(new Rule(lex));
			parseRuleList(lex);
			return;
		}else if(lex.peek(QUERIES)){
			return;
		}

		throw UNEXPECTED_TOKEN;
	
	};
	string toString() const{
		string output;
		for(int i = 0; i < list.size(); i++)
			output += list[i]->toString();
		return output;
	}
private:

};

#endif	/* RULELIST_H */

