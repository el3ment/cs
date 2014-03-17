#include "Datalog.h"
#include "Query.h"
#include <tr1/unordered_set>

using namespace std;

Query::Query(Lex &lex){
	predicate = Predicate(lex);
	lex.match(Q_MARK);
};
string Query::toString() const{
	string output;
	output = "  ";
	output += predicate.toString();
	output += "?\n";
	return output;
}

Table Query::evaluate(Datalog* data){	
	
	Table output = Table(data->getTable(predicate.id));

	vector<string> projection = vector<string>();
	
	for(int i = 0; i < predicate.size(); i++){
		
		if(predicate.at(i)->token.getTokenType() == ID){
			projection.push_back(predicate.at(i)->token.getTokensValue());
		}
		
		output = predicate.at(i)->eval(output, i);
	}
	
	output = output.project(projection);

	return output;
}
