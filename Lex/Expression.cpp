#include "Parameter.h"
#include "Expression.h"

Expression::Expression(){}
Expression::Expression(Lex &lex){
		
	if(lex.peek(LEFT_PAREN)){
		lex.match(LEFT_PAREN);
		left = new Parameter(lex);
		op = Operator(lex);
		right = new Parameter(lex);
		lex.match(RIGHT_PAREN);
		return;
	}

	throw UNEXPECTED_TOKEN;
}

string Expression::toString() const{
	string output;
	output += "(";
	output += left->toString();
	output += op.toString();
	output += right->toString();
	output += ")";
	return output;
}
