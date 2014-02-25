/* 
 * File:   Query.h
 * Author: robert
 *
 * Created on February 20, 2014, 9:23 PM
 */

#ifndef QUERY_H
#define	QUERY_H

#include "Errors.h"
#include "Lex.h"
#include "Predicate.h"

class Query {
public:
	
	Predicate predicate;
	
	Query(){}
	Query(Lex &lex){
		predicate = Predicate(lex);
		lex.match(Q_MARK);
	};
	Query(const Query& orig){};
	virtual ~Query(){};
	string toString() const{
		string output;
		output = "  ";
		output += predicate.toString();
		output += "?\n";
		return output;
	}
private:

};

#endif	/* QUERY_H */

