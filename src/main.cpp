#include "game.h"
#include "raylib.h"
#include <string>

double lastUpdateTime = 0;

bool EventTriggered(double interval) {
  double currentTime = GetTime();
  if (currentTime - lastUpdateTime >= interval) {
    lastUpdateTime = currentTime;
    return true;
  }
  return false;
}

int main(void) {
  InitWindow(550, 400, "snake by billy");

  Game game = Game();

  while (!WindowShouldClose()) {
    if (game.gameOver) {
      game.Reset();
    }
    game.HandleInput();
    if (EventTriggered(0.2)) {
      game.Move();
    }
    BeginDrawing();

    char scoreText[10];
    sprintf(scoreText, "%d", game.score);
    int textSize = MeasureText(scoreText, 38);

    DrawText(scoreText, 400 + (170 - textSize) / 2, 65, 20, VIOLET);
    game.Draw();
    ClearBackground(RAYWHITE);
    EndDrawing();
  }

  CloseWindow();

  return 0;
}
