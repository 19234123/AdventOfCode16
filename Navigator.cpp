#include "Navigator.h"

void Navigator::changeDirection(int direction) {
    heading += direction;
    // n e s w = 0 1 2 3
    if (heading == 4){
        heading = 0;
    } else if (heading == -1){
        heading = 3;
    }
}

void Navigator::move(int distance) {
    for (int i=0; i<distance; i++) {
        std::string currentXY;
        currentXY += std::to_string(x);
        currentXY += std::to_string(y);

        for (const auto& location: visitedLocations){
            if (currentXY == location){
                destinationFound = true;
                return;
            }
        }

        this->visitedLocations.push_back(currentXY);
        step();
    }
}

void Navigator::step() {
    switch (heading){
        case 0:
            y -= 1;
            break;
        case 1:
            x += 1;
            break;
        case 2:
            y += 1;
            break;
        case 3:
            x -= 1;
            break;
    }
}

Navigator::Navigator() {
    this->x = 0;
    this->y = 0;
    this->heading = 0;
    this->destinationFound = false;
}
