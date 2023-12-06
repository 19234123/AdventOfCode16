#include "Functions.h"



vector<string> extractSubstringsBetween(const string& inputString, char startChar, char endChar) {
    size_t startIndex = 0;
    size_t endIndex = 0;
    vector<string> substrings;

    while (true) {
        startIndex = inputString.find(startChar, startIndex);
        endIndex = inputString.find(endChar, endIndex);

        if (startIndex != std::string::npos && endIndex != std::string::npos && startIndex < endIndex) {
            substrings.push_back(inputString.substr(startIndex + 1, endIndex - startIndex - 1));

            startIndex = endIndex + 1;
            endIndex = startIndex;
        } else {
            break;
        }
    }

    return substrings;
}

string trim(const string& str){
    size_t first = str.find_first_not_of(' ');
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last-first+1));
}

vector<string> readFile(const string& filePath){
    vector<string> rawInput;

    std::ifstream file(filePath);

    if (file.is_open()) {
        string line;
        while(std::getline(file, line)) {
            rawInput.push_back(line);
        }
    } else {
        std::cout << "Unable to open file";
    }
    return rawInput;
}


vector<string> splitLineToString(const string& line, const char& delimiter) {
    vector<string> splitString;

    std::stringstream stream(line);

    string currentLine;
    while (stream.good()) {
        std::getline(stream, currentLine, delimiter);
        if (!currentLine.empty()) {
            splitString.push_back(trim(currentLine));
        }
    }

    return splitString;
}

vector<int> splitLineToInt(const string& line, const char& delimiter) {
    vector<int> splitString;

    std::stringstream stream(line);

    string currentLine;
    while (stream.good()) {
        std::getline(stream, currentLine, delimiter);
        if (!currentLine.empty()) {
            splitString.push_back(std::stoi(trim(currentLine)));
        }
    }

    return splitString;
}