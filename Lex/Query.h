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
#include "Table.h"
#include "Datalog.h"

class Datalog;

class Query {
public:
	
	Predicate predicate;
	
	Query(){}
	Query(Lex &lex);
	Query(const Query& orig){};
	virtual ~Query(){};
	string toString() const;
	
	Table evaluate(Datalog* data);
	
private:

};

#endif	/* QUERY_H */

