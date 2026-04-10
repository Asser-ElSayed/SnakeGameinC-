#include "Render.h"
#include <iostream>
#include <windows.h>

Render::Render(int boardWidth, int boardHeight) : boardWidth(boardWidth), boardHeight(boardHeight),
    snakeSymbol('O'), appleSymbol('A'), emptySymbol(' '), boundarySymbol('#') {}

void Render::clearScreen() {
    system("cls");
}

void Render::renderVisual(Snake& snake, Apple& apple, int score) {
    clearScreen();

    std::vector<Point> body = snake.getBody();
    Point applePos = apple.getPosition();

    for (int i = 0; i < boardHeight + 2; i++) {
        for (int j = 0; j < boardWidth + 2; j++) {
            if (i == 0 || i == boardHeight + 1) {
                std::cout << boundarySymbol;
            } else if (j == 0 || j == boardWidth + 1) {
                std::cout << boundarySymbol;
            } else {
                Point current(j - 1, i - 1);
                bool isSnake = false;

                for (const Point& p : body) {
                    if (current == p) {
                        isSnake = true;
                        break;
                    }
                }

                if (isSnake) {
                    std::cout << snakeSymbol;
                } else if (current == applePos) {
                    std::cout << appleSymbol;
                } else {
                    std::cout << emptySymbol;
                }
            }
        }
        std::cout << std::endl;
    }

    std::cout << "Score: " << score << std::endl;
}

void Render::displayGameOver(int finalScore) {
    clearScreen();
    std::cout << "Game Over!" << std::endl;
    std::cout << "Final Score: " << finalScore << std::endl;
    std::cout << "Press R to Restart or Q to Quit" << std::endl;
}
