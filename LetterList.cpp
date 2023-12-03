
#include "LetterList.h"
#include <map>
#include <algorithm>


// Part 1
char LetterList::mostCommonCharacter() {
    std::map<char, int> letterFrequency;
    for (const auto& letter: letters){
        letterFrequency[letter]++;
    }

    auto maxElement = std::max_element(letterFrequency.begin(), letterFrequency.end(),
                                       [](const auto& p1, const auto& p2) {
                                           return p1.second < p2.second;
                                       });

    return maxElement->first;
}

// Part 2
char LetterList::leastCommonCharacter() {
    std::map<char, int> letterFrequency;
    for (const auto& letter: letters){
        letterFrequency[letter]++;
    }

    auto minElement = std::min_element(letterFrequency.begin(), letterFrequency.end(),
                                       [](const auto& p1, const auto& p2) {
                                           return p1.second < p2.second;
                                       });

    return minElement->first;
}
