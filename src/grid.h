#pragma once
#include "colors.h"
#include "food.h"
#include "snake.h"

class Grid {
public:
  Grid(bool isDebug = false);
  void Initialize();
  void Draw();
  int grid[20][20];
  void Snake2Grid(Snake snake);
  void Food2Grid(Food food);
  int rowNumber;
  int colNumber;

private:
  Colors color;
  int cellSize;
  bool isDebug;
};
