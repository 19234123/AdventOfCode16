#include "Screen.h"
#include <iostream>
#include <sstream>
#include <map>

using std::cout;
using std::endl;
using std::map;

Screen::Pixel::Pixel(int row, int column) : row(row), column(column) {}

Screen::Screen(int columns, int rows) {
    this->columns = columns;
    this->rows = rows;
    this->pixelsLit = 0;

    for (int row=0; row<rows; row++) {
        vector<Pixel> currentRow;
        for(int column=0; column<columns; column++) {
            auto currentPixel = Pixel(row, column);
            currentPixel.value = ".";
            currentPixel.row = row;
            currentPixel.column = column;
            currentRow.push_back(currentPixel);
        }
        grid.push_back(currentRow);
    }
}

void Screen::updateScreen(const string &instruction) {
    vector<string> instructionSplit = splitLine(instruction, ' ');

    // create rectangle
    if (instructionSplit.size() == 2) {
        vector<string> rectangleDimensions = splitLine(instructionSplit[1], 'x');
        int rectangleWidth = std::stoi(rectangleDimensions[0]);
        int rectangleHeight = std::stoi(rectangleDimensions[1]);

        for (int row = 0; row < rectangleHeight; row++) {
            for (int column = 0; column < rectangleWidth; column++) {
                this->grid[row][column].value = '#';
            }
        }
        // move pixels
    } else if (instructionSplit.size() == 5) {
        string axis = instructionSplit[1];
        int axisIndex = std::stoi(splitLine(instructionSplit[2], '=')[1]);
        int distance = std::stoi(instructionSplit[4]);

        if (axis == "row") {
            updateRow(axisIndex, distance);
        } else {
            updateColumn(axisIndex, distance);
        }
    }
}


void Screen::updateRow(int rowIndex, int distance) {
    auto& row = grid[rowIndex];

    string rowSnapshot;
    for (auto& pixel: row){
        rowSnapshot += pixel.value;
    }
    int rowLength = (int)rowSnapshot.size();

    for (auto& pixel: row){
        int newValueIndex = (rowLength + (pixel.column - distance)) % rowLength;
        pixel.value = rowSnapshot[newValueIndex];
    }
}

void Screen::updateColumn(int columnIndex, int distance) {
    string columnSnapshot;
    for (auto& row : grid) {
        for (auto &pixel: row) {
            if (pixel.column == columnIndex) {
                columnSnapshot += pixel.value;
            }
        }
    }

    for (auto& row : grid) {
        int columnLength = (int)columnSnapshot.size();
        for (auto& pixel: row) {
            if (pixel.column == columnIndex) {
                int newRowValueIndex = (columnLength + (pixel.row - distance)) % columnLength;
                row[columnIndex].value = columnSnapshot[newRowValueIndex];
            }
        }
    }
}

void Screen::display() {
    for (const auto& row: grid){
        for (const auto& pixel: row){
            cout << pixel.value;
        }
        cout <<  endl;
    }
    cout << endl;
}


vector<string> Screen::splitLine(const string& line, const char& delimiter) {
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

string Screen::trim(const string& str) {
    size_t first = str.find_first_not_of(' ');
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last-first+1));
}

int Screen::numberPixelsLit() {
    pixelsLit = 0;
    for (const auto& row: grid){
        for (const auto& pixel: row){
            if (pixel.value == "#"){
                pixelsLit++;
            }
        }
    }
    return pixelsLit;
}