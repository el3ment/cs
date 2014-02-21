#include "Parse.h"
#include "Lex.h"
#include "TokenType.h"
#include <string>
#include <iostream>

using namespace std;

const int UNEXPECTED_TOKEN = 1;

Parse::Parse() {
}

Parse::Parse(const Parse& orig) {
}

Parse::~Parse() {
}

Parse::Parse(const char* fileName){
    _lexicalStructure.parse(fileName);
}


string Parse::toString() const{
    return _lexicalStructure.toString();
}

Token* Parse::getCurrentToken(){
	return _lexicalStructure.getCurrentToken();
}

// Look at the current token, test it against the argument
bool Parse::peek(TokenType test){ 
	return _lexicalStructure.getCurrentToken()->getTokenType() == test;
}

// Test the current token, if successful advance, otherwise throw an error
bool Parse::match(TokenType consume){ 
	if(_lexicalStructure.getCurrentToken()->getTokenType() == consume){
		_lexicalStructure.advance();
		return true;
	}
	
	throw UNEXPECTED_TOKEN;
}

bool Parse::parseScheme(){
	if(peek(ID)){
		return match(ID) && match(LEFT_PAREN) && match(ID) && parseIdList() 
				&& match(RIGHT_PAREN);
	}
	
	throw UNEXPECTED_TOKEN;
};

bool Parse::parseIdList(){
	if(peek(COMMA)){
		return match(COMMA) && match(ID) && parseIdList();
	}else if(peek(RIGHT_PAREN)){
		return true;
	}
		
	throw UNEXPECTED_TOKEN;
}

bool Parse::parseSchemeList(){
	if(peek(ID)){
		return parseScheme() && parseSchemeList();
	}else if(peek(FACTS)){
		return true;
	}
	
	throw UNEXPECTED_TOKEN;
};
bool Parse::parseFactList(){ 
	if(peek(ID)){
		return parseFact() && parseFactList();
	}else if(peek(RULES)){
		return true;
	}
	
	throw UNEXPECTED_TOKEN;
}

bool Parse::parseFact(){
	if(peek(ID)){
		return match(ID) && match(LEFT_PAREN) && match(STRING) 
				&& parseStringList() && match(RIGHT_PAREN) && match(PERIOD);
	}
	
	throw UNEXPECTED_TOKEN;
}

bool Parse::parseStringList(){
	if(peek(COMMA)){
		return match(COMMA) && match(STRING) && parseStringList();
	}else if(peek(RIGHT_PAREN)){
		return true;
	}
	
	throw UNEXPECTED_TOKEN;
}
bool Parse::parseRuleList(){ 
	if(peek(ID)){
		return parseRule() && parseRuleList();
	}else if(peek(QUERIES)){
		return true;
	}
	
	throw UNEXPECTED_TOKEN;
	
};

bool Parse::parseRule(){
	if(peek(ID)){
		return parseHeadPredicate() && match(COLON_DASH) && parsePredicate() 
				&& parsePredicateList() && match(PERIOD);
	}
	
	throw UNEXPECTED_TOKEN;
}
bool Parse::parseHeadPredicate(){
	if(peek(ID)){
		return match(ID) && match(LEFT_PAREN) && match(ID) && parseIdList() 
				&& match(RIGHT_PAREN);
	}
	
	throw UNEXPECTED_TOKEN;
}
bool Parse::parsePredicate(){
	if(peek(ID)){
		return match(ID) && match(LEFT_PAREN) && parseParameter() 
				&& parseParameterList() && match(RIGHT_PAREN);
	}
	
	throw UNEXPECTED_TOKEN;
}

bool Parse::parseParameter(){
	if(peek(STRING)){
		return match(STRING);
	}else if(peek(ID)){
		return match(ID);
	}else if(peek(LEFT_PAREN)){
		return parseExpression();
	}
	
	throw UNEXPECTED_TOKEN;
}

bool Parse::parseExpression(){
	if(peek(LEFT_PAREN)){
		return match(LEFT_PAREN) && parseParameter() && parseOperator() 
				&& parseParameter() && match(RIGHT_PAREN);
	}
	
	throw UNEXPECTED_TOKEN;
}

bool Parse::parseOperator(){
	if(peek(ADD)){
		return match(ADD);
	}else if(peek(MULTIPLY)){
		return match(MULTIPLY);
	}
	
	throw UNEXPECTED_TOKEN;
}

bool Parse::parseParameterList(){
	if(peek(COMMA)){
		return match(COMMA) && parseParameter() && parseParameterList();
	}else if(peek(RIGHT_PAREN)){
		return true;
	}
	
	throw UNEXPECTED_TOKEN;
}

bool Parse::parsePredicateList(){
	if(peek(COMMA)){
		return match(COMMA) && parsePredicate() && parsePredicateList();
	}else if(peek(PERIOD)){
		return true;
	}
	
	throw UNEXPECTED_TOKEN;
}
bool Parse::parseQuery(){ 
	if(peek(ID)){
		return parsePredicate() && match(Q_MARK);
	}
	
	throw UNEXPECTED_TOKEN;
};
bool Parse::parseQueryList(){ 
	if(peek(ID)){
		return parseQuery() && parseQueryList();
	}else if(peek(ENDOFFILE)){
		return true;
	}

	throw UNEXPECTED_TOKEN;
};

bool Parse::parseDatalog(){
    if(peek(SCHEMES)){
        return match(SCHEMES) && match(COLON) && parseScheme() && parseSchemeList()
                && match(FACTS) && match(COLON) && parseFactList()
                && match(RULES) && match(COLON) && parseRuleList()
                && match(QUERIES) && match(COLON) && parseQuery() && parseQueryList();
    }
	
	throw UNEXPECTED_TOKEN;
}


int main(int argc, char* argv[]) {
   
	Parse parser("active");
   
	try{
		cout << parser.parseDatalog();
		cout << parser.toString();
	}catch(int e){
		switch(e){
			case UNEXPECTED_TOKEN:
				cout << "Failure! " << parser.getCurrentToken()->toString();
				break;
			default:
				cout << "Unknown error";
				break;
		}
	}
    

    return 0;
}
