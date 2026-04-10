#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include <map>

#include "Common.h"

class InputHandler {
private:
    std::map<char, Direction> keyMappings;

public:
    InputHandler();
    Direction getInput();
    bool isValidDirection(Direction current, Direction requested);
};

#endif
