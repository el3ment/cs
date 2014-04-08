/* 
 * File:   Table.h
 * Author: robert
 *
 * Created on March 13, 2014, 8:04 PM
 */

#ifndef TABLE_H
#define	TABLE_H

#include "Tuple.h"
#include <set>
#include <vector>
#include "Token.h"
#include <tr1/unordered_set>

using namespace std;

class Table {
public:
	Table();
	Table(Token name, Token first, vector<Token> list);
	Table(string name, vector<string> schema);
	Table(const Table* orig);
	virtual ~Table();
	
	void add(Tuple tuple);
	int count() const;
	string getHeaderFromIndex(int index) const;
	int indexOfTokenInSchema(Token token);
	bool isInSchema(Token token);
	
	Table select(string a, string b);
	Table select(int index, Token right);
	Table rename(int fromIndex, string newValue) const;
	Table project(vector<string> subset) const;
	Table join(Table a, Table b);
	
	string toString() const;
	
	set<Tuple> _rows;
	vector<string> _schema;
	string _name;
private:
	
	

};

#endif	/* TABLE_H */

