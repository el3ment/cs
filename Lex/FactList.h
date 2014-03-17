/* 
 * File:   FactList.h
 * Author: robert
 *
 * Created on February 21, 2014, 8:35 AM
 */

#ifndef FACTLIST_H
#define	FACTLIST_H

#include "Fact.h"
#include "Domain.h"
#include <vector>

using namespace std;

class FactList {
public:
	
	vector<Fact*> list;
	
	FactList(){}
	FactList(Lex &lex, Domain &domain){
		parseFactList(lex, domain);
	};
	FactList(const FactList& orig){};
	virtual ~FactList(){
		for(int i = 0; i < list.size(); i++){
			//delete list[i];
		}
	};
	
	void parseFactList(Lex &lex, Domain &domain){
		if(lex.peek(ID)){
			list.push_back(new Fact(lex, domain));
			parseFactList(lex, domain);
			
			return;
		}else if(lex. peek(RULES)){
			return;
		}
		throw UNEXPECTED_TOKEN;
	}
	
	string toString() const{
		string output;
		for(int i = 0; i < list.size(); i++)
			output += list[i]->toString();
		return output;
	}
private:

};

#endif	/* FACTLIST_H */

