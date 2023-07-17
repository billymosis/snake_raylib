#include "snake.h"

Snake::Snake() {}

void Snake::SetBody(std::vector<Position> body) { this->body = body; }

void Snake::MoveBodyUp() {
  std::vector<Position> newBody;
  for (int i = 0; i < body.size(); i++) {
    if (i == 0) {
      newBody.push_back(Position(body[i].row, body[i].column - 1));
    } else {
      newBody.push_back(Position(body[i - 1].row, body[i - 1].column));
    }
  }
  SetBody(newBody);
}

void Snake::MoveBodyDown() {
  std::vector<Position> newBody;
  for (int i = 0; i < body.size(); i++) {
    if (i == 0) {
      newBody.push_back(Position(body[i].row, body[i].column + 1));
    } else {
      newBody.push_back(Position(body[i - 1].row, body[i - 1].column));
    }
  }
  SetBody(newBody);
}

void Snake::MoveBodyLeft() {
  std::vector<Position> newBody;
  for (int i = 0; i < body.size(); i++) {
    if (i == 0) {
      newBody.push_back(Position(body[i].row - 1, body[i].column));
    } else {
      newBody.push_back(Position(body[i - 1].row, body[i - 1].column));
    }
  }
  SetBody(newBody);
}

void Snake::MoveBodyRight() {
  std::vector<Position> newBody;
  for (int i = 0; i < body.size(); i++) {
    if (i == 0) {
      newBody.push_back(Position(body[i].row + 1, body[i].column));
    } else {
      newBody.push_back(Position(body[i - 1].row, body[i - 1].column));
    }
  }
  SetBody(newBody);
}

Position Snake::GetHeadPosition() { return body[0]; }

void Snake::PushBody(Position position) {
  body.push_back(position);
}
