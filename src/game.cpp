#include "game.h"
#include <algorithm>
#include <iostream>
#include <ostream>

std::vector<Position> defaultBody = {
    Position(2, 2),
    Position(2, 3),
    Position(2, 4),
    Position(2, 5),
};

Game::Game() {
  grid = Grid();
  grid.Initialize();
  snake = Snake();
  std::vector<Position> body = defaultBody;
  snake.SetBody(body);
  snakeHead = snake.GetHeadPosition();
  direction = IDLE;
  food = Food(grid.rowNumber, grid.colNumber);
  food.CreateRandomFood(snake);
  score = 0;
  isDebug = false;
}

void Game::Move() { HandleInput(direction); }

void Game::Reset() {
  grid.Initialize();
  std::vector<Position> body = defaultBody;
  snake.SetBody(body);
  snakeHead = snake.GetHeadPosition();
  gameOver = false;
  direction = IDLE;
  food.CreateRandomFood(snake);
  score = 0;
}

void Game::Draw() {
  grid.Snake2Grid(snake);
  grid.Food2Grid(food);
  grid.Draw();

  if (isDebug) {
    std::string coordinates = "(" + std::to_string(snakeHead.row) + "," +
                              std::to_string(snakeHead.column) + ")";
    std::string myFood = "(" + std::to_string(food.FoodPosition.row) + "," +
                         std::to_string(food.FoodPosition.column) + ")";
    DrawText(coordinates.c_str(), 400, 400, 12, BLACK);
    DrawText(myFood.c_str(), 400, 420, 12, BLACK);
  }
}

void Game::HandleInput(int direction) {
  if (gameOver)
    return;

  int keyPressed;
  if (direction > 0) {
    keyPressed = direction;
  } else {
    keyPressed = GetKeyPressed();
  }
  switch (keyPressed) {
  case KEY_LEFT:
    if (this->direction == RIGHT)
      break;
    snake.MoveBodyLeft();
    this->direction = LEFT;
    break;
  case KEY_RIGHT:
    if (this->direction == LEFT)
      break;
    snake.MoveBodyRight();
    this->direction = RIGHT;
    break;
  case KEY_DOWN:
    if (this->direction == UP)
      break;
    snake.MoveBodyDown();
    this->direction = DOWN;
    break;
  case KEY_UP:
    if (this->direction == DOWN)
      break;
    snake.MoveBodyUp();
    this->direction = UP;
    break;
  }
  if (snakeHead.column == food.FoodPosition.column &&
      snakeHead.row == food.FoodPosition.row) {
    food.CreateRandomFood(snake);
    snake.PushBody(food.FoodPosition);
    score += 100;
  }
  if (IsOutOfBound()) {
    gameOver = true;
  };
}

bool Game::IsOutOfBound() {
  snakeHead = snake.GetHeadPosition();
  if (snakeHead.row == 0 || snakeHead.column == 0 ||
      snakeHead.row == grid.rowNumber - 1 ||
      snakeHead.column == grid.colNumber - 1) {
    return true;
  }

  for (int i = 1; i < snake.body.size(); i++) {
    Position item = snake.body[i];
    if (item.row == snakeHead.row && item.column == snakeHead.column) {
      return true;
    }
  }

  return false;
}

Game::~Game() {}
