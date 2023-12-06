#ifndef ADVENTOFCODE16_FUNCTIONS_H
#define ADVENTOFCODE16_FUNCTIONS_H
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>

using std::string;
using std::vector;


vector<string> readFile(const string& filePath);
string trim(const string& str);
vector<int> splitLineToInt(const string& line, const char& delimiter);
vector<string> splitLineToString(const string& line, const char& delimiter);
vector<string> extractSubstringsBetween(const string& inputString, char startChar, char endChar);



#endif //ADVENTOFCODE16_FUNCTIONS_H
