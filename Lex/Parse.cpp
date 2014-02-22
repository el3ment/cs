#include "Parse.h"
#include "Lex.h"
#include "TokenType.h"
#include "Errors.h"
#include <string>
#include <iostream>

using namespace std;

Parse::Parse() {
}

Parse::Parse(const Parse& orig) {
}

Parse::~Parse() {
}

Parse::Parse(const char* fileName){
    _lexicalStructure.parse(fileName);
}


string Parse::parse(){
    
	string output;
	
	try{
		Datalog* data = new Datalog(_lexicalStructure);
		output += "Success!\n";
		output += data->toString();
	}catch(int e){
		switch(e){
			case UNEXPECTED_TOKEN:
				output ="Failure!\n";
				output += "  ";
				output += _lexicalStructure.getCurrentToken()->toString();
				break;
			default:
				cout << "Unknown error";
				break;
		}
	}
	
	return output;
}

int main(int argc, char* argv[]) {
   
	
   
	Parse parser("active");
	cout << parser.parse();
    

    return 0;
}
