#include "Parse.h"
#include "Lex.h"
#include <string>
#include <iostream>

using namespace std;

Parse::Parse() {
}

Parse::Parse(const Parse& orig) {
}

Parse::Parse(const char* fileName){
    _lexicalStructure.parse(fileName);
}

Parse::~Parse() {
}

string Parse::toString() const{
    return _lexicalStructure.toString();
}


int main(int argc, char* argv[]) {

    Parse parser("active");
    cout << parser.toString();

    //saveStringToFile(argv[2], lex.toString());

    return 0;
}
