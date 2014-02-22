/* 
 * File:   HeadPredicate.h
 * Author: robert
 *
 * Created on February 21, 2014, 12:06 AM
 */

#ifndef HEADPREDICATE_H
#define	HEADPREDICATE_H

#include "Token.h"
#include "IdList.h"

class HeadPredicate {
public:
	
	Token id;
	IdList idList;
	
	HeadPredicate(){}
	HeadPredicate(Lex &lex){
		id = lex.match(ID);
		lex.match(LEFT_PAREN);

		idList = IdList(lex);

		lex.match(RIGHT_PAREN);
	};
	HeadPredicate(const HeadPredicate& orig){};
	virtual ~HeadPredicate(){};
	
	string toString() const{
		string output;
		output += id.getTokensValue();
		output += "(";
		output += idList.toString();
		output += ")";
		return output;
	}
private:

};

#endif	/* HEADPREDICATE_H */

