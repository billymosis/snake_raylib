#include "grid.h"
#include "snake.h"
#include "food.h"

class Game {
public:
  Game();
  ~Game();
  void Draw();
  void HandleInput(int direction = 0);
  void Move();
  bool gameOver = false;
  void Reset();
  int score;

private:
  Grid grid;
  Snake snake;
  Position snakeHead = Position({5, 5});
  enum Direction {
    IDLE = 0,
    LEFT = 263,
    RIGHT = 262,
    UP = 265,
    DOWN = 264,
  };
  Direction direction;
  bool IsOutOfBound();
  Food food;
  bool isDebug;
};
