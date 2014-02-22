#ifndef EXPRESSION_H
#define	EXPRESSION_H

#include "Operator.h"
#include "Errors.h"
#include "Parameter.h"

class Parameter;

class Expression {
public:
	Parameter* left;
	Operator op;
	Parameter* right;

	Expression();
	Expression(Lex &lex);
	Expression(const Expression& orig){};
	virtual ~Expression(){};
	string toString() const;
private:

};

#endif	/* EXPRESSION_H */

