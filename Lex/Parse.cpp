#include "Parse.h"
#include "Lex.h"
#include "TokenType.h"
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


string Parse::toString() const{
    return _lexicalStructure.toString();
}

bool Parse::peek(TokenType test){ return true; }
bool Parse::match(TokenType consume){ return true; }
bool Parse::parseScheme(){ return true; };
bool Parse::parseSchemeList(){ return true; };
bool Parse::parseFactList(){ return true; };
bool Parse::parseRuleList(){ return true; };
bool Parse::parseQuery(){ return true; };
bool Parse::parseQueryList(){ return true; };

bool Parse::parseDatalog(){
    if(peek(SCHEMES)){
        return match(SCHEMES) && match(COLON) && parseScheme() && parseSchemeList()
                && match(FACTS) && match(COLON) && parseFactList()
                && match(RULES) && match(COLON) && parseRuleList()
                && match(QUERIES) && match(COLON) && parseQuery() && parseQueryList();
    }else{
        // throw error
    }
}


int main(int argc, char* argv[]) {
   
    Parse parser("active");
    cout << parser.toString();

    return 0;
}
