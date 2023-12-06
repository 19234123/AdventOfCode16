#ifndef ADVENTOFCODE16_SCREEN_H
#define ADVENTOFCODE16_SCREEN_H

#include <vector>
#include <string>

using std::vector;
using std::string;

class Screen {
private:
    class Pixel {
    public:
        Pixel(int row, int column);
        string value;
        int row;
        int column;
    };

    int columns;
    int rows;
    int pixelsLit;
    vector<vector<Pixel>> grid;
    vector<Pixel> currentColumn;
    void updateColumn(int columnIndex, int distance);
    void updateRow(int rowIndex, int distance);
    static vector<string> splitLine(const string& line, const char& delimiter);
    static string trim(const string& str);

public:
    Screen(int columns, int rows);
    int numberPixelsLit();
    void display();
    void updateScreen(const string& instruction);
};


#endif //ADVENTOFCODE16_SCREEN_H