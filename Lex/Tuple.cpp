/* 
 * File:   Tuple.cpp
 * Author: robert
 * 
 * Created on March 13, 2014, 8:04 PM
 */

#include "Tuple.h"
#include <iostream>
#include <sstream>

using namespace std;

Tuple::Tuple() {
}

Tuple::Tuple(const Tuple& orig){
	for(int i = 0; i < orig._values.size(); i++){
		_values.push_back(orig._values[i]);
	}
}

Tuple::~Tuple() {
}

Tuple::Tuple(vector<Token> argumentList){
	this->_values = vector<Token>(argumentList);
}

void Tuple::addAll(Tuple tuple){
	for(int i = 0; i < tuple._values.size(); i++){
		_values.push_back(tuple._values[i]);
	}
}

void Tuple::remove(int index){
	//cout << "tuple size before " << _values.size() << endl;
	//_values[index] = Token();
	_values.erase(_values.begin() + index);
	//cout << "tuple size after " << _values.size() << endl;
}

string Tuple::get(int id){
	return _values.at(id).getTokensValue();
}

string Tuple::toString() const{
	stringstream ss;
	
	ss << "(";
	for(int i = 0; i < _values.size(); i++){
		ss << _values[i].getTokensValue() << ", ";
	}
	ss << ")";
	
	return ss.str();
}

bool Tuple::operator <(const Tuple& tuple) const{
	for(int i = 0; i < _values.size(); i++){
		if(tuple._values[i].getTokensValue().compare(_values[i].getTokensValue()))
			return tuple._values[i].getTokensValue() > _values[i].getTokensValue();
	}
	return false;
}

bool Tuple::operator >(const Tuple& tuple) const{
	for(int i = 0; i < _values.size(); i++){
		if(tuple._values[i].getTokensValue().compare(_values[i].getTokensValue()))
			return tuple._values[i].getTokensValue() < _values[i].getTokensValue();
	}
	return false;
}