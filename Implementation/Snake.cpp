#include "Snake.h"

Snake::Snake(Point startPosition, Direction initialDirection) : currentDirection(initialDirection) {
    body.push_back(startPosition);
}

void Snake::move() {
    Point head = getHead();

    if (currentDirection == NORTH) head.y--;
    else if (currentDirection == SOUTH) head.y++;
    else if (currentDirection == EAST) head.x++;
    else if (currentDirection == WEST) head.x--;

    body.insert(body.begin(), head);
    body.pop_back();
}

void Snake::changeDirection(Direction newDirection) {
    currentDirection = newDirection;
}

void Snake::grow() {
    Point tail = body.back();
    body.push_back(tail);
}

bool Snake::checkSelfCollision() {
    Point head = getHead();
    for (int i = 1; i < body.size(); i++) {
        if (head == body[i]) {
            return true;
        }
    }
    return false;
}

Point Snake::getHead() {
    return body.front();
}

std::vector<Point> Snake::getBody() {
    return body;
}

Direction Snake::getCurrentDirection() {
    return currentDirection;
}
