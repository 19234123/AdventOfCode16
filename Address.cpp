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
    referenceSequences = setValidSequences(referenceList);
    validationSequences = setValidSequences(validationList);

    for (const auto& reference: referenceSequences){
        for (const auto& validation: validationSequences){
            if (reference[0] == validation[1] && reference[1] == validation[0]){
                valid = true;
            }
        }
    }
}

std::list<std::string> Address::setValidSequences(std::list<std::string>& range){
    std::list<std::string> validSequences;
    for (const auto& line: range){
        string firstPair;
        string secondPair;
        int maxIndex = line.size()-2;

        for (int i=0; i<maxIndex; i++){
            string testSequence = line.substr(i, 3);
            if (testSequence[0] == testSequence[2] && testSequence[0] != testSequence[1]){
                validSequences.push_back(testSequence);
            }
        }
    }
    return validSequences;
}


void Address::setupSearchRange() {
    vector<string> addressSplit = splitLine(rawAddress, '[');
    referenceList.push_back(addressSplit.at(0));
    addressSplit.erase(addressSplit.begin());

    for (const auto& line: addressSplit) {
        vector<string> lineSplit = splitLine(line, ']');
        validationList.push_back(lineSplit.at(0));
        referenceList.push_back(lineSplit.at(1));
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