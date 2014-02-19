
#include <string>
#include <map>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

#ifndef GRAMMERRULE_H
#define	GRAMMERRULE_H

class GrammerRule {
public:
    GrammerRule();
    GrammerRule(string  rule);
    GrammerRule(const GrammerRule& orig);
    virtual ~GrammerRule();
    string rule;
    string render(map< string, vector<GrammerRule> > &grammerList);
    
private:

};

#endif	/* GRAMMERRULE_H */

