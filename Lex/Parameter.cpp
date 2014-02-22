
#include "Parameter.h"

using namespace std;

Parameter::Parameter(){}
Parameter::Parameter(Lex &lex){
	if(lex.peek(STRING)){
		isToken = true;
		token = lex.match(STRING);
		return;
	}else if(lex.peek(ID)){
		isToken = true;
		token = lex.match(ID);
		return;
	}else if(lex.peek(LEFT_PAREN)){
		isToken = false;
		expression = Expression(lex);
		return;
	}

	throw UNEXPECTED_TOKEN;
}

string Parameter::toString() const{
	return (isToken ? token.getTokensValue() : expression.toString());
}