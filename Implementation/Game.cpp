#include "Game.h"
#include <windows.h>
#include <conio.h>
Game::Game(int boardWidth, int boardHeight) :
    board(boardWidth, boardHeight),
    snake(Point(boardWidth / 2, boardHeight / 2), NORTH),
    apple(board.getRandomEmptyCell(snake.getBody())),
    render(boardWidth, boardHeight),
    score(0),
    isRunning(true) {}

void Game::initialize() {
    score = 0;
    isRunning = true;
    snake = Snake(Point(board.getWidth() / 2, board.getHeight() / 2), NORTH);
    apple = Apple(board.getRandomEmptyCell(snake.getBody()));
}

void Game::run() {
    while (isRunning) {
        processInput();
        update();
        render.renderVisual(snake, apple, score);
        Sleep(150);
    }
    gameOver();
}

void Game::processInput() {
    Direction requested = inputHandler.getInput();
    if (inputHandler.isValidDirection(snake.getCurrentDirection(), requested)) {
        snake.changeDirection(requested);
    }
}

void Game::update() {
    snake.move();
    checkCollisions();
    handleAppleEaten();
}

void Game::checkCollisions() {
    Point head = snake.getHead();

    if (!board.isWithinBounds(head) || snake.checkSelfCollision()) {
        isRunning = false;
    }
}

void Game::handleAppleEaten() {
    if (snake.getHead() == apple.getPosition()) {
        snake.grow();
        score++;
        apple.setPosition(board.getRandomEmptyCell(snake.getBody()));
    }
}

void Game::gameOver() {
    render.displayGameOver(score);
    char choice;
    do {
        choice = _getch();
    } while (choice != 'R' && choice != 'r' && choice != 'Q' && choice != 'q');

    if (choice == 'R' || choice == 'r') {
        initialize();
        run();
    }
}
