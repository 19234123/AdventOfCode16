#include "Address.h"
#include <string>
#include <vector>
#include <sstream>

using std::vector;
using std::string;


Address::Address(const std::string& rawAddress) {
    this->rawAddress = rawAddress;
    this->valid = false;
    setupSearchRange();
    validateAddress();
}

void Address::validateAddress(){
    if (validAddressRange(validSearchRange) && !validAddressRange(invalidSearchRange)){
        valid = true;
    }
}

bool Address::validAddressRange(std::list<std::string>& range){
    for (const auto& line: range){
        string firstPair;
        string secondPair;
        int maxIndex = line.size()-3;

        for (int i=0; i<maxIndex; i++){
            firstPair += line[i];
            firstPair += line[i+1];
            secondPair += line[i+2];
            secondPair += line[i+3];

            if (firstPair[0] != firstPair[1]){
                if (firstPair[0] == secondPair[1] && firstPair[1] == secondPair[0]){
                    return true;
                }
            }
            firstPair.clear();
            secondPair.clear();
        }
    }
    return false;
}


void Address::setupSearchRange() {
    vector<string> addressSplit = splitLine(rawAddress, '[');
    validSearchRange.push_back(addressSplit.at(0));
    addressSplit.erase(addressSplit.begin());

    for (const auto& line: addressSplit) {
        vector<string> lineSplit = splitLine(line, ']');
        invalidSearchRange.push_back(lineSplit.at(0));
        validSearchRange.push_back(lineSplit.at(1));
    }
}


string Address::trim(const string& str){
    size_t first = str.find_first_not_of(' ');
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last-first+1));
}

std::vector<std::string> Address::splitLine(const std::string& line, const char& delimiter){
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