#include "InputHandler.h"
#include <conio.h>

InputHandler::InputHandler() {
    keyMappings['W'] = NORTH;
    keyMappings['S'] = SOUTH;
    keyMappings['D'] = EAST;
    keyMappings['A'] = WEST;
    keyMappings['w'] = NORTH;
    keyMappings['s'] = SOUTH;
    keyMappings['d'] = EAST;
    keyMappings['a'] = WEST;
}

Direction InputHandler::getInput() {
    if (_kbhit()) {
        char key = _getch();
        if (keyMappings.find(key) != keyMappings.end()) {
            return keyMappings[key];
        }
    }
    return NONE;
}

bool InputHandler::isValidDirection(Direction current, Direction requested) {
    if (requested == NONE) return false;
    if (current == NORTH && requested == SOUTH) return false;
    if (current == SOUTH && requested == NORTH) return false;
    if (current == EAST && requested == WEST) return false;
    if (current == WEST && requested == EAST) return false;
    return true;
}
