#include "food.h"
#include "raylib.h"
#include <iostream>
#include <random>

Food::Food(){};

Food::Food(int maxRow, int maxColumn) {
  this->maxRow = maxRow;
  this->maxColumn = maxColumn;
}

void Food::CreateRandomFood(Snake snake) {
  int randomRow = 1 + (rand() % (maxRow - 2));
  int randomColumn = 1 + (rand() % (maxColumn - 2));

  for (int i = 0; i < snake.body.size(); i++) {
    Position item = snake.body[i];

    if (item.column == randomColumn && item.row == randomRow) {
      CreateRandomFood(snake);
      return;
    }
  }

  this->FoodPosition = Position(randomRow, randomColumn);
}
