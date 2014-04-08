#include "RuleList.h"
#include "Rule.h"
#include "Datalog.h"
#include <vector>

using namespace std;

RuleList::RuleList(Lex &lex){
	parseRuleList(lex);
};

RuleList::RuleList(const RuleList& orig){};

void RuleList::parseRuleList(Lex &lex){ 
	if(lex.peek(ID)){
		list.push_back(new Rule(lex));
		parseRuleList(lex);
		return;
	}else if(lex.peek(QUERIES)){
		return;
	}

	throw UNEXPECTED_TOKEN;

};
string RuleList::toString() const{
	string output;
	for(int i = 0; i < list.size(); i++)
		output += list[i]->toString();
	return output;
}

void RuleList::eval(Datalog* db){
	
	// Loop through rules for as long as
	// the rules don't add any additional facts
	
	int oldCount;
	do{
		oldCount = db->countFacts();
		for(int i = 0; i < list.size(); i++){
			Table ruleTable = list.at(i)->eval(db);
			db->addTableToFacts(ruleTable);
		}
	}while(oldCount != db->countFacts());
}