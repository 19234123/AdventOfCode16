#ifndef ADVENTOFCODE16_STRINGPARSER_H
#define ADVENTOFCODE16_STRINGPARSER_H
#include <string>
#include "Functions.h"

using std::string;

class StringParser {
public:
    string inputString;
    long long decompressedLength;

    void setInputString(const string& input);
    long long getDecompressedStringLength();


};


#endif //ADVENTOFCODE16_STRINGPARSER_H
