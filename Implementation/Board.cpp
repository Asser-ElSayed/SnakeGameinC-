#include "Board.h"
#include <cstdlib>
#include <ctime>

Board::Board(int width, int height) : width(width), height(height) {
    srand(time(0));
}

int Board::getWidth() const {
    return width;
}

int Board::getHeight() const {
    return height;
}

bool Board::isWithinBounds(Point position) const {
    return position.x >= 0 && position.x < width &&
           position.y >= 0 && position.y < height;
}

Point Board::getRandomEmptyCell(std::vector<Point> occupiedCells) const {
    Point randomPoint;
    bool isOccupied;

    do {
        isOccupied = false;
        randomPoint.x = rand() % width;
        randomPoint.y = rand() % height;

        for (const Point& p : occupiedCells) {
            if (randomPoint == p) {
                isOccupied = true;
                break;
            }
        }
    } while (isOccupied);

    return randomPoint;
}
