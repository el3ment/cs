#include "Lex.h"

#include "Input.h"
#include "TokenType.h"
#include "Utils.h"
#include <iostream>
#include <ctype.h>

using namespace std;

Lex::Lex() {
    input = new Input();
    generateTokens(input);
}

Lex::Lex(const char* filename) {
    parse(filename);
}

Lex::Lex(istream& istream) {
    input = new Input(istream);
    generateTokens(input);
}

Lex::Lex(const Lex& lex) {
    input = new Input(*lex.input);
    tokens = new vector<Token*>();

    vector<Token*>::iterator iter;
    for(iter=lex.tokens->begin(); iter != lex.tokens->end(); iter++) {
        Token* newToken = new Token(**iter);
        tokens->push_back(newToken);
    }

    index = lex.index;
    state = lex.state;
}

Lex::~Lex(){
    for (int i = 0; i < tokens->size(); i++) {
        delete (*tokens)[i];
    }
    delete tokens;
    delete input;
}

void Lex::parse(const char* fileName){
    input = new Input(fileName);
    generateTokens(input);
}

bool Lex::operator==(const Lex& lex) {
    bool result = (tokens->size() == lex.tokens->size()) && (index == lex.index);
    if(result) {
        vector<Token*>::iterator iter1;
        vector<Token*>::iterator iter2;
        iter1 = tokens->begin();
        iter2 = lex.tokens->begin();
        while(result && iter1 != tokens->end() && iter2 != lex.tokens->end()) {
            result = **iter1 == **iter2;
            iter1++;
            iter2++;
        }
        result = result && iter1 == tokens->end() && iter2 == lex.tokens->end();
    }
    return result;
}

string Lex::toString() const {
    int count = 0;
    string result;
    while(count < tokens->size()) {
        Token* token = (*tokens)[count];
        result += token->toString();
        count++;
    }
    result += "Total Tokens = ";
    string countToString;
    result += itoa(countToString, count);
    result += "\n";
    return result;
}

void Lex::generateTokens(Input* input) {
    tokens = new vector<Token*>();
    index = 0;

    state = Start;
    while(state != End) {
        state = nextState();
    }
}

Token* Lex::getCurrentToken() {
    return (*tokens)[index];
}

void Lex::advance() {
    index++;
}

bool Lex::hasNext() {
    return index < tokens->size();
}

State Lex::nextState() {
    State result;
    char character = input->getCurrentCharacter();
	switch(state) {
        case Start:
                result = getNextState(); 
		break;
			
        case Comma:
                emit(COMMA);
		result = getNextState();
		break;
			
        case Period:
		emit(PERIOD);
		result = getNextState();
		break;
			
        case SawColon:
            character = input->getCurrentCharacter();
            if(character == '-') {
                result = Colon_Dash;
                input->advance();
            } else { //Every other character
                emit(COLON);
				result = getNextState();
            }
            break;
			
        case Colon_Dash:
			emit(COLON_DASH); 
			result = getNextState(); 
			break;
			
        case SawAQuote:  
            character = input->getCurrentCharacter();
            if(character == '\'') {
                result = PossibleEndOfString;
            } else if(character == -1) {
                result = Undefined;
            } else { //Every other character
                result = ProcessingString;
            }
            input->advance();
            break;
			
        case ProcessingString:  
            character = input->getCurrentCharacter();
            if(character == '\'') {
                result = PossibleEndOfString;
            } else if(character == -1) {
                result = Undefined;
            } else { //Every other character
                result = ProcessingString;
            }
            input->advance();
            break;
			
        case PossibleEndOfString:
            if(input->getCurrentCharacter() == '\'') {
                input->advance();
                result = ProcessingString;
            } else { //Every other character
                emit(STRING);
                result = getNextState();
            }
            break;
			
        case SawComment:
                //character = input->getCurrentCharacter();
                if(character == '#'){
                    result = SawComment;
                    input->advance();
                }else if(character == '|'){
                    result = ProcessingBlockComment;
                    input->advance();
                }else if(character == '\n'){
                    //emit(COMMENT);
					input->mark();
                    result = getNextState();
                }else{
                     result = ProcessingComment;
                     input->advance();
                }
                
                break;

        case ProcessingBlockComment:
                //character = input->getCurrentCharacter();
                if(character == '|'){
                        result = PossibleEndOfComment;
                }else if(character == -1){
                        result = Undefined;
                }else{
                        result = ProcessingBlockComment;
                }
                input->advance();
                break;

        case PossibleEndOfComment:
                if(character == '#'){

                        input->advance(); // We could make another state called "sawClosingPipe"
                                                          // but it seemed unnecessary

                        //emit(COMMENT);
						input->mark();
                        result = getNextState();
                }else{
                        result = ProcessingBlockComment;
                        input->advance();
                }
                break;

        case ProcessingComment:
                //character = input->getCurrentCharacter();
                if(character == '\n' || character == -1){
                        //emit(COMMENT);
						input->mark();
                        result = getNextState();
                }else{
                        input->advance();
                        result = ProcessingComment;
                }

                break;

        case Keyword:
			// Loop until we find the end of the keyword
			while(isalnum(character)){
					input->advance();
					character = input->getCurrentCharacter();
			}

			if(input->getTokensValue() == "Schemes")
					emit(SCHEMES);
			else if(input->getTokensValue() == "Queries")
					emit(QUERIES);
			else if(input->getTokensValue() == "Rules")
					emit(RULES);
			else if(input->getTokensValue() == "Facts")
					emit(FACTS);
			else
					emit(ID); // Otherwise, it must be an ID

			result = getNextState();

			break;

        case Whitespace:
			if(isspace(character)){
					input->advance();
					result = Whitespace;
			}else{
					//emit(WHITESPACE);
					input->mark();
					result = getNextState();
			}
			break;

        case Left_Paren:
			emit(LEFT_PAREN);
			result = getNextState();
			break;

        case Right_Paren:
			emit(RIGHT_PAREN);
			result = getNextState();
			break;

        case Q_Mark:
			emit(Q_MARK);
			result = getNextState();
			break;

        case Multiply:
			emit(MULTIPLY);
			result = getNextState();
			break;

        case Add:
			emit(ADD);
			result = getNextState();
			break;

        case Undefined:
			emit(UNDEFINED);
			result = getNextState();
			break;

        case EndOfFile:
			emit(ENDOFFILE);
			result = End;
			break;
			
	case End:
            throw "ERROR:: in End state:, the Input should be empty once you reach the End state."; 
            break;
		default:
			throw "ERROR:: Unknown state";
    };
    return result;
}

State Lex::getNextState() {
    State result;
    char currentCharacter = input->getCurrentCharacter();

    //The handling of checking for whitespace and setting the result to Whilespace and
    //checking for letters and setting the result to Id will probably best be handled by
    //if statements rather then the switch statement.
    switch(currentCharacter) {
        case ','  : result = Comma; break;
        case '.'  : result = Period; break;
        case ':'  : result = SawColon; break;
        case '\'' : result = ProcessingString; break;
        case '#'  : result = SawComment; break;
        case '+'  : result = Add; break;
        case '*'  : result = Multiply; break;
        case '('  : result = Left_Paren; break;
        case ')'  : result = Right_Paren; break;
        case '?'  : result = Q_Mark; break;
        case -1   : result = EndOfFile; break;
        default:
            if(isspace(currentCharacter))
                    result = Whitespace;
            else if(isalpha(currentCharacter)){
                    result = Keyword;
            }else{
                    result = Undefined;
            }
    }
    input->advance();
    return result;
}

void Lex::emit(TokenType tokenType) {
    Token* token = new Token(tokenType, input->getTokensValue(), input->getCurrentTokensLineNumber());
    storeToken(token);
    input->mark();
}

void Lex::storeToken(Token* token) {
    //This section should ignore whitespace and comments and change the token type to the appropriate value
    //if the value of the token is "Schemes", "Facts", "Rules", or "Queries".
    tokens->push_back(token);
}