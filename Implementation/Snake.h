#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include "Point.h"
#include "Common.h"

class Snake {
private:
    std::vector<Point> body;
    Direction currentDirection;

public:
    Snake(Point startPosition, Direction initialDirection);
    void move();
    void changeDirection(Direction newDirection);
    void grow();
    bool checkSelfCollision();
    Point getHead();
    std::vector<Point> getBody();
    Direction getCurrentDirection();
};

#endif
