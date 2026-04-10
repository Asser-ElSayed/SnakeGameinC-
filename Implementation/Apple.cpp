#include "Apple.h"

Apple::Apple(Point position) : position(position) {}

Point Apple::getPosition() const {
    return position;
}

void Apple::setPosition(Point newPosition) {
    position = newPosition;
}
