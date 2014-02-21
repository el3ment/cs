/* 
 * File:   Datalog.h
 * Author: robert
 *
 * Created on February 20, 2014, 7:55 PM
 */

#ifndef DATALOG_H
#define	DATALOG_H

#include <vector>
#include "Lists.h"

class Datalog {
public:
	Datalog();
	Datalog(const Datalog& orig);
	virtual ~Datalog();
	
	SchemeList schemeList;
	FactList factList;
	RuleList ruleList;
	QueryList queryList;
private:

};

#endif	/* DATALOG_H */

