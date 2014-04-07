/* 
 * File:   Tuple.h
 * Author: robert
 *
 * Created on March 13, 2014, 8:04 PM
 */

#ifndef TUPLE_H
#define	TUPLE_H

#include <vector>
#include "Token.h"

using namespace std;

class Tuple {
public:
	Tuple();
	Tuple(vector<Token> argumentList);
	Tuple(const Tuple& orig);
	virtual ~Tuple();
	
	void add(Token token);
	void addAll(Tuple tuple);
	string get(int id);
	string toString() const;
	void remove(int index);
	
	bool operator==(const Tuple& tuple) const;
	bool operator<(const Tuple& tuple) const;
	bool operator>(const Tuple& tuple) const;
	
	vector<Token> _values;
	
private:
	
};

#endif	/* TUPLE_H */

