#ifndef GAME_H
#define GAME_H

#include "Snake.h"
#include "Apple.h"
#include "Board.h"
#include "Render.h"
#include "InputHandler.h"
#include "Common.h"

class Game {
private:
    Snake snake;
    Apple apple;
    Board board;
    Render render;
    InputHandler inputHandler;
    int score;
    bool isRunning;

public:
    Game(int boardWidth, int boardHeight);
    void run();
    void update();
    void processInput();
    void checkCollisions();
    void handleAppleEaten();
    void gameOver();
    void initialize();
};

#endif
