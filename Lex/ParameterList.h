/* 
 * File:   ParameterList.h
 * Author: robert
 *
 * Created on February 20, 2014, 11:58 PM
 */

#ifndef PARAMETERLIST_H
#define	PARAMETERLIST_H

#include <vector>
#include "Parameter.h"

using namespace std;

class ParameterList {
public:
	
	vector<Parameter*> list;
	
	ParameterList(){}
	ParameterList(Lex &lex){
		parseParameterList(lex);
	};
	ParameterList(const ParameterList& orig){};
	virtual ~ParameterList(){};
	
	void parseParameterList(Lex &lex){
		if(lex.peek(COMMA)){
			lex.match(COMMA);
			list.push_back(new Parameter(lex));
			parseParameterList(lex);
			return;
		}else if(lex.peek(RIGHT_PAREN)){
			return;
		}
		
		throw UNEXPECTED_TOKEN;
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

#endif	/* PARAMETERLIST_H */

