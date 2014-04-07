#include "Lex.h"
#include "Parse.h"
#include "TokenType.h"
#include "Errors.h"
#include <string>
#include <iostream>
#include "Datalog.h"

using namespace std;

Parse::Parse() {
}

Parse::Parse(const char* fileName){
	lexicalStructure = new Lex(fileName);
}

Parse::Parse(const Parse& orig){}

Parse::~Parse() {
	delete lexicalStructure;
}

Datalog* Parse::parse(){
    
	Datalog* data = new Datalog(*lexicalStructure);
	
	return data;
}

int main(int argc, char* argv[]) {
  
	Parse parser = Parse("active");
	Datalog* data = parser.parse();
	
	vector<Query*> queries = data->getQueries();
	for(int i = 0; i < queries.size(); i++){
		Table response = queries.at(i)->evaluate(data);
		string countString = "No";
		
		if(response.count() > 0){
			countString = "Yes(";
			countString += itoa(response.count());
			countString += ")";
		}
		
		cout << queries.at(i)->predicate.toString() << "? " << countString << endl;
		cout << response.toString();
	
	}

    return 0;
}
