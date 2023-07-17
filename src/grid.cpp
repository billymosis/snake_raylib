#include "grid.h"
#include "raylib.h"
#include <iostream>
#include <string>



Grid::Grid(bool isDebug) {
  rowNumber = 20;
  colNumber = 20;
  cellSize = 20;
  color = Colors();
  this->isDebug = isDebug;
  Initialize();
}

void Grid::Initialize() {
  for (int i = 0; i < rowNumber; i++) {
    for (int j = 0; j < colNumber; j++) {
      grid[i][j] = 0;
    }
  }
}

void Grid::Draw() {
  for (int i = 0; i < rowNumber; i++) {
    for (int j = 0; j < colNumber; j++) {
      int value = grid[i][j];
      Color tileColor = color.GetTileColor(value);

      if (i == 0 || j == 0 || i == rowNumber - 1 || j == colNumber - 1) {
        DrawRectangle(i * cellSize + 1, j * cellSize + 1, 0, 0, tileColor);
      } else {
        DrawRectangle(i * cellSize + 1, j * cellSize + 1, cellSize - 1,
                      cellSize - 1, tileColor);
      }
      if (isDebug) {
        // Convert the coordinates to string format
        std::string coordinates =
            "(" + std::to_string(i) + "," + std::to_string(j) + ")";

        // Convert the string to a char array
        char *text = &coordinates[0];
        DrawText(text, i * cellSize + 1, j * cellSize + 1, 1, BLACK);
      }
    }
  }
}

void Grid::Snake2Grid(Snake snake) {
  std::vector<Position> body = snake.body;
  Initialize();
  for (int i = 0; i < body.size(); i++) {
    Position item = snake.body[i];
    if (i == 0) {
      grid[item.row][item.column] = 2;
    } else {
      grid[item.row][item.column] = 1;
    }
  }
}

void Grid::Food2Grid(Food food) {
  grid[food.FoodPosition.row][food.FoodPosition.column] = 3;
}
