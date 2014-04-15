/* 
 * File:   ConnectedComponent.h
 * Author: robert
 *
 * Created on April 14, 2014, 10:30 PM
 */

#ifndef CONNECTEDCOMPONENT_H
#define	CONNECTEDCOMPONENT_H

#include <vector>
#include "Rule.h"

class Datalog;

using namespace std;

class ConnectedComponent {
public:
    ConnectedComponent();
    ConnectedComponent(const ConnectedComponent& orig);
    virtual ~ConnectedComponent();
    
    vector<string> vertcies;
    
    string toString();
    void add(Rule newComponent);
    void eval(Datalog *db);
    bool exists(string vertex);
    
private:

};

#endif	/* CONNECTEDCOMPONENT_H */

