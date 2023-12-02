#ifndef ADVENTOFCODE16_KEYPAD_H
#define ADVENTOFCODE16_KEYPAD_H

#include <string>


class Keypad {
public:
    std::string keys[5][5] = {
        "X", "X", "1", "X", "X",
        "X", "2","3","4", "X",
        "5","6","7","8","9",
        "X", "A", "B", "C", "X",
        "X", "X", "D", "X", "X"
    };
    int currentRow;
    int currentCol;
    std::string code;

    Keypad();
    void nextDigit(const std::string& line);

};


#endif //ADVENTOFCODE16_KEYPAD_H
