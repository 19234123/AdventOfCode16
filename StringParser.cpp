#include "StringParser.h"

string StringParser::getDecompressedString() {
    int inputStringIndex = 0;

    while (inputStringIndex < inputString.size()) {
        auto& currentChar = inputString[inputStringIndex];
        if (currentChar != '('){
            decompressedString += currentChar;
            inputStringIndex++;
        } else {
            auto markerStartIndex = inputStringIndex + 1;
            auto markerEndIndex = inputString.find(')', inputStringIndex);
            auto markerSize = markerEndIndex - (markerStartIndex);

            string marker = inputString.substr(markerStartIndex, markerSize);
            vector<int> markerSplit = splitLineToInt(marker, 'x');

            string compressedChars = inputString.substr(markerEndIndex+1, markerSplit[0]);
            for (int i=0; i<markerSplit[1]; i++) {
                decompressedString += compressedChars;
            }
            inputStringIndex = (int)(markerEndIndex + compressedChars.size() + 1);
        }
    }

//    vector<string> lineData = splitLine(input, ')');
//    string decompressedString;
//
//    for (int i=0; i<input.size(); input) {
//        char currentChar = input[i];
//        string x;
//    }

    return this->decompressedString;
}

void StringParser::setInputString(const string &input) {
    this->inputString = input;
    this->decompressedString.clear();

}
