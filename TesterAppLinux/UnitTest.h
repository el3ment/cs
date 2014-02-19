/* 
 * File:   UnitTest.h
 * Author: robert
 *
 * Created on February 4, 2013, 9:07 AM
 */

#ifndef UNITTEST_H
#define	UNITTEST_H

#include <vector>
#include <string>
#include <set>

using namespace std;

struct testFile{
    string name;
    string letter;
    string type;
    string number;
    bool parsed;
};

class UnitTest {
public:
    UnitTest();
    UnitTest(const UnitTest& orig);
    virtual ~UnitTest();
    
    string testNumber;
    set<string> inputFiles;
    testFile outputFile;
    string assertTest;
    
    bool assert(string executeable);
    void addFile(testFile file);
    
private:
    string buildCommand(string executeable);
    bool compareFiles(string file1, string file2);
    void emptyAssertionTestFile();
};

#endif	/* UNITTEST_H */

