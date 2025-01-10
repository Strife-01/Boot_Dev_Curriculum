#include "coord.h"

struct Coordinate new_coord(int x, int y, int z) {
  struct Coordinate coord = {.x = x, .y = y, .z = z};
  return coord;
}

struct Coordinate scale_coordinate(struct Coordinate coord, int factor) {
  struct Coordinate new_coord = {
    .x = coord.x * factor,
    .y = coord.y * factor,
    .z = coord.z * factor
  };

  return new_coord;
}

