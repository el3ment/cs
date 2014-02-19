#include "Parse.h"
#include "Lex.h"
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


int main(int argc, char* argv[]) {
   
    Parse parser("active");
    cout << parser.toString();

    return 0;
}
