/* 
 * File:   PredicateList.h
 * Author: robert
 *
 * Created on February 21, 2014, 12:04 AM
 */

#ifndef PREDICATELIST_H
#define	PREDICATELIST_H

#include <vector>

#include "Predicate.h"

using namespace std;

class PredicateList {
public:
	
	vector<Predicate*> list;
	
	PredicateList(){}
	PredicateList(Lex &lex){
		parsePredicateList(lex);
	};
	PredicateList(const PredicateList& orig){};
	virtual ~PredicateList(){
		for(int i = 0; i < list.size(); i++){
			//delete list[i];
		}
	};
	
	void parsePredicateList(Lex &lex){
		if(lex.peek(COMMA)){
			lex.match(COMMA);
			list.push_back(new Predicate(lex));
			parsePredicateList(lex);
			return;
		}else if(lex.peek(PERIOD)){
			return;
		}

	}
	
	string toString() const{
		string output;
		for(int i = 0; i < list.size(); i++){
			output += ",";
			output += list[i]->toString();
		}
		return output;
	}
private:

};

#endif	/* PREDICATELIST_H */

