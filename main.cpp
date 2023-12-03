#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "Navigator.h"
#include "keypad.h"
#include <map>
#include <algorithm>

using std::string;
using std::vector;
using std::cout;
using std::endl;

string filePath = R"(C:\Dev\Text_files\input.txt)";
vector<string> readFile();
string trim(const string& str);
bool validTriangle(const vector<int>&);
vector<string> splitLine(const string& line, const char& delimiter);
string decrypt(const string& encrypted, int cypher);


// Day 4
// Part 2
int main() {
    vector<string> rawInput = readFile();

    for (const auto& line: rawInput){
        string currentLine = line.substr(0, line.size()-7);
        int cipherValue = std::stoi(currentLine.substr(currentLine.size()-3));

        string decrypted = decrypt(currentLine, cipherValue);
    }
    return 0;
}

string decrypt(const string& encrypted, int cypher){
    string decrypted;
    for (const auto& letter: encrypted){
        if (letter == '-'){
            decrypted += " ";
        } else if (isalpha(letter)) {
            int rawValue = ((letter - 96) + cypher) % 26;
            rawValue += 96;
            decrypted += char(rawValue);
        }
    }
    if (decrypted == "northpole object storage ") {
        cout << decrypted << std::to_string(cypher);
    }
    return decrypted;
}


/*

// Day 4
// Part 1

int main() {
    vector<string> rawInput = readFile();

    int totalRoomValue = 0;
    for (const auto& line: rawInput){
        vector<string> currentLine = splitLine(line, '-');
        totalRoomValue += roomValue(currentLine);
    }

    cout << totalRoomValue;
    return 0;
}

int roomValue(vector<string> roomData){
    vector<string> valueAndChecksum = splitLine(roomData.at(roomData.size() - 1), '[');
    int roomValue = std::stoi(valueAndChecksum.at(0));
    string checksum = valueAndChecksum.at(1);
    checksum = checksum.substr(0, checksum.size()-1);
    roomData.pop_back();

    std::map<char, int> letterValues;
    for (const auto& line: roomData){
        for (const auto& letter: line){
            letterValues[letter]++;
        }
    }

    string testString;
    while (!letterValues.empty()){
        auto pair = std::max_element(letterValues.begin(), letterValues.end(),
                                  [](const std::pair<int, int>& p1, const std::pair<int, int>& p2) {
                                      return p1.second < p2.second; });
        char key = pair->first;
        testString += key;
        letterValues.erase(key);
    }

    testString = testString.substr(0, 5);
    if (testString == checksum){
        return roomValue;
    } else {
        return 0;
    }
}


// Day 3
// Part 2

int main() {
    vector<string> rawInput = readFile();

    int validTriangles = 0;
    int counter = 0;
    vector<int> lengths;
    for (const auto& line: rawInput){
        std::stringstream stream(line);
        string currentNumber;

        while (stream.good()) {
            std::getline(stream, currentNumber, ' ');
            if (!currentNumber.empty()) {
                lengths.push_back(std::stoi(trim(currentNumber)));
            }
        }

        counter++;
        if (counter % 3 == 0){
            vector<int> t1;
            vector<int> t2;
            vector<int> t3;

            t1.push_back(lengths.at(0));
            t1.push_back(lengths.at(3));
            t1.push_back(lengths.at(6));

            t2.push_back(lengths.at(1));
            t2.push_back(lengths.at(4));
            t2.push_back(lengths.at(7));

            t3.push_back(lengths.at(2));
            t3.push_back(lengths.at(5));
            t3.push_back(lengths.at(8));

            if (validTriangle(t1)){
                validTriangles += 1;
            }
            if (validTriangle(t2)){
                validTriangles += 1;
            }
            if (validTriangle(t3)){
                validTriangles += 1;
            }

            lengths.clear();
        }

    }

    cout << validTriangles;
    return 0;
}

bool validTriangle(const vector<int>& lengths){
    int l1 = lengths.at(0);
    int l2 = lengths.at(1);
    int l3 = lengths.at(2);

    if ((l1 + l2 <= l3) || (l2 + l3 <= l1) || (l3 + l1 <= l2)) {
        return false;
    }
    return true;
}

// Day 3
// Part 1
int main() {
    vector<string> rawInput = readFile();

    int validTriangles = 0;
    for (const auto& line: rawInput){
        vector<int> lengths;
        std::stringstream stream(line);
        string currentNumber;

        while (stream.good()) {
            std::getline(stream, currentNumber, ' ');
            if (!currentNumber.empty()) {
                lengths.push_back(std::stoi(trim(currentNumber)));
            }
        }
        if (validTriangle(lengths)){
            validTriangles += 1;
        }
    }

    cout << validTriangles;
    return 0;
}

bool validTriangle(const vector<int>& lengths){
    int l1 = lengths.at(0);
    int l2 = lengths.at(1);
    int l3 = lengths.at(2);

    if ((l1 + l2 <= l3) || (l2 + l3 <= l1) || (l3 + l1 <= l2)) {
        return false;
    }
    return true;
}

// Day 2
// Part 2
int main(){
    vector<string> rawInput = readFile();
    auto *keypad = new Keypad();

    for (const auto& line: rawInput){
        keypad->nextDigit(line);
    }

    cout << keypad->code;
    return 0;
}

// Day 1
// part 2

int main() {
    vector<string> rawInput = readFile();

    vector<string> instructions;
    for (const auto& inputLine: rawInput) {
        std::stringstream stream(inputLine);

        string currentLine;
        while (stream.good()) {
            std::getline(stream, currentLine, ',');
            if (!currentLine.empty()) {
                instructions.push_back(trim(currentLine));
            }
        }
    }

    auto *navigator = new Navigator();


    for (const auto& line: instructions){
        if (!navigator->destinationFound) {
            char direction = line[0];
            int directionChange;
            string distance = line.substr(1);

            if (direction == 'R') {
                directionChange = 1;
            } else {
                directionChange = -1;
            }

            navigator->changeDirection(directionChange);
            navigator->move(std::stoi(distance));
        } else {
            break;
        }
    }

    cout << std::abs(navigator->x) + std::abs(navigator->y);



    return 0;
}*/


string trim(const string& str){
    size_t first = str.find_first_not_of(' ');
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last-first+1));
}


vector<string> readFile(){
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


vector<string> splitLine(const string& line, const char& delimiter){
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