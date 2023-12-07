#include "Robot.h"
#include <iostream>
#include <algorithm>

std::map<string, Robot*> Robot::robotList;

Robot::Robot(const string &id) {
    this->id = id;
    robotList[id] = this;
}

void Robot::passNumbers(Robot *lowBot, Robot *highBot) {
    int lowNumber = getLowNumber();
    int highNumber = getHighNumber();

    lowBot->chips.push_back(lowNumber);
    chips.erase(std::min_element(chips.begin(), chips.end()));

    highBot->chips.push_back(highNumber);
    chips.erase(std::max_element(chips.begin(), chips.end()));
}

bool Robot::targetChipComparison(int firstNumber, int secondNumber) {
    int low = getLowNumber();
    int high = getHighNumber();

    return (low==firstNumber && high==secondNumber) || (high==firstNumber && low==secondNumber);
}

int Robot::getLowNumber() {
    if (chips.empty()){
        return -1;
    } else {
        return *std::min_element(chips.begin(), chips.end());
    }
}

int Robot::getHighNumber() {
    if (chips.empty()){
        return -1;
    } else {
        return *std::max_element(chips.begin(), chips.end());
    }
}