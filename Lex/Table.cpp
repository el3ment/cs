/* 
 * File:   Table.cpp
 * Author: robert
 * 
 * Created on March 13, 2014, 8:04 PM
 */

#include "Table.h"
#include "Token.h"
#include <vector>
#include <iostream>
#include <sstream>
#include <tr1/unordered_set>

using namespace std;

Table::Table() {
}

Table::Table(Token id, Token first, vector<Token> list){
	_name = id.getTokensValue();
	_schema.push_back(first.getTokensValue());
	for(int i = 0; i < list.size(); i++){
		_schema.push_back(list.at(i).getTokensValue());
	}
}

Table::Table(string name, vector<string> schema){
	_schema = schema;
	name = name;
}


Table::Table(const Table* orig) {
	set<Tuple>::iterator tupleIterator;
	for(tupleIterator = orig->_rows.begin(); tupleIterator != orig->_rows.end(); tupleIterator++){
		add(*tupleIterator);
	}
	
	for(int i = 0; i < orig->_schema.size(); i++){
		_schema.push_back(orig->_schema.at(i));
	}
	
	this->_name = orig->_name;
}

Table::~Table() {
}

string Table::getHeaderFromIndex(int index) const{
	return this->_schema[index];
}

Table Table::project(vector<string> subset) const{
	
	// Remove the duplicates
	subset.erase(unique(subset.begin(), subset.end()), subset.end());
	
	// Project
	Table newTable = Table(_name, subset);
	set<Tuple>::iterator tupleIterator;
	for(tupleIterator = _rows.begin(); tupleIterator != _rows.end(); tupleIterator++){
		vector<Token> tupleList = vector<Token>();
		
		for(int i = 0; i < _schema.size(); i++){
			for(int j = 0; j < subset.size(); j++){
				if(_schema[i] == subset[j]){
					tupleList.push_back((*tupleIterator)._values[i]);
				}
			}
		}
		
		newTable.add(Tuple(tupleList));
	}

	return newTable;
}

Table Table::rename(int fromIndex, string toValue) const{
	Table newTable = Table(this);
	
	newTable._schema[fromIndex] = toValue;

	return newTable;
}

Table Table::select(int index, Token right){
	Table newTable = Table(_name, _schema);
	
	set<Tuple>::iterator tupleIterator;
	for (tupleIterator = _rows.begin(); tupleIterator != _rows.end(); tupleIterator++){
		Tuple tuple = *tupleIterator;
		
		// Test against another column
		if(right.getTokenType() == ID){
			string rightValueOnRow = tuple.get(indexOfTokenInSchema(right));
			string leftValueOnRow = tuple.get(index);
			
			if(rightValueOnRow == leftValueOnRow){
				newTable.add(tuple);
			}
			
		// Test against a string
		}else if(right.getTokenType() == STRING){
			string valueOnRow = tuple.get(index);
			if(valueOnRow == right.getTokensValue()){
				newTable.add(tuple);
			}
		}	
	}
	
	return newTable;
}

int Table::indexOfTokenInSchema(Token token){
	for(int i = 0; i < _schema.size(); i++){
		if(_schema[i] == token.getTokensValue()){
			return i;
		}
	}
}

string Table::toString() const{
	stringstream ss;
	
	if(_schema.size() > 0){
		set<Tuple>::iterator tupleIterator;
		for (tupleIterator = _rows.begin(); tupleIterator != _rows.end(); tupleIterator++){
			ss << "  ";
			for(int i = 0; i < _schema.size(); i++){
				ss << _schema[i] << "=" << (*tupleIterator)._values[i].getTokensValue();
				if(i < _schema.size() - 1)
					ss << ", ";
			}
			ss << endl;
		}
	}
	
	return ss.str();
}

void Table::add(Tuple tuple){
	_rows.insert(tuple);
}

int Table::count() const{
	return _rows.size();
}

bool Table::isInSchema(Token t){
	for(int i = 0; i < _schema.size(); i++){
		
		if(_schema[i] == t.getTokensValue())
			return true;
	}
	return false;
}