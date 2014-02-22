/* 
 * File:   Fact.h
 * Author: robert
 *
 * Created on February 20, 2014, 9:24 PM
 */

#ifndef FACT_H
#define	FACT_H

#include "Token.h"
#include "Domain.h"

class Fact {
public:
	
	Token id;
	vector<Token> argumentList;
	
	Fact(){}
	Fact(Lex &lex, Domain &domain){
		id = lex.match(ID);
		lex.match(LEFT_PAREN);
		
		Token param = lex.match(STRING);
		argumentList.push_back(param);
		domain.add(param);
		
		parseStringList(lex, domain);

		lex.match(RIGHT_PAREN);
		lex.match(PERIOD);
	};
	Fact(const Fact& orig){};
	virtual ~Fact(){};
	

	void parseStringList(Lex &lex, Domain &domain){
		if(lex.peek(COMMA)){
			lex.match(COMMA);
			Token param = lex.match(STRING);
			argumentList.push_back(param);
			domain.add(param);
			parseStringList(lex, domain);
			return;
		}else if(lex.peek(RIGHT_PAREN)){
			return;
		}

		throw UNEXPECTED_TOKEN;
	}
	
	string toString() const{
		string output;
		output = "  ";
		output += id.getTokensValue();
		output += "(";
		output += argumentList[0].getTokensValue();
		for(int i = 1; i < argumentList.size(); i++){
			output += ",";
			output += argumentList[i].getTokensValue();
		}
		output += ").\n";
		return output;
	}
private:

};

#endif	/* FACT_H */

