#include "Datalog.h"

Datalog::Datalog(Lex& lex){
	if(lex.peek(SCHEMES)){
		lex.match(SCHEMES);
		lex.match(COLON);
		firstScheme = Scheme(lex);

		schemeList = SchemeList(lex);

		lex.match(FACTS);
		lex.match(COLON);
		factList = FactList(lex, domain);

		lex.match(RULES);
		lex.match(COLON);
		ruleList = RuleList(lex);

		lex.match(QUERIES);
		lex.match(COLON);

		firstQuery = Query(lex);
		queryList = QueryList(lex);

		parseSchemes();
		parseFacts();

	}else{
		throw UNEXPECTED_TOKEN;
	}
}

void Datalog::parseSchemes(){

	// Create the first table
	database.push_back(new Table(firstScheme.id, firstScheme.idList.firstId, firstScheme.idList.list));
		
	// Create other tables
	for(int i = 0; i < schemeList.list.size(); i++){
		database.push_back(new Table(schemeList.list.at(i)->id, schemeList.list.at(i)->idList.firstId, schemeList.list.at(i)->idList.list));
	}
	
}

void Datalog::parseFacts(){
	// Add facts as tuples to table
	for(int i = 0; i < factList.list.size(); i++){
		Table* workingTable = getTable(factList.list.at(i)->id);
		workingTable->add(Tuple(factList.list.at(i)->argumentList));
	}
}

Table* Datalog::getTable(Token id){
	for(int i = 0; i < database.size(); i++){
		if(database.at(i)->_name == id.getTokensValue()){
			
			return database.at(i);
		}
	}
}

vector<Query*> Datalog::getQueries(){
	vector<Query*> output = vector<Query*>();

	output.push_back(&firstQuery);
	for(int i = 0; i < queryList.list.size(); i++){
		output.push_back(queryList.list.at(i));
	}
	return output;
}

string Datalog::toString() const{
	string output;
	output += "Schemes(";
		output += schemeList.list.empty() ? "1" : itoa(1 + schemeList.list.size());
		output += "): \n";
		output += firstScheme.toString();
		output += schemeList.toString();
	output += "Facts(";
		output += itoa(factList.list.size());
		output += "): \n";
		output += factList.toString();
	output += "Rules(";
		output += itoa(ruleList.list.size());
		output += "): \n";
		output += ruleList.toString();
	output += "Queries(";
		output += queryList.list.empty() ? "1" : itoa(1 + queryList.list.size());
		output += "): \n";
		output += firstQuery.toString();
		output += queryList.toString();
	output += "Domain(";
		output += itoa(domain.list.size());
		output += "): \n";
		output += domain.toString();
	return output;
};
