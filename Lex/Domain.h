/* 
 * File:   Domain.h
 * Author: robert
 *
 * Created on February 21, 2014, 1:56 PM
 */

#ifndef DOMAIN_H
#define	DOMAIN_H

#include "Token.h"
#include <set>

using namespace std;

class Domain {
public:
	set<string> list;
	Domain(){
		list = set<string>();
	};
	Domain(const Domain& orig){};
	virtual ~Domain(){};
	
	void add(Token token){
		list.insert(token.getTokensValue());
	}
	string toString() const{
		string output;
		
		for (set<string>::iterator it = list.begin(); it != list.end(); ++it){
			output += "  ";
			output += *it;
			output += "\n";
		}
	
		return output;
	}
private:

};

#endif	/* DOMAIN_H */

