#include "StringParser.h"

long long StringParser::getDecompressedStringLength() {
    int inputStringIndex = 0;

    while (inputStringIndex < inputString.size()) {
        auto& currentChar = inputString[inputStringIndex];
        if (currentChar != '('){
            decompressedLength++;
            inputStringIndex++;
        } else {
            auto markerStartIndex = inputStringIndex + 1;
            auto markerEndIndex = inputString.find(')', inputStringIndex);
            auto markerSize = markerEndIndex - (markerStartIndex);

            string marker = inputString.substr(markerStartIndex, markerSize);
            vector<int> markerSplit = splitLineToInt(marker, 'x');

            string compressedChars = inputString.substr(markerEndIndex+1, markerSplit[0]);
            auto compressedLength = compressedChars.size();
            decompressedLength += (long long)(markerSplit[1]*compressedLength);

            inputStringIndex = (int)(markerEndIndex + compressedChars.size() + 1);
        }
    }

    return this->decompressedLength;
}

void StringParser::setInputString(const string &input) {
    this->inputString = input;
    this->decompressedLength = 0;
}
