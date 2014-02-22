#include "Utils.h"

#include <sstream>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

string& itoa(string& answer, int i) {
    stringstream ss;
    ss << i;
    answer = ss.str();
    return answer;
}

string itoa(int i) {
    stringstream ss;
    ss << i;
    return ss.str();
}

string saveStringToFile(string filename, string content){
	ofstream tempFile;
	tempFile.open(filename.c_str());
	tempFile << content;
	tempFile.close();
	return filename;
}