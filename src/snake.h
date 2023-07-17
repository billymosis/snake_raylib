#pragma once
#include "position.h"
#include <vector>

class Snake {
public:
  Snake();
  std::vector<Position> body;
  Position GetHeadPosition();
  void SetBody(std::vector<Position> body);
  void PushBody(Position position);
  void MoveBodyUp();
  void MoveBodyLeft();
  void MoveBodyRight();
  void MoveBodyDown();
};
