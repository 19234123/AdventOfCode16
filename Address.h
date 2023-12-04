#ifndef ADVENTOFCODE16_ADDRESS_H
#define ADVENTOFCODE16_ADDRESS_H

#include <string>
#include <vector>
#include <list>

class Address {
public:
    std::string rawAddress;
    std::list<std::string> referenceList;
    std::list<std::string> validationList;
    std::list<std::string> referenceSequences;
    std::list<std::string> validationSequences;
    bool valid;

    explicit Address(const std::string& rawAddress);
    void setupSearchRange();
    void validateAddress();
    static std::list<std::string> setValidSequences(std::list<std::string>& range);
    static std::vector<std::string> splitLine(const std::string& line, const char& delimiter);
    static std::string trim(const std::string& str);
};


#endif //ADVENTOFCODE16_ADDRESS_H
