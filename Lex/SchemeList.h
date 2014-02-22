#pragma once
#include "Scheme.h"
#include "Utils.h"
#include <vector>
#include <iostream>

using namespace std;

class SchemeList {
public:
	vector<Scheme*> list;
	
	SchemeList(){};
	SchemeList(Lex &lex){
		parseSchemeList(lex);
	};
	SchemeList(const SchemeList& orig){};
	virtual ~SchemeList(){};
	
	void parseSchemeList(Lex &lex){
		if(lex.peek(ID)){
			list.push_back(new Scheme(lex));
			parseSchemeList(lex);
			return;

		}else if(lex.peek(FACTS)){
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