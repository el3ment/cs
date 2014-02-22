/* 
 * File:   IdList.h
 * Author: robert
 *
 * Created on February 20, 2014, 11:14 PM
 */

#ifndef IDLIST_H
#define	IDLIST_H

#include <vector>

#include "Token.h"

using namespace std;

class IdList {
public:
	
	Token firstId;
	vector<Token> list;
	
	IdList(){}
	IdList(Lex &lex){
		if(lex.peek(ID)){
			firstId = lex.match(ID);
			parseTail(lex);
			
			return;
		}

		throw UNEXPECTED_TOKEN;
	};
	IdList(const IdList& orig){};
	virtual ~IdList(){};
	
	void parseTail(Lex &lex){
		if(lex.peek(COMMA)){
			lex.match(COMMA);
			list.push_back(lex.match(ID));
			parseTail(lex);
			return;
		}else if(lex.peek(RIGHT_PAREN)){
			return;
		}
		throw UNEXPECTED_TOKEN;
	}
	
	string toString() const{
		string output;
		output += firstId.getTokensValue();
		for(int i = 0; i < list.size(); i++){
			output += ",";
			output += list[i].getTokensValue();
		}
		return output;
	}
private:

};

#endif	/* IDLIST_H */

