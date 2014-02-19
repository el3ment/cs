
#include <string>
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <time.h>
#include "GrammerRule.h"

using namespace std;

GrammerRule::GrammerRule() {
}
GrammerRule::GrammerRule(string rule){
    this->rule = rule;
}
GrammerRule::GrammerRule(const GrammerRule& orig) {
    this->rule = orig.rule;
}

GrammerRule::~GrammerRule() {
}

string GrammerRule::render(map<string,vector<GrammerRule> > &grammerList){
    stringstream output;
    stringstream ruleStream(this->rule);
    string word;
    
    while(ruleStream >> word){
        if(word.substr(0, 1).compare("<") == 0 && grammerList[word].size() > 0){
            unsigned int random = (rand() % (grammerList[word].size()));
            output << grammerList[word][random].render(grammerList);
        }else{
            output << word << " ";
        }
    }

    return output.str();
}