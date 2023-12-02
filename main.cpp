#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "Navigator.h"
#include "keypad.h"

using std::string;
using std::vector;
using std::cout;
using std::endl;

string filePath = R"(C:\Dev\Text_files\input.txt)";
vector<string> readFile();
string trim(const string& str);
bool validTriangle(const vector<int>&);

int main() {
    vector<string> rawInput = readFile();

    return 0;
}

// Day 3
// Part 2
/*
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