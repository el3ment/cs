#include "Parameter.h"
#include "ParameterList.h"
#include "Datalog.h"
#include "Predicate.h"

Predicate::Predicate(){}
Predicate::Predicate(Lex &lex){
	id = lex.match(ID);
	lex.match(LEFT_PAREN);
	firstParameter = new Parameter(lex);
	parameterList = ParameterList(lex);
	lex.match(RIGHT_PAREN);
};

Predicate::Predicate(const Predicate& orig){}

Parameter* Predicate::at(int index){
	if(index == 0){
		return firstParameter;
	}else{
		return parameterList.list.at(index - 1);
	}
}

int Predicate::size(){
	return (parameterList.list.size() > 0 ? 1 + parameterList.list.size() : 1);
}

Table Predicate::eval(Datalog* db){
	Table output = Table(db->getTable(id));

	vector<string> projection = vector<string>();
	
	for(int i = 0; i < size(); i++){
		if(at(i)->token.getTokenType() == ID){
			projection.push_back(at(i)->token.getTokensValue());
		}
		output = at(i)->eval(output, i);
	}

	return output;
}

string Predicate::toString() const{
	string output;
	output += id.getTokensValue();
	output += "(";
	output += firstParameter->toString();
	output += parameterList.toString();
	output += ")";
	return output;
}