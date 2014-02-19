/* 
 * File:   newsimpletest.cpp
 * Author: robert
 *
 * Created on Feb 3, 2014, 3:37:22 PM
 */

#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <algorithm>
#include "Lex.h"

using namespace std;

bool compareFiles(string filename1, string filename2, string name){
    
    bool returnBool = true;
    
    string linefile1;
    string linefile2;
    
    unsigned int lineNumber = 0;
    
    ifstream file1;
    ifstream file2;
    
    file1.open(filename1.c_str());
    file2.open(filename2.c_str());
    
    do{
        getline(file1, linefile1);
        getline(file2, linefile2);
        
        linefile1.erase(std::find_if(linefile1.rbegin(), linefile1.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), linefile1.end());
        linefile2.erase(std::find_if(linefile2.rbegin(), linefile2.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), linefile2.end());
        
        if(linefile1.compare(linefile2) != 0 || !returnBool){
            cout << "%TEST_FAILED% time=0 testname=" << name << " (newsimpletest) message=";
			cout << "     Expecting : " << linefile1 << " (size " << linefile1.size() << ")" << endl;
			cout << "           Got : " << linefile2 << " (size " << linefile2.size() << ") on line #" << lineNumber << endl;
			return false;
        }
        
        lineNumber++;
        
    }while(file1 && file2 && !file1.eof() && !file2.eof());
    
    file1.close();
    file2.close();
    
    return returnBool;
    
}

string saveStringToTempFile(string content){
	ofstream tempFile;
	tempFile.open ("temp");
	tempFile << content;
	tempFile.close();
	return "temp";
}

void deleteTempFile(){
	remove("temp");
}

void blank() {
	Lex lex("./blank");
	compareFiles(saveStringToTempFile(lex.toString()), "./blank_output", "blank");
}

void quotes_multiline() {
	Lex lex("./quotes_multiline");
	compareFiles(saveStringToTempFile(lex.toString()), "./quotes_multiline_output", "quotes_multiline");
}

void single_line() {
	Lex lex("./single_line");
	compareFiles(saveStringToTempFile(lex.toString()), "./single_line_output", "single_line");
}

void single_token() {
	Lex lex("./single_token");
	compareFiles(saveStringToTempFile(lex.toString()), "./single_token_output", "single_token");
}
void comment() {
	
	try{
	  Lex lex("./comment");
	  compareFiles(saveStringToTempFile(lex.toString()), "./comment_output", "comment");
	}catch (string e){
		cout << "%TEST_FAILED% time=0 testname=comment (newsimpletest) message=" << e << endl;
	}
	
}

void wiki1() {
	
	try{
	  Lex lex("./wiki1");
	  compareFiles(saveStringToTempFile(lex.toString()), "./wiki1_output", "wiki1");
	}catch (string e){
		cout << "%TEST_FAILED% time=0 testname=wiki1 (newsimpletest) message=" << e << endl;
	}
	
}

void wiki2() {
	
	try{
	  Lex lex("./wiki2");
	  compareFiles(saveStringToTempFile(lex.toString()), "./wiki2_output", "wiki2");
	}catch (string e){
		cout << "%TEST_FAILED% time=0 testname=wiki2 (newsimpletest) message=" << e << endl;
	}
	
}

int main(int argc, char** argv) {
	std::cout << "%SUITE_STARTING% newsimpletest" << std::endl;
	std::cout << "%SUITE_STARTED%" << std::endl;

	std::cout << "%TEST_STARTED% blank (newsimpletest)" << std::endl;
	blank();
	std::cout << "%TEST_FINISHED% time=0 blank (newsimpletest)" << std::endl;

	std::cout << "%TEST_STARTED% quotes_multiline (newsimpletest)" << std::endl;
	quotes_multiline();
	std::cout << "%TEST_FINISHED% time=0 multiline (newsimpletest)" << std::endl;
	
	std::cout << "%TEST_STARTED% single_line (newsimpletest)" << std::endl;
	single_line();
	std::cout << "%TEST_FINISHED% time=0 single_line (newsimpletest)" << std::endl;
	
	std::cout << "%TEST_STARTED% single_token (newsimpletest)" << std::endl;
	single_token();
	std::cout << "%TEST_FINISHED% time=0 single_token (newsimpletest)" << std::endl;

	std::cout << "%TEST_STARTED% comment (newsimpletest)" << std::endl;
	comment();
	std::cout << "%TEST_FINISHED% time=0 comment (newsimpletest)" << std::endl;

	std::cout << "%TEST_STARTED% wiki1 (newsimpletest)" << std::endl;
	wiki1();
	std::cout << "%TEST_FINISHED% time=0 wiki1 (newsimpletest)" << std::endl;
	
	std::cout << "%TEST_STARTED% wiki2 (newsimpletest)" << std::endl;
	wiki2();
	std::cout << "%TEST_FINISHED% time=0 wiki2 (newsimpletest)" << std::endl;
		

	std::cout << "%SUITE_FINISHED% time=0" << std::endl;

	return (EXIT_SUCCESS);
}