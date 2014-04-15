#include "RuleList.h"
#include "Rule.h"
#include "Datalog.h"
#include <vector>
#include "Utils.h"
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
    
    // Create list of used predicate ids
    vector<string> usedRules = vector<string>();
    usedRules.push_back(db->firstQuery.predicate.id.getTokensValue());
    for(int i = 0; i < db->queryList.list.size(); i++){
        usedRules.push_back(db->queryList.list[i]->predicate.id.getTokensValue());
    }
    
    // Generate the graph
    for(int i = 0; i < list.size(); i++){
        for(int j = 0; j < list[i]->size(); j++){
            // Prune to only rules that are referenced by queries
            if(existsStringInStringVector(usedRules, list[i]->headPredicate.id.getTokensValue())){
                //if(list[i]->headPredicate.id.getTokensValue() != list[i]->getId(j))
                    directedGraph.addEdge(list[i]->headPredicate.id.getTokensValue(), list[i]->getId(j));
            }
        }
    }
    
    // Generate the SCCs
    directedGraph.generateSCCs();
    
    // Evaluate the SCCs
    for(int i = 0; i < directedGraph.sccs.size(); i++){
        directedGraph.sccs[i].eval(db);
    }
    
}