#include "coordinate.h"

// we need to pass the pointer to the coord struct
void coordinate_update_x(coordinate_t coord, int new_x) {
  coord.x = new_x;
}

coordinate_t coordinate_update_and_return_x(coordinate_t coord, int new_x) {
  coord.x = new_x;
  return coord;
}

