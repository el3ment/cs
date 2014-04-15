#include "Errors.h"
#include "IdList.h"
#include "HeadPredicate.h"
#include "PredicateList.h"
#include "Lex.h"
#include "Rule.h"
#include "Datalog.h"


Rule::Rule(){}
Rule::Rule(Lex &lex){
	headPredicate = HeadPredicate(lex);
	lex.match(COLON_DASH);
	firstPredicate = Predicate(lex);
	predicateList = PredicateList(lex);
	lex.match(PERIOD);
};

string Rule::getId(int i){    
    if(i == 0)
        return firstPredicate.id.getTokensValue();
    else
        return predicateList.list[i - 1]->id.getTokensValue();
}

int Rule::size(){
    return 1 + predicateList.list.size();
}

Table Rule::eval(Datalog* db){
	
	vector<Table> list = vector<Table>();
	for(int i = 0; i < predicateList.list.size(); i++){
		list.push_back(predicateList.list[i]->eval(db));
	}
	
	Table output = eval(firstPredicate.eval(db), list);
	output._name = headPredicate.id.getTokensValue();
	
	// Create projection
	vector<string> projection = vector<string>();
	for(int i = 0; i < headPredicate.idList.size(); i++){
		if(headPredicate.idList.at(i).getTokenType() == ID){
			projection.push_back(headPredicate.idList.at(i).getTokensValue());
		}
	}
	
	return output.project(projection);
}

Table Rule::eval(Table left, vector<Table> list){
	if(list.size() > 1){
		Table secondLeft = list.at(list.size() - 1);
		list.pop_back();
		return left.join(left, eval(secondLeft, list));
	}else if(list.size() == 1){
		return left.join(left, list[0]);
	}else{
		return left;
	}
}

Rule::Rule(const Rule& orig){};

string Rule::toString() const{
	string output;
	output = "  ";
	output += headPredicate.toString();
	output += " :- ";
	output += firstPredicate.toString();
	output += predicateList.toString();
	output += ".\n";
	return output;
}