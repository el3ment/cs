/* 
 * File:   ConnectedComponent.cpp
 * Author: robert
 * 
 * Created on April 14, 2014, 10:30 PM
 */

#include "ConnectedComponent.h"
#include "Datalog.h"
#include <sstream>

using namespace std;

ConnectedComponent::ConnectedComponent(vector<string> newVerticies) {
    vertcies = vector<string>(newVerticies);
}

ConnectedComponent::ConnectedComponent(const ConnectedComponent& orig) {
    vertcies = orig.vertcies;
}

ConnectedComponent::~ConnectedComponent() {
}

string ConnectedComponent::toString(){
    stringstream ss;
    
    for(int i = 0; i < vertcies.size(); i++){
        ss << vertcies[i] << ", ";
    }
    
    ss << endl;
    
    return ss.str();
}

bool ConnectedComponent::exists(string test){
    for(int i = 0; i < vertcies.size(); i++){
        if(vertcies[i] == test)
            return true;
    }
    return false;
}

void ConnectedComponent::eval(Datalog* db){
    
    vector<Rule*> list = db->ruleList.list;
    
    int oldCount;
    int n = 0;
    do{
        oldCount = db->countFacts();
        n++;
        for(int i = 0; i < list.size(); i++){
            // If the rule is in this component - do the deed
            if(exists(list[i]->headPredicate.id.getTokensValue())){
                Table ruleTable = list.at(i)->eval(db);
                db->addTableToFacts(ruleTable);
            }
        }
    }while(oldCount != db->countFacts());
}