/* 
 * File:   EvaluateableInterface.h
 * Author: robert
 *
 * Created on March 13, 2014, 8:08 PM
 */

#ifndef EVALUATEABLEINTERFACE_H
#define	EVALUATEABLEINTERFACE_H

#include "Table.h"

class EvaluateableInterface{
	
	public:
        virtual ~EvaluateableInterface() {}
        virtual Table eval(Table table, int index) const = 0;
};

#endif	/* EVALUATEABLEINTERFACE_H */

