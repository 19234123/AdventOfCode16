#include "StringParser.h"


StringParser::CompressedSubstring::CompressedSubstring(const string &substring, int multiplier) {
    this->substring = substring;
    this->multiplier = multiplier;
    this->decompressedLength = substringDecompressedLength();
}

bool StringParser::CompressedSubstring::hasCompressionMarker() const {
    return substring.find('(') != string::npos;
}

long long StringParser::CompressedSubstring::substringDecompressedLength() {
    long long length = 0;
    if (hasCompressionMarker()){
        length = getDecompressedStringLength(substring, 0);
        length *= multiplier;
    } else {
        length = (long long) (multiplier * substring.size());
    }
    return length;
}


StringParser::StringParser(const string &inputString) {
    this->decompressedLength = getDecompressedStringLength(inputString, 0);
}


long long StringParser::getDecompressedStringLength(const string& inputString, int stringIndex) {
    long long decompressedStringLength = 0;

    while (stringIndex < inputString.size()) {
        auto &currentChar = inputString[stringIndex];
        if (currentChar != '(') {
            decompressedStringLength++;
            stringIndex++;
        } else {
            auto markerStartIndex = stringIndex + 1;
            auto markerEndIndex = inputString.find(')', stringIndex);
            auto markerSize = markerEndIndex - (markerStartIndex);

            string marker = inputString.substr(markerStartIndex, markerSize);
            vector<int> markerSplit = splitLineToInt(marker, 'x');

            string compressedChars = inputString.substr(markerEndIndex + 1, markerSplit[0]);
            auto compressedLength = compressedChars.size();

            auto compressedSubstring = new CompressedSubstring(compressedChars, markerSplit[1]);
            decompressedStringLength += compressedSubstring->decompressedLength;

            stringIndex = (int) (markerEndIndex + compressedLength + 1);
        }
    }

    return decompressedStringLength;
}