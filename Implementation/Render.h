#ifndef RENDER_H
#define RENDER_H

#include "Snake.h"
#include "Apple.h"
#include "Common.h"

class Render {
private:
    int boardWidth;
    int boardHeight;
    char snakeSymbol;
    char appleSymbol;
    char emptySymbol;
    char boundarySymbol;

public:
    Render(int boardWidth, int boardHeight);
    void renderVisual(Snake& snake, Apple& apple, int score);
    void clearScreen();
    void displayGameOver(int finalScore);
};

#endif
