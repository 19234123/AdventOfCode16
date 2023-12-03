#include "PasswordGenerator.h"
#include <string>
#include <random>

PasswordGenerator::PasswordGenerator(const std::string &input) {
    this->index = 0;
    this->passwordIndex = -1;
    this->nextChar = ' ';
    this->input = input;
    this->password = "........";
}

// Part 1
char PasswordGenerator::getNextCharacter() {
    std::string hash;
    std::string testString;

    do {
        testString = input + std::to_string(index);
        hash = md5(testString);
        index++;
    } while (hash.substr(0,5) != "00000");

    std::cout << index-1 << ": " << hash << std::endl;

    return hash[5];
}

// Part 2
void PasswordGenerator::nextIndexAndCharacter() {
    std::string hash;
    std::string testString;
    bool found = false;

    do {
        testString = input + std::to_string(index);
        hash = md5(testString);
        index++;

        if (index % 250000 == 0){
            outputDecrypting();
        }
    } while (hash.substr(0,5) != "00000");


    if (isdigit(hash[5])){
        std::string indexStr {hash[5]};
        int nextIndex = std::stoi(indexStr);

        if (nextIndex >= 0 && nextIndex <= 7) {
            passwordIndex = nextIndex;
            nextChar = hash[6];

            if (password[passwordIndex] == '.') {
                found = true;
                password[passwordIndex] = nextChar;
            }
        }
    }

    if (!found){
        nextIndexAndCharacter();
    }
}

void PasswordGenerator::outputDecrypting() {
    std::string currentPassword = this->password;
    std::string randomCharacters = "1234567890-=qwertyuiop[]asdfghjkl;'#zxcvbnm,./!£$%^&*()_+{}:@~<>?";

    for (int i=0; i<currentPassword.size(); i++){
        if (currentPassword[i] == '.'){
            int idx = getRandomNumber(randomCharacters.size());
            currentPassword[i] = randomCharacters[idx];
        }
    }

    std::cout << currentPassword << std::endl;

}

int PasswordGenerator::getRandomNumber(int max){
    std::random_device device;
    std::mt19937 rng(device());
    std::uniform_int_distribution<std::mt19937::result_type> distribution(0, max);

    return distribution(rng);
}
