#ifndef APPLE_H
#define APPLE_H

#include "Point.h"

class Apple {
private:
    Point position;

public:
    Apple(Point position);
    Point getPosition() const;
    void setPosition(Point newPosition);
};

#endif
