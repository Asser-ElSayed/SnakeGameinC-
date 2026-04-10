#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include "Point.h"
#include "Common.h"

class Board {
private:
    int width;
    int height;

public:
    Board(int width, int height);
    int getWidth() const;
    int getHeight() const;
    bool isWithinBounds(Point position) const;
    Point getRandomEmptyCell(std::vector<Point> occupiedCells) const;
};

#endif
