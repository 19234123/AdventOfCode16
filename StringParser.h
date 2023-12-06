#ifndef ADVENTOFCODE16_STRINGPARSER_H
#define ADVENTOFCODE16_STRINGPARSER_H
#include <string>
#include "Functions.h"

using std::string;
using std::vector;

class StringParser {
private:
    class CompressedSubstring {
    public:
        int multiplier;
        string substring;
        long long decompressedLength;

        CompressedSubstring(const string& substring, int multiplier);
    private:
        [[nodiscard]] bool hasCompressionMarker() const;
        long long substringDecompressedLength();
    };

public:
    long long decompressedLength;

    explicit StringParser(const string& inputString);
    static long long getDecompressedStringLength(const string& inputString, int stringIndex);
};


#endif //ADVENTOFCODE16_STRINGPARSER_H
