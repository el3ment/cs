/* 
 * File:   QueryList.h
 * Author: robert
 *
 * Created on February 20, 2014, 11:51 PM
 */

#ifndef QUERYLIST_H
#define	QUERYLIST_H

#include <vector>

using namespace std;

class QueryList {
public:
	vector<Query*> list;
	
	QueryList(){}
	QueryList(Lex &lex){
		parseQueryList(lex);
	}
	QueryList(const QueryList& orig){};
	virtual ~QueryList(){};
	
	void parseQueryList(Lex &lex){
		if(lex.peek(ID)){
			list.push_back(new Query(lex));
                        parseQueryList(lex);
			return;
		}else if(lex.peek(ENDOFFILE)){
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

#endif	/* QUERYLIST_H */

