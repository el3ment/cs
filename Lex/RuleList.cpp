#include "RuleList.h"
#include "Rule.h"
#include "Datalog.h"
#include <vector>
#include "DirectedGraph.h"

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

    directedGraph = DirectedGraph();
    
    for(int i = 0; i < list.size(); i++){
        for(int j = 0; j < list[i]->size(); j++){
            directedGraph.addEdge(list[i]->headPredicate.id.getTokensValue(), list[i]->getId(j));
        }
    }
    
    directedGraph.generateSCCs();
    
    // prune only to vital sccs
    
    for(int i = 0; i < directedGraph.sccs.size(); i++){
        directedGraph.sccs[i].eval(db);
    }
    
    cout << "The graph!" << endl<< directedGraph.toString();
}