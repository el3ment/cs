
#include "Parameter.h"
#include "EvaluateableInterface.h"
#include "Table.h"
#include <iostream>
#include "Utils.h"

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
Table Parameter::eval(Table table, int index) const{
	if(token.getTokenType() == STRING){
		table = table.select(index, token);
	}else if(token.getTokenType() == ID){
			
			
		if(table.isInSchema(token)){
			table = table.select(index, token);
			table = table.rename(index, token.getTokensValue() + itoa(index));
		}else{
			table = table.rename(index, token.getTokensValue());
		}
		
	}else{
		// unimplemented
	}
	
	return table;
}

string Parameter::toString() const{
	return (isToken ? token.getTokensValue() : expression.toString());
}