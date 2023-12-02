#include "Keypad.h"

void Keypad::nextDigit(const std::string& line) {
    for (const auto& direction: line){
        if (direction == 'U'){
            if (keys[currentRow-1][currentCol] != "X") {
                currentRow -= 1;
                currentRow = std::max(currentRow, 0);
            }
        } else if (direction == 'R'){
            if (keys[currentRow][currentCol+1] != "X") {
                currentCol += 1;
                currentCol = std::min(currentCol, 4);
            }
        } else if (direction == 'D'){
            if (keys[currentRow+1][currentCol] != "X") {
                currentRow += 1;
                currentRow = std::min(currentRow, 4);
            }
        } else if (direction == 'L'){
            if (keys[currentRow][currentCol-1] != "X") {
                currentCol -= 1;
                currentCol = std::max(currentCol, 0);
            }
        }
    }





    code += keys[currentRow][currentCol];
}

Keypad::Keypad() {
    this->currentRow = 2;
    this->currentCol = 0;
    this->code = "";
}
