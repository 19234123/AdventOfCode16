#ifndef ADVENTOFCODE16_STRINGPARSER_H
#define ADVENTOFCODE16_STRINGPARSER_H
#include <string>
#include "Functions.h"

using std::string;

class StringParser {
public:
    string inputString;
    string decompressedString;

    void setInputString(const string& input);
    string getDecompressedString();


};


#endif //ADVENTOFCODE16_STRINGPARSER_H
