#ifndef ADVENTOFCODE16_ROBOT_H
#define ADVENTOFCODE16_ROBOT_H
#include <vector>
#include <string>
#include <map>

using std::vector;
using std::string;

class Robot {
public:
    string id;
    vector<int> chips {};
    static std::map<string, Robot*> robotList;

    explicit Robot(const string& id);
    bool targetChipComparison(int firstNumber, int secondNumber);
    void passNumbers(Robot *lowBot, Robot *highBot);

private:
    int getLowNumber();
    int getHighNumber();

};


#endif //ADVENTOFCODE16_ROBOT_H
