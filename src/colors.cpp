#include "colors.h"

Colors::Colors() { myPallete = {GRAY, BLACK, GREEN, RED}; };

Color Colors::GetTileColor(int value) { return myPallete[value]; }
