#ifndef ADVENTOFCODE16_LETTERLIST_H
#define ADVENTOFCODE16_LETTERLIST_H

#include <list>
#include <string>

class LetterList {
public:
    std::string letters{};

    char mostCommonCharacter();
    char leastCommonCharacter();
};


#endif //ADVENTOFCODE16_LETTERLIST_H
