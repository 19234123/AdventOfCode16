#ifndef ADVENTOFCODE16_PASSWORDGENERATOR_H
#define ADVENTOFCODE16_PASSWORDGENERATOR_H
#include "md5.h"


class PasswordGenerator {
public:
    int index;
    int passwordIndex;
    char nextChar;
    std::string input;
    std::string password;

    explicit PasswordGenerator(const std::string &input);
    char getNextCharacter();
    void nextIndexAndCharacter();
    void outputDecrypting();
    static int getRandomNumber(int max);

};


#endif //ADVENTOFCODE16_PASSWORDGENERATOR_H
