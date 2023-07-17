#include "raylib.h"
#include <vector>

class Colors {
public:
  Colors();
  Color GetTileColor(int value);

private:
  std::vector<Color> myPallete;
};
