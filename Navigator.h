#ifndef ADVENTOFCODE16_NAVIGATOR_H
#define ADVENTOFCODE16_NAVIGATOR_H
#include <string>
#include <vector>


class Navigator {
public:
    int x;
    int y;
    int heading;
    bool destinationFound;
    std::vector<std::string> visitedLocations;

    Navigator();
    void changeDirection(int direction);
    void move(int distance);
    void step();



};


#endif //ADVENTOFCODE16_NAVIGATOR_H
