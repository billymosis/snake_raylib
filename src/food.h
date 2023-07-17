#pragma once
#include "position.h"
#include "snake.h"

class Food {
public:
  Food();
  Food(int maxRow, int maxColumn);
  void CreateRandomFood(Snake snake);
  Position FoodPosition;

private:
  int maxColumn;
  int maxRow;
};
