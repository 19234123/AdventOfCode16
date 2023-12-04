#ifndef ADVENTOFCODE16_ADDRESS_H
#define ADVENTOFCODE16_ADDRESS_H

#include <string>
#include <vector>
#include <list>

class Address {
public:
    std::string rawAddress;
    std::list<std::string> validSearchRange;
    std::list<std::string> invalidSearchRange;
    bool valid;

    explicit Address(const std::string& rawAddress);
    void setupSearchRange();
    void validateAddress();
    static bool validAddressRange(std::list<std::string>& range);
    static std::vector<std::string> splitLine(const std::string& line, const char& delimiter);
    static std::string trim(const std::string& str);
};


#endif //ADVENTOFCODE16_ADDRESS_H
