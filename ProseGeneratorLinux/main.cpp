#include <cstdlib>
#include <iostream>
#include <fstream>
#include <map>
#include "GrammerRule.h"
#include "GrammerList.h"

using namespace std;

int main(int argc, char** argv) {

    GrammerList grammerList;
    grammerList.loadFile(argv[1]);
    
    ofstream outputFile(argv[2]);
    outputFile << grammerList.printGrammer() << endl;
    
    for(int i = 0; i < 10; i++){
        outputFile << grammerList.render() << endl;
    }
    
    ifstream print(argv[2]);
    string line;
    while(getline(print, line)){
        cout << line << endl;
    }
    
    return 0;
}

