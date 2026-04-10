#ifndef POINT_H
#define POINT_H
#include "Common.h"

class Point {
public:
    int x;
    int y;

    Point(int x = 0, int y = 0);
    bool operator==(const Point& other) const;
};

#endif
